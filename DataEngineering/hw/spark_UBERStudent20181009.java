import scala.Tuple2;
import org.apache.spark.sql.SparkSession;
import org.apache.spark.api.java.*;
import org.apache.spark.api.java.function.*;
import java.io.Serializable;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;
import java.util.regex.Pattern;
import java.util.Calendar;

public final class UBERStudent20181009 {
    public static void main(String[] args) throws Exception {

        if (args.length < 2) {
            System.err.println("Usage: UBERStudent20181009 <in-file> <out-file>");
            System.exit(1);
        }

        SparkSession spark = SparkSession
                .builder()
                .appName("UBERStudent20181009")
                .getOrCreate();

        // 텍스트 파일 읽어오기
        JavaRDD<String> lines = spark.read().textFile(args[0]).javaRDD();

        // 텍스트 파일을 자르기
        // FlatMapFunction : A function that returns zero or more output records from
        // each input record.
        FlatMapFunction<String, String> fmf = new FlatMapFunction<String, String>() {
            public Iterator<String> call(String s) {
                String[] week = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
                String[] info = s.split(","); // 텍스트 파일을 ','로 자르기
                // 날짜 부분
                String[] date = info[1].split("/"); // 텍스트 파일을 '/' 로 자르기

                Calendar calendar = Calendar.getInstance();

                calendar.set(Calendar.MONTH, Integer.parseInt(date[0]) - 1);
                calendar.set(Calendar.DAY_OF_MONTH, Integer.parseInt(date[1]));
                calendar.set(Calendar.YEAR, Integer.parseInt(date[2]));

                return Arrays.asList(info[0] + ","
                        + week[calendar.get(Calendar.DAY_OF_WEEK) - 1]
                        + "==" + info[3] + "," + info[2]).iterator();
            }
        };
        // method flatMap : 함수에서 단일 값을 반환하는 대신 iterator를 반환
        JavaRDD<String> words = lines.flatMap(fmf);

        // PairFunction : A function that returns key-value pairs (Tuple2<K,V>), and can
        // be used to construct PairRDDs.
        // generic type: <input, output key, output value>
        PairFunction<String, String, String> pf = new PairFunction<String, String, String>() {
            public Tuple2<String, String> call(String s) {
                String[] str = s.split("=="); // "=="로 자르기
                return new Tuple2(str[0], str[1]);
            }
        };
        // JavaPairRDD : key-value 쌍을 가지는 특별한 RDD
        JavaPairRDD<String, String> values = words.mapToPair(pf);

        // 같은 key를 가지는 요소를 aggregation 하기
        // Interface Function2 : A two-argument function that takes arguments of type T1
        // and T2 and returns an R
        // generic type : <T1, T2, output value>
        Function2<String, String, String> f2 = new Function2<String, String, String>() {
            public String call(String x, String y) {
                String[] str1 = x.split(",");
                String[] str2 = y.split(",");

                int[] sum = { 0, 0 };

                sum[0] = Integer.parseInt(str1[0]) + Integer.parseInt(str2[0]);
                sum[1] = Integer.parseInt(str1[1]) + Integer.parseInt(str2[1]);

                return Integer.toString(sum[0]) + "," + Integer.toString(sum[1]);
            }
        };
        // method reduceByKey: 동일 key에 대해 같은 함수 적용 (f2에서 구현한 것을 적용)
        JavaPairRDD<String, String> counts = values.reduceByKey(f2);

        // 결과를 텍스트 파일로 저장하기
        counts.saveAsTextFile(args[1]);

        spark.stop(); // Spark 프로그램 종료
    }
}
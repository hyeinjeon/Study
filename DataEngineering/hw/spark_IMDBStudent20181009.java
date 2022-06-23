import scala.Tuple2;
import org.apache.spark.sql.SparkSession;
import org.apache.spark.api.java.*;
import org.apache.spark.api.java.function.*;
import java.io.Serializable;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;
import java.util.regex.Pattern;

public final class IMDBStudent20181009 {
    public static void main(String[] args) throws Exception {

        if (args.length < 2) {
            System.err.println("Usage: IMDBStudent20181009 <in-file> <out-file>");
            System.exit(1);
        }

        SparkSession spark = SparkSession
                .builder()
                .appName("IMDBStudent20181009")
                .getOrCreate(); // DataSet, DataFrame API를 사용하여 Spark를 프로그래밍하는 시작점

        // 텍스트 파일 읽어오기
        JavaRDD<String> lines = spark.read().textFile(args[0]).javaRDD();

        // 텍스트 파일 자르기
        // FlatMapFunction : A function that returns zero or more output records from
        // each input record.
        FlatMapFunction<String, String> fmf = new FlatMapFunction<String, String>() {
            public Iterator<String> call(String s) {
                // 텍스트 파일을 '::'과 '|' 로 자르기
                return Arrays.asList(s.split("::")[2].split("\\|")).iterator();
            }
        };
        // method flatMap : 함수에서 단일 값을 반환하는 대신 iterator를 반환
        JavaRDD<String> words = lines.flatMap(fmf);

        // 각 요소가 key가 되고 value가 1이 되는 Tuple들로 바꾸기
        // PairFunction : A function that returns key-value pairs (Tuple2<K,V>), and can
        // be used to construct PairRDDs.
        // generic type: <input, output key, output value>
        PairFunction<String, String, Integer> pf = new PairFunction<String, String, Integer>() {
            public Tuple2<String, Integer> call(String s) { // generic type: <output key, output value>
                return new Tuple2(s, 1); // key가 s, value가 1이 되는 tuple 반환
            }
        };
        // JavaPairRDD : key-value 쌍을 가지는 특별한 RDD
        JavaPairRDD<String, Integer> ones = words.mapToPair(pf);

        // 같은 key를 가지는 요소를 aggregation 하기
        // Interface Function2 : A two-argument function that takes arguments of type T1
        // and T2 and returns an R
        // generic type : <T1, T2, output value>
        Function2<Integer, Integer, Integer> f2 = new Function2<Integer, Integer, Integer>() {
            public Integer call(Integer x, Integer y) {
                return x + y;
            }
        };
        // method reduceByKey: 동일 key에 대해 같은 함수 적용 (f2에서 구현한 것을 적용)
        JavaPairRDD<String, Integer> counts = ones.reduceByKey(f2); // 동일 key에 대해 같은 함수 적용

        // 결과를 텍스트 파일로 저장하기
        counts.saveAsTextFile(args[1]);

        spark.stop(); // Spark 프로그램 종료
    }
}
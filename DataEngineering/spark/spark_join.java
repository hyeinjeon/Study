import java.io.Serializable;
import java.util.Iterator;
import java.util.List;
import java.util.regex.*;

public final class JavaJoin {
    public static class Product implements Serializable {
        public int id;
        public int price;
        public String code;

        public Product(int id, int price, String code) {
            this.id = id;
            this.price = price;
            this.code = code;
        }

        public String toString() {
            return "id : " + id + ", price : " + price + ", code : " + code;
        }
    }

    public static void main(String[] args) throws Exception {
        if (args.length < 1) {
            System.err.println("Usage: JavaJoin");
            System.exit(1);
        }

        SparkSession spark = SparkSession
                .builder()
                .appName("JavaJoin")
                .getOrCreate();

        // 파일을 읽어서 한줄을 읽어온다.
        JavaRDD<String> products = spark.read().textFile(args[0]).javaRDD();

        PairFunction<String, String, Product> pfA = new PairFunction<String, String, Product>() {
            public Tuple2<String, Product> call(String s) {
                // String 을 delimiter(구분자)로 자르기
                Sting[] pValues = s.split("\\|");

                // join key를 key로 하고, Product 객체를 value로 하는 Tuple2 반환
                return new Tuple2(pValues[2],
                        new Product(Integer.parseInt(pValues[0]), Integer.parseInt(pValues[1]), pValues[2]));
            }
        };
        JavaRDD<String, Product> pTuples = products.mapToPair(pfA);

        JavaRDD<String> codes = spark.read().textFile(args[1]).javaRDD();
        PairFunction<String, String, Code> pfB = new PairFunction<String, String, Code>() {
            public Tuple2<String, Code> call(String s) {
                // String 을 delimiter(구분자)로 자르기
                String[] cValues = s.split("\\|");

                // join key를 key로 하고, Code 객체를 value로 하는 Tuple2 반환
                return new Tuple2(cValues[0], new Code(cValues[0], cValues[1]));
            }
        };
        JavaPairRDD<String, Code> cTuples = codes.mapToPair(pfB);

        // 지정한 key에 대해 Join 연산 수행
        // key에 맞는 record가 없을 수도 있는 객체는 Optional class로 감싸주기
        JavaPairRDD<String, Tuple2<Product, Code>> joined = pTuples.join(cTuples); // inner join
        JavaPairRDD<String, Tuple2<Product, Optional<Code>>> leftOuterJoined = pTuples.leftOuterJoin(cTuples);
        JavaPairRDD<String, Tuple2<Optional<Product>, Code>> rightOuterJoined = pTuples.rightOuterJoin(cTuples);
        JavaPairRdd<String, Tuple2<Optional<Product>, Optional<Code>>> fullOuterJoined = pTuples.fullOuterJoin(cTuples);

        // 결과 저장
        joined.saveAsTextFile(args[args.length - 1] + "_join");
        leftOuterJoined.saveAsTextFile(args[args.length - 1] + "_leftOuterJoin");
        rightOuterJoined.saveAsTextFile(args[args.length - 1] + "_rightOuterJoin");
        fullOuterJoined.saveAsTextFile(args[args.length - 1] + "_fullOuterJoin");

        spark.stop();
    }

}
import java.io.IOException;
import java.util.*;
import java.io.*;
import org.apache.hadoop.conf.*;
import org.apache.hadoop.fs.FileSystem;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.*;
import org.apache.hadoop.mapreduce.*;
import org.apache.hadoop.mapreduce.lib.input.*;
import org.apache.hadoop.mapreduce.lib.output.*;
import org.apache.hadoop.util.GenericOptionsParser;

public class ReduceSideJoin {

    public static class ReduceSideJoinMapper extends Mapper<Object, Text, Text, Text> {

        // System.out.println("hellllo");
        boolean fileA = true;

        private String filename;
        // private Text word = new Text();
        // private Text one_value = new Text();

        public void map(Object key, Text value, Context context) throws IOException, InterruptedException {

            System.out.println("hellllo");
            // long byte_offset = ((LongWritable)key).get();
            StringTokenizer itr = new StringTokenizer(value.toString(), "|");

            Text outputKey = new Text();
            Text outputValue = new Text();

            String joinKey = "";
            String o_value = "";

            if (fileA) {

                String id = itr.nextToken();
                String price = itr.nextToken();
                String code = itr.nextToken();

                joinKey = code;
                o_value = "A" + " " + id + " " + price;
            } else { // B
                String code = itr.nextToken();
                String description = itr.nextToken();

                joinKey = code;
                o_value = "B" + " " + description;
            }

            outputKey.set(joinKey);
            outputValue.set(o_value);
            System.out.println("[test]: " + outputKey.toString() + outputValue.toString());
            context.write(outputKey, outputValue);
        }

        protected void setup(Context contex) throws IOException, InterruptedException {
            filename = ((FileSplit) contex.getInputSplit()).getPath().getName();

            if (filename.indexOf("relation_a") != -1)
                fileA = true;
            else
                fileA = false;
        }
    }

    public static class ReduceSideJoinReducer extends Reducer<Text, Text, Text, Text> {
        public void reduce(Text key, Iterable<Text> values, Context context) throws IOException, InterruptedException {
            Text reduce_key = new Text();
            Text reduce_result = new Text();
            String description = "";

            ArrayList<String> buffer = new ArrayList<String>();

            for (Text val : values) {

                StringTokenizer itr = new StringTokenizer(val.toString());

                String file_type = itr.nextToken().trim();

                if (file_type.equals("B")) {
                    description = itr.nextToken().trim();
                } else { // A
                    if (description.length() == 0) { // A..not descript
                        buffer.add(val.toString());
                    } else { // A..has descript
                        reduce_key.set(itr.nextToken());
                        reduce_result.set(itr.nextToken() + " " + description);
                        context.write(reduce_key, reduce_result);
                    }
                }

            }

            for (int i = 0; i < buffer.size(); i++) {
                StringTokenizer itr = new StringTokenizer(buffer.get(i));

                itr.nextToken();
                reduce_key.set(itr.nextToken());
                reduce_result.set(itr.nextToken() + " " + description);
                context.write(reduce_key, reduce_result);
            }
        }

    }

    public static void main(String[] args) throws Exception {
        Configuration conf = new Configuration();
        String[] otherArgs = new GenericOptionsParser(conf, args).getRemainingArgs();

        if (otherArgs.length != 2) {
            System.err.println("Usage: ReduceSideJoin <in> <out>");
            System.exit(2);
        }

        Job job = new Job(conf, "ReduceSideJoin");
        job.setJarByClass(ReduceSideJoin.class);
        job.setMapperClass(ReduceSideJoinMapper.class);
        job.setReducerClass(ReduceSideJoinReducer.class);

        job.setOutputKeyClass(Text.class);
        job.setOutputValueClass(Text.class);

        FileInputFormat.addInputPath(job, new Path(otherArgs[0]));
        FileOutputFormat.setOutputPath(job, new Path(otherArgs[1]));
        FileSystem.get(job.getConfiguration()).delete(new Path(otherArgs[1]), true);
        System.exit(job.waitForCompletion(true) ? 0 : 1);
    }
}

/**
 * Created by anjueappen on 18/03/16.
 */
import org.finra.datagenerator.consumer.DataConsumer;
import org.finra.datagenerator.distributor.multithreaded.DefaultDistributor;
import org.finra.datagenerator.engine.scxml.SCXMLEngine;


import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
public class CSVDataGen {

    private CSVDataGen() {
        // Do nothing
    }

    /**
     * Main method, handles all the setup tasks for DataGenerator a user would normally do themselves
     *
     * @param args command line arguments
     */
    public static void main(String[] args) {
        String modelFile = "";
        String outputFile = "";
        int numberOfRows = 0;
        try {
            modelFile = args[0];
	System.out.println(modelFile);
            outputFile = args[1];
            numberOfRows = Integer.valueOf(args[2]);
		System.out.println("num rows is " + numberOfRows);
        } catch (IndexOutOfBoundsException e) {
            System.out.println("ERROR! Invalid command line arguments, expecting: <scxml model file> "
                    + "<desired csv output file> <desired number of output rows>");
            return;
        }catch(NumberFormatException e){
            System.out.println("ERROR! Invalid command line arguments, expecting: <scxml model file> "
                    + "<desired csv output file> <desired number of output rows>");
            return;
        }

        FileInputStream model = null;
        try {
            model = new FileInputStream(modelFile);
        } catch (FileNotFoundException e) {
            System.out.println("ERROR! Model file not found");
            return;
        }

        SCXMLEngine engine = new SCXMLEngine();
        engine.setModelByInputFileStream(model);
        engine.setBootstrapMin(100);

        DataConsumer consumer = new DataConsumer();
        consumer.addDataTransformer(new MachineTransformer());
        CSVFileWriter writer;
        try {
            writer = new CSVFileWriter(outputFile);
        } catch (IOException e) {
            System.out.println("ERROR! Can not write to output csv file");
            return;
        }
        consumer.addDataWriter(writer);

        DefaultDistributor dist = new DefaultDistributor();
        dist.setThreadCount(100000);
        dist.setMaxNumberOfLines(numberOfRows);
        dist.setDataConsumer(consumer);

        engine.process(dist);
        writer.closeCSVFile();

        System.out.println("COMPLETE!");
    }
}

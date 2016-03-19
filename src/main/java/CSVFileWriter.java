/**
 * Created by anjueappen on 18/03/16.
 */

import com.opencsv.CSVWriter;
import org.finra.datagenerator.consumer.DataPipe;
import org.finra.datagenerator.writer.DataWriter;

import java.io.FileWriter;
import java.io.IOException;
import java.util.Map;

public class CSVFileWriter implements DataWriter{
    private final CSVWriter csvFile;

    /**
     * Constructor
     *
     * @param csvFile output file name
     * @throws IOException if the output file can not be opened for writing
     */
    public CSVFileWriter(final String csvFile) throws IOException {
        this.csvFile = new CSVWriter(new FileWriter(csvFile), ',');
    }

    /**
     * Prints one line to the csv file
     *
     * @param cr data pipe with search results
     */
    public void writeOutput(DataPipe cr) {
        String[] nextLine = new String[cr.getDataMap().entrySet().size()];

        int count = 0;
        for (Map.Entry<String, String> entry : cr.getDataMap().entrySet()) {
            nextLine[count] = entry.getValue();
            count++;
        }

        csvFile.writeNext(nextLine);
    }

    /**
     * Closes the CSV file, should be called once all writing is done
     */
    public void closeCSVFile() {
        try {
            csvFile.close();
        } catch (IOException e) {
            System.out.println("ERROR! Failed to close csv file");
        }
    }

}

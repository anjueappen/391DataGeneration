import org.apache.commons.lang.RandomStringUtils;
import org.apache.commons.lang.StringUtils;
import org.finra.datagenerator.consumer.DataPipe;
import org.finra.datagenerator.consumer.DataTransformer;

import java.util.Map;
import java.util.Random;
import java.util.logging.Logger;

/**
 * Created by anjueappen on 18/03/16.
 */
public class MachineTransformer implements DataTransformer {

    private static final Logger log = Logger.getLogger(MachineTransformer.class.toString());
    private final Random rand = new Random(System.currentTimeMillis());
    private final RandomStringUtils randomStringUtils = new RandomStringUtils();
    /**
     * The transform method for this DataTransformer
     * @param cr a reference to DataPipe from which to read the current map
     */
    public void transform(DataPipe cr) {

        for (Map.Entry<String, String> entry : cr.getDataMap().entrySet()) {
            String value = entry.getValue();

            if (value.equals("#{random_string}")) {
                entry.setValue(randomStringUtils.randomAlphabetic(10).toUpperCase());
            }else if (value.equals("#{random_integer}")){
                entry.setValue(Integer.toString(rand.nextInt()));
            }else if (value.equals("#{random_decimal}")){
                entry.setValue(Double.toString(rand.nextDouble()));
            }
        }
    }

}

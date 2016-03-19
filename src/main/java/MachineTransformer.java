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
    /**
     * The transform method for this DataTransformer
     * @param cr a reference to DataPipe from which to read the current map
     */
    public void transform(DataPipe cr) {
        for (Map.Entry<String, String> entry : cr.getDataMap().entrySet()) {
            String value = entry.getValue();

            if (value.equals("#{c}")) {
                // Generate a random number
                int ran = rand.nextInt();
                entry.setValue(String.valueOf(ran));
            }else if (value.equals("#{b}")){
                entry.setValue("replaced by Anju");
            }
        }
    }

}

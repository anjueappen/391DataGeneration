/**
 * Created by anjueappen on 18/03/16.
 */

import com.opencsv.CSVWriter;
import org.finra.datagenerator.consumer.DataPipe;
import org.finra.datagenerator.writer.DataWriter;

import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class CSVFileWriter implements DataWriter{

    private  HashMap<String, Integer> columnOrder;
    private final CSVWriter csvFile;

    /**
     * Constructor
     *
     * @param csvFile output file name
     * @throws IOException if the output file can not be opened for writing
     */
    public CSVFileWriter(final String csvFile) throws IOException {
        this.csvFile = new CSVWriter(new FileWriter(csvFile), ',');
        String[] columns = {"cdrRecordType", "globalCallID_callManagerId", "globalCallID_callId",
                "origLegCallIdentifier", "dateTimeOrigination", "origNodeId", "origSpan", "origIpAddr", "callingPartyNumber", "callingPartyUnicodeLoginUserID", "origCause_location", "origCause_value", "origPrecedenceLevel",
                "origMediaTransportAddress_IP", "origMediaTransportAddress_Port", "origMediaCap_payloadCapability", "origMediaCap_maxFramesPerPacket", "origVideoCap_Codec", "origVideoCap_Bandwidth", "origVideoCap_Resolution",
                "origVideoTransportAddress_IP", "origVideoTransportAddress_Port", "origRSVPAudioStat", "origRSVPVideoStat", "destLegCallIdentifier", "destNodeId", "destSpan", "destIpAddr", "originalCalledPartyNumber", "finalCalledPartyNumber", "finalCalledPartyUnicodeLoginUserID", "destCause_location", "destCause_value", "destPrecedenceLevel", "destMediaTransportAddress_IP", "destMediaTransportAddress_Port", "destMediaCap_payloadCapability", "destMediaCap_maxFramesPerPacket", "destVideoCap_Codec", "destVideoCap_Bandwidth", "destVideoCap_Resolution", "destVideoTransportAddress_IP", "destVideoTransportAddress_Port", "destRSVPAudioStat", "destRSVPVideoStat", "dateTimeConnect", "dateTimeDisconnect", "lastRedirectDn", "pkid", "originalCalledPartyNumberPartition", "NumberPartition", "finalCalledPartyNumberPartition", "lastRedirectDnPartition", "duration", "origDeviceName", "destDeviceName", "origCallTerminationOnBehalfOf", "destCallTerminationOnBehalfOf", "origCalledPartyRedirectOnBehalfOf", "lastRedirectRedirectOnBehalfOf", "origCalledPartyRedirectReason", "lastRedirectRedirectReason", "destConversationID", "globalCallId_ClusterId", "joinOnBehalfOf", "comment", "authCodeDescription", "authorizationLevel", "clientMatterCode", "origDTMFMethod", "destDTMFMethod", "callSecuredStatus", "origConversationID", "origMediaCap_Bandwidth", "destMediaCap_Bandwidth", "authorizationCodeValue", "outpulsedCallingPartyNumber", "outpulsedCalledPartyNumber", "origIpv4v6Addr", "destIpv4v6Addr", "origVideoCap_Codec_Channel2", "origVideoCap_Bandwidth_Channel2", "origVideoCap_Resolution_Channel2", "origVideoTransportAddress_IP_Channel2", "origVideoTransportAddress_Port_Channel2", "origVideoChannel_Role_Channel2", "destVideoCap_Codec_Channel2", "destVideoCap_Bandwidth_Channel2", "destVideoCap_Resolution_Channel2", "destVideoTransportAddress_IP_Channel2", "destVideoTransportAddress_Port_Channel2",
                "destVideoChannel_Role_Channel2", "IncomingProtocolID", "IncomingProtocolCallRef", "OutgoingProtocolID",
                "OutgoingProtocolCallRef", "currentRoutingReason", "origRoutingReason", "lastRedirectingRoutingReason", "huntPilotDN", "huntPilotPartition"};
        System.out.println("Making new hashmap");
        columnOrder = new HashMap<String, Integer>(101);
        int i = 0;
        for(String col: columns){
            columnOrder.put(col, i);
            i++;
        }
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
            nextLine[columnOrder.get(entry.getKey())] = entry.getValue();
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

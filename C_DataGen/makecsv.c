//
// Created by anjueappen on 24/03/16.
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>

const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
const long INT = 1234567;
const double DECIMAL = 1234.567;
const char * STRING = "ABCDEFGHIJKL";
// Assumes 0 <= max <= RAND_MAX
// Returns in the half-open interval [0, max]
long random_at_most(long max) {
    unsigned long
    // max <= RAND_MAX < ULONG_MAX, so this is okay.
            num_bins = (unsigned long) max + 1,
            num_rand = (unsigned long) RAND_MAX + 1,
            bin_size = num_rand / num_bins,
            defect   = num_rand % num_bins;

    long x;
    do {
        //srand(time(NULL));
        x = rand();
    }
        // This is carefully written not to overflow
    while (num_rand - defect <= (unsigned long)x);

    // Truncated division is intentional
    return x/bin_size;
}

long timestamp(){
    //srand(time(NULL));
    return rand() % 90000000 + 10000000;
}

long phone_number(){
    //srand(time(NULL));
    return rand()%9000000 + 1000000;
}
char *rand_string(char *str, size_t size)
{
    if (size) {
        --size;
        for (size_t n = 0; n < size; n++) {
            //srand(time(NULL));
            int key = rand() % (int) (sizeof charset - 1);
            str[n] = charset[key];
        }
        str[size] = '\0';
    }
    return str;
}

int main(int argc, char **argv) {
    if( argc != 3) {
        printf("Mandatory arguments: <number of rows> <filepath>\n");
        return 1;
    }

    char buf[1048576];
    memset(buf, '\0', sizeof(buf));
    FILE * fp;
    fp = fopen(argv[2], "w");

    setvbuf(fp, buf, _IOFBF, 1048576);
    unsigned int row;
    srand(time(NULL));
	struct timeval  tv1, tv2;
	gettimeofday(&tv1, NULL);

	unsigned int guaranteedPN[3] = {4411299,3231283,9901234};
    float epsilon = 0.2;
    for(row = 0; row < atoi(argv[1]); row++) {
            float r = ((double) rand() / (RAND_MAX));
            int area_code = random_at_most(99);
            /* Default values are "row x col" */
/*cdrRecordType*/                               fprintf(fp,"\"%ld.0\",", random_at_most(10));
/*globalCallID_callManagerId*/                  fprintf(fp,"\"%ld\",", INT);
/*globalCallID_callId*/                         fprintf(fp,"\"%ld\",", INT);
/*origLegCallIdentifier*/                       fprintf(fp,"\"%ld\",", INT);
/*dateTimeOrigination*/                         fprintf(fp,"\"%ld\",", INT);
/*origNodeId*/                                  fprintf(fp,"\"%ld\",", INT);
/*origSpan*/                                    fprintf(fp,"\"%ld\",", INT);
/*origIpAddr*/                                  fprintf(fp,"\"%ld\",", INT);
                                                if (r < epsilon)
/*callingPartyNumber*/                              fprintf(fp,"\"780%u\",", guaranteedPN[row%3]);
                                                else
                                                    fprintf(fp,"\"7%d%ld\",", area_code, phone_number());
/*callingPartyUnicodeLoginUserID*/              fprintf(fp,"\"%s\",", STRING);
/*origCause_location*/                          fprintf(fp,"\"%lf\",", DECIMAL);
/*origCause_value*/                             fprintf(fp,"\"%lf\",", DECIMAL);
/*origPrecedenceLevel*/                         fprintf(fp,"\"%lf\",", DECIMAL);
/*origMediaTransportAddress_IP*/                fprintf(fp,"\"%ld\",", INT);
/*origMediaTransportAddress_Port*/              fprintf(fp,"\"%ld\",", INT);
/*origMediaCap_payloadCapability*/              fprintf(fp,"\"%ld\",", INT);
/*origMediaCap_maxFramesPerPacket*/             fprintf(fp,"\"%d\",", 5);
/*origVideoCap_Codec*/                          fprintf(fp,"\"%lf\",", DECIMAL);
/*origVideoCap_Bandwidth*/                      fprintf(fp,"\"%ld\",", INT);
/*origVideoCap_Resolution*/                     fprintf(fp,"\"%lf\",", DECIMAL);
/*origVideoTransportAddress_IP*/                fprintf(fp,"\"%ld\",", INT);
/*origVideoTransportAddress_Port*/              fprintf(fp,"\"%ld\",", INT);
/*origRSVPAudioStat*/                           fprintf(fp,"\"%lf\",", DECIMAL);
/*origRSVPVideoStat*/                           fprintf(fp,"\"%lf\",", DECIMAL);
/*destLegCallIdentifier*/                       fprintf(fp,"\"%ld\",", INT);
/*destNodeId*/                                  fprintf(fp,"\"%ld\",", INT);
/*destSpan*/                                    fprintf(fp,"\"%ld\",", INT);
/*destIpAddr*/                                  fprintf(fp,"\"%ld\",", INT);
                                                if (r < epsilon)
/*callingPartyNumber*/                              fprintf(fp,"\"780%u\",", guaranteedPN[(row+1)%3]);
                                                else
/*originalCalledPartyNumber*/                       fprintf(fp,"\"7%d%ld\",", area_code, phone_number());
/*finalCalledPartyNumber*/                      fprintf(fp,"\"%d%ld\",", area_code, phone_number()); //must be read in as string for sstables
/*finalCalledPartyUnicodeLoginUserID*/          fprintf(fp,"\"%s\",", STRING); //must be read in as string for sstables
/*destCause_location*/                          fprintf(fp,"\"%lf\",", DECIMAL);
/*destCause_value*/                             fprintf(fp,"\"%lf\",", DECIMAL);
/*destPrecedenceLevel*/                         fprintf(fp,"\"%lf\",", DECIMAL);
/*destMediaTransportAddress_IP*/                fprintf(fp,"\"%ld\",", INT);
/*destMediaTransportAddress_Port*/              fprintf(fp,"\"%ld\",", INT);
/*destMediaCap_payloadCapability*/              fprintf(fp,"\"%ld\",", INT);
/*destMediaCap_maxFramesPerPacket*/             fprintf(fp,"\"%ld\",", INT);
/*destVideoCap_Codec*/                          fprintf(fp,"\"%lf\",", DECIMAL);
/*destVideoCap_Bandwidth*/                      fprintf(fp,"\"%ld\",", INT);
/*destVideoCap_Resolution*/                     fprintf(fp,"\"%lf\",", DECIMAL);
/*destVideoTransportAddress_IP*/                fprintf(fp,"\"%ld\",", INT);
/*destVideoTransportAddress_Port*/              fprintf(fp,"\"%ld\",", INT);
/*destRSVPAudioStat*/                           fprintf(fp,"\"%ld\",", INT);
/*destRSVPVideoStat*/                           fprintf(fp,"\"%lf\",", DECIMAL);
/*dateTimeConnect*/                             fprintf(fp,"\"%ld\",", timestamp());
/*dateTimeDisConnect*/                          fprintf(fp,"\"%ld\",", timestamp());
/*lastRedirectDn*/                              fprintf(fp,"\"%s\",", STRING);
/*pkid*/                                        fprintf(fp,"\"%s\",", STRING);
/*originalCalledPartyNumberPartition*/          fprintf(fp,"\"%s\",", STRING);
/*NumberPartition*/                             fprintf(fp,"\"%s\",", STRING);
/*finalCalledPartyNumberPartition*/             fprintf(fp,"\"%s\",", STRING);
/*lastRedirectDnPartition*/                     fprintf(fp,"\"%s\",", STRING);
/*duration*/                                    fprintf(fp,"\"%ld\",", random_at_most(1000));
/*origDeviceName*/                              fprintf(fp,"\"%s\",", STRING);
/*destDeviceName*/                              fprintf(fp,"\"%s\",", STRING);
/*origCallTerminationOnBehalfOf*/               fprintf(fp,"\"%ld\",", INT);
/*destCallTerminationOnBehalfOf*/               fprintf(fp,"\"%ld\",", INT);
/*origCalledPartyRedirectOnBehalfOf*/           fprintf(fp,"\"%ld\",", INT);
/*lastRedirectRedirectOnBehalfOf*/              fprintf(fp,"\"%ld\",", INT);
/*origCalledPartyRedirectReason*/               fprintf(fp,"\"%ld\",", INT);
/*lastRedirectRedirectReason*/                  fprintf(fp,"\"%ld\",", INT);
/*destConversationID*/                          fprintf(fp,"\"%ld\",", INT);
/*globalCallId_ClusterId*/                      fprintf(fp,"\"%s\",", STRING);
/*joinOnBehalfOf*/                              fprintf(fp,"\"%ld\",", INT);
/*comment*/                                     fprintf(fp,"\"%s\",", STRING);
/*authCodeDescription*/                         fprintf(fp,"\"%s\",", STRING);
/*authorizationLevel*/                          fprintf(fp,"\"%ld\",", INT);
/*clientMatterCode*/                            fprintf(fp,"\"%s\",", STRING);
/*origDTMFMethod*/                              fprintf(fp,"\"%ld\",", INT);
/*destDTMFMethod*/                              fprintf(fp,"\"%ld\",", INT);
/*callSecuredStatus*/                           fprintf(fp,"\"%ld\",", random_at_most(2));
/*origConversationID*/                          fprintf(fp,"\"%ld\",", INT);
/*origMediaCap_Bandwidth*/                      fprintf(fp,"\"%ld\",", INT);
/*destMediaCap_Bandwidth*/                      fprintf(fp,"\"%ld\",", INT);
/*authorizationCodeValue*/                      fprintf(fp,"\"%s\",", STRING);
/*outpulsedCallingPartyNumber*/                 fprintf(fp,"\"%s\",", STRING);
/*outpulsedCalledPartyNumber*/                  fprintf(fp,"\"%s\",", STRING);
/*origIpv4v6Addr*/                              fprintf(fp,"\"%s\",", STRING);
/*destIpv4v6Addr*/                              fprintf(fp,"\"%s\",", STRING);
/*origVideoCap_Codec_Channel2*/                 fprintf(fp,"\"%lf\",", DECIMAL);
/*origVideoCap_Bandwidth_Channel2*/             fprintf(fp,"\"%ld\",", INT);
/*origVideoCap_Resolution_Channel2*/            fprintf(fp,"\"%lf\",", DECIMAL);
/*origVideoTransportAddress_IP_Channel2*/       fprintf(fp,"\"%ld\",", INT);
/*origVideoTransportAddress_Port_Channel2*/     fprintf(fp,"\"%ld\",", INT);
/*origVideoChannel_Role_Channel2*/              fprintf(fp,"\"%ld\",", INT);
/*destVideoCap_Codec_Channel2*/                 fprintf(fp,"\"%lf\",", DECIMAL);
/*destVideoCap_Bandwidth_Channel2*/             fprintf(fp,"\"%ld\",", INT);
/*destVideoCap_Resolution_Channel2*/            fprintf(fp,"\"%lf\",", DECIMAL);
/*destVideoTransportAddress_IP_Channel2*/       fprintf(fp,"\"%ld\",", INT);
/*destVideoTransportAddress_Port_Channel2*/     fprintf(fp,"\"%ld\",", INT);
/*destVideoChannel_Role_Channel2*/              fprintf(fp,"\"%ld\",", INT);
/*IncomingProtocolID*/                          fprintf(fp,"\"%ld\",", INT);
/*IncomingProtocolCallRef*/                     fprintf(fp,"\"%s\",", STRING);
/*OutgoingProtocolID*/                          fprintf(fp,"\"%ld\",", INT);
/*OutgoingProtocolCallRef*/                     fprintf(fp,"\"%s\",", STRING);
/*currentRoutingReason*/                        fprintf(fp,"\"%ld\",", INT);
/*lastRedirectingRoutingReason*/                fprintf(fp,"\"%ld\",", INT);
/*areaCode*/                                 	fprintf(fp,"\"7%d\",", area_code);
/*originCountryCode*/                           fprintf(fp,"\"%ld\",", random_at_most(99));
/*destCountryCode*/                             fprintf(fp,"\"%ld\"\n", random_at_most(99));

                                                       }
    
		gettimeofday(&tv2, NULL);
		fprintf (stderr,"Total time = %f seconds\n",
			(double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
			(double) (tv2.tv_sec - tv1.tv_sec));
        fflush(fp);
        fclose(fp);
		return 0;
}

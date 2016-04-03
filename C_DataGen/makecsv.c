//
// Created by anjueappen on 24/03/16.
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

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
    if( argc != 2) {
        printf("Mandatory arguments: <number of rows>\n");
        return 1;
    }

    int row;
    srand(time(NULL));
	struct timeval  tv1, tv2;
	gettimeofday(&tv1, NULL);

	unsigned int guaranteedPN[3] = {4411299,3231283,9901234};
    float epsilon = 0.2;
    for(row = 0; row < atoi(argv[1]); row++) {
            float r = ((double) rand() / (RAND_MAX));
            int area_code = random_at_most(99);
            /* Default values are "row x col" */
/*cdrRecordType*/                               printf("\"%ld.0\",", random_at_most(10));
/*globalCallID_callManagerId*/                  printf("\"%ld\",", INT);
/*globalCallID_callId*/                         printf("\"%ld\",", INT);
/*origLegCallIdentifier*/                       printf("\"%ld\",", INT);
/*dateTimeOrigination*/                         printf("\"%ld\",", INT);
/*origNodeId*/                                  printf("\"%ld\",", INT);
/*origSpan*/                                    printf("\"%ld\",", INT);
/*origIpAddr*/                                  printf("\"%ld\",", INT);
                                                if (r < epsilon)
/*callingPartyNumber*/                              printf("\"780%ld\",", guaranteedPN[row%3]);
                                                else
                                                    printf("\"7%d%d\",", area_code, phone_number());
/*callingPartyUnicodeLoginUserID*/              printf("\"%s\",", STRING);
/*origCause_location*/                          printf("\"%lf\",", DECIMAL);
/*origCause_value*/                             printf("\"%lf\",", DECIMAL);
/*origPrecedenceLevel*/                         printf("\"%lf\",", DECIMAL);
/*origMediaTransportAddress_IP*/                printf("\"%ld\",", INT);
/*origMediaTransportAddress_Port*/              printf("\"%ld\",", INT);
/*origMediaCap_payloadCapability*/              printf("\"%ld\",", INT);
/*origMediaCap_maxFramesPerPacket*/             printf("\"%ld\",", 5);
/*origVideoCap_Codec*/                          printf("\"%lf\",", DECIMAL);
/*origVideoCap_Bandwidth*/                      printf("\"%ld\",", INT);
/*origVideoCap_Resolution*/                     printf("\"%lf\",", DECIMAL);
/*origVideoTransportAddress_IP*/                printf("\"%ld\",", INT);
/*origVideoTransportAddress_Port*/              printf("\"%ld\",", INT);
/*origRSVPAudioStat*/                           printf("\"%lf\",", DECIMAL);
/*origRSVPVideoStat*/                           printf("\"%lf\",", DECIMAL);
/*destLegCallIdentifier*/                       printf("\"%ld\",", INT);
/*destNodeId*/                                  printf("\"%ld\",", INT);
/*destSpan*/                                    printf("\"%ld\",", INT);
/*destIpAddr*/                                  printf("\"%ld\",", INT);
                                                if (r < epsilon)
/*callingPartyNumber*/                              printf("\"780%ld\",", guaranteedPN[(row+1)%3]);
                                                else
/*originalCalledPartyNumber*/                       printf("\"7%d%d\",", area_code, phone_number());
/*finalCalledPartyNumber*/                      printf("\"%d%d\",", area_code, phone_number()); //must be read in as string for sstables
/*finalCalledPartyUnicodeLoginUserID*/          printf("\"%s\",", STRING); //must be read in as string for sstables
/*destCause_location*/                          printf("\"%lf\",", DECIMAL);
/*destCause_value*/                             printf("\"%lf\",", DECIMAL);
/*destPrecedenceLevel*/                         printf("\"%lf\",", DECIMAL);
/*destMediaTransportAddress_IP*/                printf("\"%ld\",", INT);
/*destMediaTransportAddress_Port*/              printf("\"%ld\",", INT);
/*destMediaCap_payloadCapability*/              printf("\"%ld\",", INT);
/*destMediaCap_maxFramesPerPacket*/             printf("\"%ld\",", INT);
/*destVideoCap_Codec*/                          printf("\"%lf\",", DECIMAL);
/*destVideoCap_Bandwidth*/                      printf("\"%ld\",", INT);
/*destVideoCap_Resolution*/                     printf("\"%lf\",", DECIMAL);
/*destVideoTransportAddress_IP*/                printf("\"%ld\",", INT);
/*destVideoTransportAddress_Port*/              printf("\"%ld\",", INT);
/*destRSVPAudioStat*/                           printf("\"%ld\",", INT);
/*destRSVPVideoStat*/                           printf("\"%lf\",", DECIMAL);
/*dateTimeConnect*/                             printf("\"%ld\",", timestamp());
/*dateTimeDisConnect*/                          printf("\"%ld\",", timestamp());
/*lastRedirectDn*/                              printf("\"%s\",", STRING);
/*pkid*/                                        printf("\"%s\",", STRING);
/*originalCalledPartyNumberPartition*/          printf("\"%s\",", STRING);
/*NumberPartition*/                             printf("\"%s\",", STRING);
/*finalCalledPartyNumberPartition*/             printf("\"%s\",", STRING);
/*lastRedirectDnPartition*/                     printf("\"%s\",", STRING);
/*duration*/                                    printf("\"%ld\",", random_at_most(1000));
/*origDeviceName*/                              printf("\"%s\",", STRING);
/*destDeviceName*/                              printf("\"%s\",", STRING);
/*origCallTerminationOnBehalfOf*/               printf("\"%ld\",", INT);
/*destCallTerminationOnBehalfOf*/               printf("\"%ld\",", INT);
/*origCalledPartyRedirectOnBehalfOf*/           printf("\"%ld\",", INT);
/*lastRedirectRedirectOnBehalfOf*/              printf("\"%ld\",", INT);
/*origCalledPartyRedirectReason*/               printf("\"%ld\",", INT);
/*lastRedirectRedirectReason*/                  printf("\"%ld\",", INT);
/*destConversationID*/                          printf("\"%ld\",", INT);
/*globalCallId_ClusterId*/                      printf("\"%s\",", STRING);
/*joinOnBehalfOf*/                              printf("\"%ld\",", INT);
/*comment*/                                     printf("\"%s\",", STRING);
/*authCodeDescription*/                         printf("\"%s\",", STRING);
/*authorizationLevel*/                          printf("\"%ld\",", INT);
/*clientMatterCode*/                            printf("\"%s\",", STRING);
/*origDTMFMethod*/                              printf("\"%ld\",", INT);
/*destDTMFMethod*/                              printf("\"%ld\",", INT);
/*callSecuredStatus*/                           printf("\"%ld\",", random_at_most(2));
/*origConversationID*/                          printf("\"%ld\",", INT);
/*origMediaCap_Bandwidth*/                      printf("\"%ld\",", INT);
/*destMediaCap_Bandwidth*/                      printf("\"%ld\",", INT);
/*authorizationCodeValue*/                      printf("\"%s\",", STRING);
/*outpulsedCallingPartyNumber*/                 printf("\"%s\",", STRING);
/*outpulsedCalledPartyNumber*/                  printf("\"%s\",", STRING);
/*origIpv4v6Addr*/                              printf("\"%s\",", STRING);
/*destIpv4v6Addr*/                              printf("\"%s\",", STRING);
/*origVideoCap_Codec_Channel2*/                 printf("\"%lf\",", DECIMAL);
/*origVideoCap_Bandwidth_Channel2*/             printf("\"%ld\",", INT);
/*origVideoCap_Resolution_Channel2*/            printf("\"%lf\",", DECIMAL);
/*origVideoTransportAddress_IP_Channel2*/       printf("\"%ld\",", INT);
/*origVideoTransportAddress_Port_Channel2*/     printf("\"%ld\",", INT);
/*origVideoChannel_Role_Channel2*/              printf("\"%ld\",", INT);
/*destVideoCap_Codec_Channel2*/                 printf("\"%lf\",", DECIMAL);
/*destVideoCap_Bandwidth_Channel2*/             printf("\"%ld\",", INT);
/*destVideoCap_Resolution_Channel2*/            printf("\"%lf\",", DECIMAL);
/*destVideoTransportAddress_IP_Channel2*/       printf("\"%ld\",", INT);
/*destVideoTransportAddress_Port_Channel2*/     printf("\"%ld\",", INT);
/*destVideoChannel_Role_Channel2*/              printf("\"%ld\",", INT);
/*IncomingProtocolID*/                          printf("\"%ld\",", INT);
/*IncomingProtocolCallRef*/                     printf("\"%s\",", STRING);
/*OutgoingProtocolID*/                          printf("\"%ld\",", INT);
/*OutgoingProtocolCallRef*/                     printf("\"%s\",", STRING);
/*currentRoutingReason*/                        printf("\"%ld\",", INT);
/*lastRedirectingRoutingReason*/                printf("\"%ld\",", INT);
/*areaCode*/                                 		printf("\"7%ld\",", area_code);
/*originCountryCode*/                           printf("\"%ld\",", random_at_most(99));
/*destCountryCode*/                          		printf("\"%ld\"\n", random_at_most(99));

                                                       }
    
		gettimeofday(&tv2, NULL);
		fprintf (stderr,"Total time = %f seconds\n",
			(double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
			(double) (tv2.tv_sec - tv1.tv_sec));
		return 0;
}

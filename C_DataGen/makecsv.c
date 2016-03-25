//
// Created by anjueappen on 24/03/16.
//

#include <stdio.h>
#include <stdlib.h>

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
        x = random();
    }
        // This is carefully written not to overflow
    while (num_rand - defect <= (unsigned long)x);

    // Truncated division is intentional
    return x/bin_size;
}

long timestamp(){
    srand(time(NULL));
    return rand() % 9000000000 + 1000000000;
}

long phone_number(){
    srand(time(NULL));
    return rand()%9000000000 + 1000000000;
}
char *rand_string(char *str, size_t size)
{
    if (size) {
        --size;
        for (size_t n = 0; n < size; n++) {
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
    for(row = 0; row < atoi(argv[1]); row++) {
            /* Default values are "row x col" */
        printf("%ld, ", random_at_most(10));
        printf("%ld, ", INT);
        printf("%ld, ", INT);
        printf("%ld, ", INT);
        printf("%ld, ", INT);
        printf("%ld, ", INT);
        printf("%ld, ", INT);
        printf("%ld, ", INT);
        printf("%ld, ", phone_number());
        printf("%s, ", STRING);
        printf("%lf, ", DECIMAL);
        printf("%lf, ", DECIMAL);
        printf("%lf, ", DECIMAL);
        printf("%ld, ", INT);
        printf("%ld, ", INT);
        printf("%ld, ", INT);
        printf("%ld, ", INT);
        printf("%lf, ", DECIMAL);
        printf("%ld, ", INT);
        printf("%lf, ", DECIMAL);
        printf("%ld, ", INT);
        printf("%ld, ", INT);
        printf("%lf, ", DECIMAL);
        printf("%lf, ", DECIMAL);
        printf("%ld, ", INT);
        printf("%ld, ", INT);
        printf("%ld, ", INT);
        printf("%ld, ", INT);
        printf("%s, ", STRING);
        printf("%ld, ", phone_number());
        printf("%s, ", STRING);
        printf("%lf, ", DECIMAL);
        printf("%lf, ", DECIMAL);
        printf("%lf, ", DECIMAL);
        printf("%ld, ", INT);
        printf("%ld, ", INT);
        printf("%ld, ", INT);
        printf("%ld, ", INT);
        printf("%lf, ", DECIMAL);
        printf("%ld, ", INT);
        printf("%lf, ", DECIMAL);
        printf("%ld, ", INT);
        printf("%ld, ", INT);
        printf("%lf, ", DECIMAL);
        printf("%lf, ", DECIMAL);
        printf("%ld, ", timestamp());
        printf("%ld, ", timestamp());
        printf("%s, ", STRING);
        printf("%s, ", STRING);
        printf("%s, ", STRING);
        printf("%s, ", STRING);
        printf("%s, ", STRING);
        printf("%s, ", STRING);
        printf("%ld, ", random_at_most(1000));
        printf("%s, ", STRING);
        printf("%s, ", STRING);
        printf("%ld, ", INT);
        printf("%ld, ", INT);
        printf("%ld, ", INT);
        printf("%ld, ", INT);
        printf("%ld, ", INT);
        printf("%ld, ", INT);
        printf("%ld, ", INT);
        printf("%s, ", STRING);
        printf("%ld, ", INT);
        printf("%s, ", STRING);
        printf("%s, ", STRING);
        printf("%ld, ", INT);
        printf("%s, ", STRING);
        printf("%ld, ", INT);
        printf("%ld, ", INT);
        printf("%ld, ", INT);
        printf("%ld, ", INT);
        printf("%ld, ", INT);
        printf("%s, ", STRING);
        printf("%s, ", STRING);
        printf("%s, ", STRING);
        printf("%s, ", STRING);
        printf("%s, ", STRING);
        printf("%lf, ", DECIMAL);
        printf("%ld, ", INT);
        printf("%lf, ", DECIMAL);
        printf("%ld, ", INT);
        printf("%ld, ", INT);
        printf("%ld, ", INT);
        printf("%lf, ", DECIMAL);
        printf("%ld, ", INT);
        printf("%lf, ", DECIMAL);
        printf("%ld, ", INT);
        printf("%ld, ", INT);
        printf("%ld, ", INT);
        printf("%ld, ", INT);
        printf("%s, ", STRING);
        printf("%ld, ", INT);
        printf("%s, ", STRING);
        printf("%ld, ", INT);
        printf("%ld, ", INT);
        printf("%ld, ", INT);
        printf("%s, ", STRING);
        printf("%s \r\n", STRING);

    }
    return 0;
}
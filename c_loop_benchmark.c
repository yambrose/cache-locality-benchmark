#include <stdio.h>  // standard io (printf)
#include <stdlib.h> // standard library ()
#include <stdint.h> // fixed-sized integer types
#include <time.h> // time library

int length = 2048 * 2048;

struct timespec startTime, endTime;

void PerformArithmetic() {

    clock_gettime(CLOCK_MONOTONIC, &startTime);


    int total = 1;
    for (int i = 1; i < length; i++) {
        total += i;
    }

    clock_gettime(CLOCK_MONOTONIC, &endTime);
    
    double time_taken = (endTime.tv_sec - startTime.tv_sec) +
                    (endTime.tv_nsec - startTime.tv_nsec) / 1e9;
    printf("Time taken = %f seconds\n",  time_taken);
}

int main() {
    PerformArithmetic();
}
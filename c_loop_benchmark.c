#include <stdio.h>  
#include <stdlib.h> 
#include <stdint.h> 
#include <time.h> 

long long length = 2048 * 2048;

struct timespec startTime, endTime;

void PerformArithmetic() {
    clock_gettime(CLOCK_MONOTONIC, &startTime);

    long long total = 1;
    for (long long i = 1; i < length; i++) {
        total += i;
    }

    clock_gettime(CLOCK_MONOTONIC, &endTime);
    
    double time_taken = (endTime.tv_sec - startTime.tv_sec) +
                    (endTime.tv_nsec - startTime.tv_nsec) / 1e9;
    printf("Time taken = %.16f seconds, total = %lld\n",  time_taken, total);
}

int main() {
    PerformArithmetic();
}
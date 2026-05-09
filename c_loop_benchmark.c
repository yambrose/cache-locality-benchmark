#define TRIALS 5;

#include <stdio.h>  
#include <stdlib.h> 
#include <stdint.h> 
#include <time.h> 

long long length = 2048 * 2048;

struct timespec startTime, endTime;

float PerformArithmetic() {
    clock_gettime(CLOCK_MONOTONIC, &startTime);

    long long total = 1;
    for (long long i = 1; i < length; i++) {
        total += i;
    }

    clock_gettime(CLOCK_MONOTONIC, &endTime);
    
    float timeTaken = (endTime.tv_sec - startTime.tv_sec) +
                    (endTime.tv_nsec - startTime.tv_nsec) / 1e9;
    printf("Time taken = %.16f seconds, total = %lld\n",  timeTaken, total);

    return timeTaken;
}

int main() {
    float totalTimeTaken = 0.0f;

    printf("RUNNING C LOOP BENCHMARK\n");
    for (int trial = 1; trial < TRIALS+1; trial++) {
        totalTimeTaken += PerformArithmetic(trial);
    }

    printf("C Loop Average: %16f seconds", totalTimeTaken);
}

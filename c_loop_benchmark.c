#include <stdio.h>  
#include <stdlib.h> 
#include <stdint.h> 
#include <time.h> 

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
    printf("Time taken = %.16f seconds, total = %d\n",  time_taken, total);
}

int main() {
    PerformArithmetic();
}
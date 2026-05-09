#define _POSIX_C_SOURCE 199309L
#define TRIALS 5

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rows = 1024;
int cols = 1024;
int **array;

struct timespec startTime, endTime;

void FillArray() {
    array = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        array[i] = (int *)malloc(cols * sizeof(int));

        for (int j = 0; j < cols; j++) {
            array[i][j] = rand() % 10;
        }
    }
}


void SequentialAccess() {
    printf("STARTING SEQUENTIAL ACCESS TRIALS:\n");
    float totalTimeTaken = 0;

    for (int trial = 1; trial < TRIALS+1; trial++) {
        float timeTaken;
        clock_gettime(CLOCK_MONOTONIC, &startTime);

        long long sum = 0;
        for (long long i = 0; i < rows; i++) {
            for (long long j = 0; j < cols; j++) {
                sum += array[i][j];
            }
        }
        clock_gettime(CLOCK_MONOTONIC, &endTime);
        timeTaken = (endTime.tv_sec - startTime.tv_sec) +
                    (endTime.tv_nsec - startTime.tv_nsec) / 1e9;

        printf("Trial %d: Sum = %lld, Time taken = %.16f seconds\n", trial, sum, timeTaken);

        totalTimeTaken += timeTaken;
    }
    

    printf("Sequential Access Average: Time taken = %.16f seconds\n", totalTimeTaken / TRIALS);
}

void StridedAccess() {
    printf("\nSTARTING STRIDED ACCESS TRIALS:\n");
    float totalTimeTaken = 0;

    for (int trial = 1; trial < TRIALS+1; trial++) {
        float timeTaken;
        clock_gettime(CLOCK_MONOTONIC, &startTime);

        long long sum = 0;
        for (long long i = 0; i < rows; i++) {
            for (long long j = 0; j < cols; j++) {
                sum += array[j][i];
            }
        }
        clock_gettime(CLOCK_MONOTONIC, &endTime);
        timeTaken = (endTime.tv_sec - startTime.tv_sec) +
                    (endTime.tv_nsec - startTime.tv_nsec) / 1e9;

        printf("Trial %d: Sum = %lld, Time taken = %.16f seconds\n", trial, sum, timeTaken);

        totalTimeTaken += timeTaken;
    }
    

    printf("Strided Access Average: Time taken = %.16f seconds\n", totalTimeTaken / TRIALS);
}

void RandomAccess() {
    printf("\nSTARTING RANDOM ACCESS TRIALS:\n");
    float totalTimeTaken = 0;

    for (int trial = 1; trial < TRIALS+1; trial++) {
        float timeTaken;
        clock_gettime(CLOCK_MONOTONIC, &startTime);

        long long sum = 0;
        for (long long i = 0; i < rows; i++) {
            for (long long j = 0; j < cols; j++) {
                sum += array[rand() % rows][rand() % cols];
            }
        }
        clock_gettime(CLOCK_MONOTONIC, &endTime);
        timeTaken = (endTime.tv_sec - startTime.tv_sec) +
                    (endTime.tv_nsec - startTime.tv_nsec) / 1e9;

        printf("Trial %d: Sum = %lld, Time taken = %.16f seconds\n", trial, sum, timeTaken);

        totalTimeTaken += timeTaken;
    }
    

    printf("Random Access Average: Time taken = %.16f seconds\n", totalTimeTaken / TRIALS);
}

int main() {
    FillArray();
    SequentialAccess();
    StridedAccess();
    RandomAccess();

    free(array);
    return 0;
}

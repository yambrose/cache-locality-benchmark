#define _POSIX_C_SOURCE 199309L
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

    printf("%d\n", array[2]);
}


void SequentialAccess() {

    clock_gettime(CLOCK_MONOTONIC, &startTime);

    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += array[i][j];
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &endTime);
    double timeTaken = (endTime.tv_sec - startTime.tv_sec) +
                    (endTime.tv_nsec - startTime.tv_nsec) / 1e9;
    printf("Sequential Access: Sum = %d, Time taken = %.16f seconds\n", sum, timeTaken);
}

void StridedAccess() {
    clock_gettime(CLOCK_MONOTONIC, &startTime);
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += array[j][i];
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &endTime);
    double timeTaken = (endTime.tv_sec - startTime.tv_sec) +
                    (endTime.tv_nsec - startTime.tv_nsec) / 1e9;
    printf("Strided Access: Sum = %d, Time taken = %.16f seconds\n", sum, timeTaken);
}

void RandomAccess() {
    clock_gettime(CLOCK_MONOTONIC, &startTime);
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += array[rand() % rows][rand() % cols];
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &endTime);
    double timeTaken = (endTime.tv_sec - startTime.tv_sec) +
                    (endTime.tv_nsec - startTime.tv_nsec) / 1e9;
    printf("Random Access: Sum = %d, Time taken = %.16f seconds\n", sum, timeTaken);
}

int main() {
    FillArray();
    SequentialAccess();
    StridedAccess();
    RandomAccess();

    return 0;
}
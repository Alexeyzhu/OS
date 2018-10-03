//
// Created by Alexey on 03.10.18.
//
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <memory.h>

void *myrealloc(void *ptr, size_t size) {

    void *newptr = malloc(size);

    if (ptr != NULL & size > 0) {
        memcpy(newptr, ptr, size);
    }

    free(ptr);

    if (size > 0) {
        return newptr;
    } else {
        return NULL;
    }
}


int main() {
    int N = 15;

    int *array = malloc(sizeof(int) * N);

    for (int i = 0; i < N; ++i) {
        array[i] = i;
    }

    printf("Increasing sequense from 0 to %d \n", N);

    for (int i = 0; i < N; ++i) {
        printf("%d ", array[i]);
    }

    array = myrealloc(array, sizeof(int) * (N + 5));
    printf("\n Reallocated array of size %d \n", N + 5);

    for (int i = 0; i < N + 5; ++i) {
        printf("%d ", array[i]);
    }

    array = myrealloc(array, sizeof(int) * (N - 10));
    printf("\n Reallocated array of size %d \n", N - 10);

    for (int i = 0; i < N - 10; ++i) {
        printf("%d ", array[i]);
    }

    array = realloc(NULL, sizeof(int) * 6);
    printf("\n New array of size %d \n", 6);

    for (int i = 0; i < 6; ++i) {
        printf("%d ", array[i]);
    }

    return 0;
}
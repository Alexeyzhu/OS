//
// Created by Alexey on 03.10.18.
//

#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    printf("Enter size of array: ");
    scanf("%d", &N);
    int *array = malloc(sizeof(int) * N);
    for (int i = 0; i < N; ++i) {
        array[i] = i;
    }

    printf("Increasing sequense from 0 to %d \n", N);

    for (int i = 0; i < N; ++i) {
        printf("%d ", array[i]);
    }

    free(array);
    return 0;
}
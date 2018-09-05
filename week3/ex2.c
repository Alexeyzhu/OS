//
// Created by alexey on 05.09.18.
//

#include <stdio.h>
#include <memory.h>

int *bubble_sort(int *, int);

int main(void) {

    int size = 10;

    int arr[10] = {25, 87, 1, 8, 76, 23, 43, 67, 37, 66};

    bubble_sort(arr, size);
    printf("Result is: ");
    for (int i = 0; i < 10; ++i) {
        printf("%d ", arr[i]);
    }

    return 0;
}

int *bubble_sort(int *array, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 1; j < (size - i); ++j) {
            if (array[j - 1] > array[j]) {
                int temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;
            }
        }
    }
}
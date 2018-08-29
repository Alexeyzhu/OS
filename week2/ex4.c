#include <stdio.h>

//
// Created by alexey on 29.08.18.
//

void swap(int*, int*);

main() {
    int a, b;
    printf("Enter 2 numbers: ");
    scanf("%d %d", &a, &b);
    swap(&a, &b);
    printf("\n Result: ");
    printf("%d %d \n", a, b);
}

void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
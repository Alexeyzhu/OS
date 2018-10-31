//
// Created by Alexey on 10/31/18.
//

#include <stdio.h>
#include <unistd.h>

int main_1(void) {
    printf("Hello");
    fork();
    printf("\n");
    return 0;
}

int main_2(void) {
    printf("Hello\n");
    fork();
    printf("\n");
    return 0;
}
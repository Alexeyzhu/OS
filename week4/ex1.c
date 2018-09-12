//
// Created by alexey on 12.09.18.
//

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 10;
    int result = fork();


    if (result == 0) {
        printf("Hello from child [%d - %d].\n", getpid(), n);
    } else if (result == -1) {
        return -1;
    } else {
        printf("Hello from parent [%d - %d]. My child is %d\n", getpid(), n, result);
    }

    return 0;
}
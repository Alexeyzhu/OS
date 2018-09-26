//
// Created by Alexey on 26.09.18.
//

#include <stdio.h>
#include <unistd.h>
#include <memory.h>

int main() {

    char s1[6] = "Hello!";
    char s2[6] = "";
    int rw[2];

    if (pipe(rw) < 0) {
        return -1;
    }

    write(rw[1], s1, (sizeof(s1) / sizeof(char)) + 1);
    close(rw[1]);

    read(rw[0], s2, (sizeof(s1) / sizeof(char)) + 1);
    close(rw[0]);

    printf("Second string is: %s \n", s2);

    return 0;
}
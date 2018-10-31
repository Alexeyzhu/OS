//
// Created by Alexey on 10/31/18.
//

#include <stdio.h>
#include <zconf.h>
#include <stdlib.h>

int main() {
    int status = setvbuf(stdout, 0, _IOLBF, 0);
    if (status < 0) {
        exit(1);
    }

    printf("%c", 'H');
    sleep(1);
    printf("%c", 'e');
    sleep(1);
    printf("%c", 'l');
    sleep(1);
    printf("%c", 'l');
    sleep(1);
    printf("%c", 'o');
    sleep(1);

    printf("\n");

    return 0;
}

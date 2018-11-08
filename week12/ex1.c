#include <stdio.h>
#include <zconf.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
    int file = open("../ex1.txt", O_WRONLY);
    int ran = open("/dev/random", O_RDONLY);
    char *s = malloc(sizeof(char) * 20);
    if (read(ran, s, 20) == -1) {
        exit(-1);
    }
    if (write(file, s, 20) == -1) {
        exit(-1);
    }
    close(ran);
    close(file);
    return 0;
}
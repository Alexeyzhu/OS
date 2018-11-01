#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <zconf.h>
#include <string.h>
#include <sys/mman.h>

int main() {
    char *word = "This is a\n"
                 "nice day";

    int filedesc = open("../ex1.txt", O_RDWR);
    if (filedesc < 0)
        exit(1);

    struct stat buffer;
    ftruncate(filedesc, strlen(word));
    if (fstat(filedesc, &buffer) < 0) {
        exit(2);
    }

    void *mapped;
    mapped = mmap(0, (size_t) buffer.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, filedesc, 0);
    if (mapped == MAP_FAILED) {
        exit(3);
    }

    memcpy(mapped, word, (size_t) buffer.st_size);
    msync(mapped, (size_t) buffer.st_size, MS_SYNC);

    return 0;
}

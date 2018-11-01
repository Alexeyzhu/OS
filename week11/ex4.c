//
// Created by Alexey on 10/31/18.
//

#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>

int main() {
    int filedesc = open("../ex1.txt", O_RDWR);
    if (filedesc < 0)
        exit(1);

    struct stat buffer;
    int status = fstat(filedesc, &buffer);
    if (status < 0) {
        exit(2);
    }

    void *mapped;
    mapped = mmap(0, (size_t) buffer.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, filedesc, 0);
    if (mapped == MAP_FAILED) {
        exit(3);
    }

    int filedescmemcpy = open("../ex1.memcpy.txt", O_RDWR);
    if (filedescmemcpy < 0) {
        exit(4);
    }

    ftruncate(filedescmemcpy, buffer.st_size);


    void *mapped2;
    mapped2 = mmap(0, (size_t) buffer.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, filedescmemcpy, 0);
    if (mapped2 == MAP_FAILED) {
        exit(6);
    }

    memcpy(mapped2, mapped, (size_t) buffer.st_size);
    msync(mapped2, (size_t) buffer.st_size, MS_SYNC);
    munmap(mapped2, (size_t) buffer.st_size);

    return 0;
}
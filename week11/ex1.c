#include <stdio.h>
#include <fcntl.h>

int main() {
    char *word = "This is a\n"
                 "nice day";

    int filedesc = open("../ex1.txt", O_RDWR);
    if (filedesc < 0)
        exit(1);

    struct stat buffer;
    int status = fstat(filedesc, &buffer);
    if (status < 0) {
        exit(2);
    }

    if (strlen(word) > buffer.st_size) {
        ftruncate(filedesc, strlen(word));
        status = fstat(filedesc, &buffer);
        if (status < 0) {
            exit(2);
        }
    }


    void *mapped;
    mapped = mmap(0, (size_t) buffer.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, filedesc, 0);
    if (mapped == MAP_FAILED) {
        exit(3);
    }

    if (buffer.st_size > strlen(word)) {
        memcpy(mapped, word, strlen(word));
    } else {
        memcpy(mapped, word, buffer.st_size);
    }

    msync(mapped, (size_t) buffer.st_size, MS_SYNC);

    return 0;
}

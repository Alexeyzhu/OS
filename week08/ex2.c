#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>

int main() {
    int mb = 1024 * 1024;
    for (int i = 0; i < 10; ++i) {
        printf("Time %d : \n", i);
        void *ptr = malloc(10 * mb);
        memset(ptr, 0, 10 * mb);
        //printf("Still alive! %d\n", getpid());
        sleep(1);
    }
    return 0;
}
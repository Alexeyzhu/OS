//
// Created by Alexey on 11.10.18.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    int who = RUSAGE_SELF;
    struct rusage usage;
    int mb = 1024 * 1024;
    for (int j = 0; j < 10; ++j) {
        printf("Time %d : \n", j);
        void *ptr = malloc(10 * mb);
        memset(ptr, 0, 10 * mb);
        int i = getrusage(who, &usage);
        printf("Max resident set data %ld\n",usage.ru_maxrss);
        printf("Integral shared memory size %ld\n",usage.ru_ixrss);
        printf("Integral unshared data size %ld\n",usage.ru_idrss);
        printf("Integral unshared stack size %ld\n",usage.ru_isrss);
        //printf("Still alive! %d\n", getpid());
        sleep(1);
    }
    return 0;
}

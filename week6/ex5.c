//
// Created by Alexey on 26.09.18.
//

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main() {
    int pid = fork();
    if (pid == -1) {
        return -1;
    }

    if (pid > 0) {
        sleep(10);
        kill(pid, SIGTERM);
    } else {
        while (1) {
            sleep(1);
            printf("I'm alive %d \n", getpid());
        }
    }

    return 0;
}

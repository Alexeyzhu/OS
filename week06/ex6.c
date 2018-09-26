//
// Created by Alexey on 26.09.18.
//

#include <unistd.h>
#include <stdio.h>
#include <wait.h>

int main() {
    int rw[2];
    int status2;

    if (pipe(rw) < 0) {
        return -1;
    }

    int pid1 = fork();
    int pid2 = -256;

    if (pid1 == -1) {
        return -1;
    }

    if (pid1 > 0) {
        pid2 = fork();
    }

    if (pid2 == -1) {
        return -1;
    }

    printf("PROCESS [%d] | Children are P1: [%d] P2: [%d] \n", getpid(), pid1, pid2);

    if (pid1 == 0) {
        printf("PROCESS [%d] | Reads message from parent \n", getpid());
        close(rw[1]);
        read(rw[0], &pid2, sizeof(int));
        close(rw[0]);
        printf("PROCESS [%d] | Gonna terminate [%d] \n", getpid(), pid2);
        if (pid2 != getpid()) {
            sleep(5);
            kill(pid2, SIGSTOP);
            printf("PROCESS [%d] | Terminated [%d] \n", getpid(), pid2);
        }

    } else if (pid1 > 0 & pid2 > 0) {
        printf("PROCESS [%d] | Sends the message to child [%d] \n", getpid(), pid1);
        close(rw[0]);
        write(rw[1], &pid2, sizeof(int));
        close(rw[1]);
        int p = pid2;
        wait(&pid2);
        printf("PROCESS [%d] | Process [%d] is terminated \n ", getpid(), p);

    } else if (pid2 == 0) {
        printf("PROCESS [%d] | Hello world!  \n", getpid());
        while (1) {
            printf("PROCESS [%d] | Still alive! \n", getpid());
            sleep(1);
        }
    }

    return 0;
}

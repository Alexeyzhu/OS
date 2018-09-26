//
// Created by Alexey on 26.09.18.
//

#include <unistd.h>
#include <stdio.h>
#include <wait.h>

int main() {
    int rw[2];
    int status1;
    int status2;

    if (pipe(rw) < 0) {
        return -1;
    }

    int pid1 = fork();
    int pid2 = -259;

    if (pid1 == -1) {
        return -1;
    }

    if (pid1 > 0) {
        pid2 = fork();
    }

    if (pid2 == -1) {
        return -1;
    }

    printf("I'm %d. My children are P1: %d P2: %d \n", getpid(), pid1, pid2);

    if (pid1 == 0) {
        printf("Hello from child P1 %d \n", getpid());
        close(rw[1]);
        read(rw[0], &pid2, sizeof(int));
        close(rw[0]);
        printf("%d gonna terminate %d \n", getpid(), pid2);
        if (pid2 != getpid()) {
            sleep(3);
            kill(pid2, SIGSTOP);
            printf("%d terminated by %d \n", pid2, getpid());
        }

    } else if (pid1 > 0 & pid2 > 0) {
        printf("Hello from parent %d \n", getpid());
        close(rw[0]);
        write(rw[1], &pid2, sizeof(int));
        close(rw[1]);
        int i = pid2;
        wait(&pid2);
        printf("%d is terminated (%d)\n ", i, getpid());

    } else if (pid2 == 0) {
        printf("Hello from child P2 %d \n", getpid());
        while (1) {
            printf("I'm %d still alive \n", getpid());
            sleep(1);
        }
    }

    return 0;
}

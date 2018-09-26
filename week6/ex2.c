//
// Created by alexey on 26.09.18.
//

#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include <wait.h>

int main() {

    char s1[6] = "Hello!";
    char s2[6] = "";
    int rw[2];

    if (pipe(rw) < 0) {
        return -1;
    }

    int pid = fork();

    if (pid == -1) {
        return -1;
    }

    if (pid == 0) {
        close(rw[1]);
        read(rw[0], s2, (sizeof(s1) / sizeof(char)) + 1);
        close(rw[0]);
        printf("String from child : %s My PID is %d \n", s2, getpid());
    } else {
        printf("Hello from parent PID: %d \n", getpid());
        close(rw[0]);
        write(rw[1], s1, (sizeof(s1) / sizeof(char)) + 1);
        close(rw[1]);
        wait(pid);
    }

    return 0;
}
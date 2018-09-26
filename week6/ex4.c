//
// Created by alexey on 26.09.18.
//

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void sighandler(int);

int main() {
    signal(SIGKILL, sighandler);
    signal(SIGSTOP, sighandler);
    signal(SIGUSR1, sighandler);

    while (1) {
        sleep(1);
        printf("\n %d", getpid());
    }

}

void sighandler(int sig) {
    if (sig == 9) {
        printf("\n Caught SIGKILL");
    } else if (sig == 23) {
        printf("\n Caught SIGSTOP");
    } else if (sig == 10) {
        printf("\n Caught SIGUSR1");
        exit(1);
    }
}
//
// Created by alexey on 26.09.18.
//

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void sighandler(int);

int main() {
    signal(SIGINT, sighandler);

    while (1) {
        sleep(1);
    }

    return 0;
}

void sighandler(int sig) {
    if (sig == 2) {
        printf("\n Caught SIGINT");
    }
}

//
// Created by alexey on 12.09.18.
//

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <unistd.h>
#include <wait.h>

int main() {
    char command[50];

    do {

        printf("user@command > ");
        fgets(command, sizeof(command), stdin);
        printf("\n");
        fork();
        system(command);
    } while (strcmp(command, "exit\n") != 0);

    return 0;
}


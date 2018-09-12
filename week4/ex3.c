//
// Created by alexey on 12.09.18.
//

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main() {
    char command[10] = "";
    do {
        system(command);
        printf("user@command > ");
        scanf("%s", command);
        printf("\n");
    } while (strcmp(command, "exit") != 0);
    return 0;
}




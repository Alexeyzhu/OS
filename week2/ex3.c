//
// Created by alexey on 29.08.18.
//

#include <stdio.h>

exercise3() {
    int height;
    printf("Enter the height of tree: ");
    scanf("%d", &height);

    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= (height - i); j++) {
            printf(" ");
        }
        for (int k = 1; k <= (2*i - 1); k++) {
            printf("*");
        }
        printf("\n");
    }


}

//
// Created by alexey on 29.08.18.
//

#include <stdio.h>

void tree(int *);

void triangle(int *);

void star(int *);

void plane(int *);

int read(int*);

main() {
    int height, exit = 1;
    printf("Enter the height of pic: ");
    scanf("%d", &height);

    while (exit == 1){
        exit = read(&height);
    }
}

int read(int *height) {

    int type;
    printf("Enter the type of pic: \n 1 - tree \n 2 - triangle \n 3 - star \n 4 - plane \n 0 - exit \n");
    scanf("%d", &type);

    switch (type) {
        case 1:
            tree(height);
            break;
        case 2:
            triangle(height);
            break;
        case 3:
            star(height);
            break;
        case 4:
            plane(height);
            break;
        case 0:
            return 0;
        default:
            return 1;
    }
    return 0;
}

void tree(int *height) {
    for (int i = 1; i <= *height; i++) {
        for (int j = 1; j <= (*height - i); j++) {
            printf(" ");
        }
        for (int k = 1; k <= (2 * i - 1); k++) {
            printf("*");
        }
        printf("\n");
    }
}

void triangle(int *height) {
    for (int i = 1; i <= *height; i++) {
        for (int k = 1; k <= i; k++) {
            printf("*");
        }
        printf("\n");
    }
}

void star(int *height) {
    for (int i = 1; i <= (*height / 2); i++) {
        for (int k = 1; k <= i; k++) {
            printf("*");
        }
        printf("\n");
    }

    if ((*height % 2) != 0) {
        for (int k = 1; k <= (*height / 2) + 1; k++) {
            printf("*");
        }
        printf("\n");
    }

    for (int i = (*height / 2); i > 0; i--) {
        for (int k = 1; k <= i; k++) {
            printf("*");
        }
        printf("\n");
    }
}

void plane(int *height) {
    for (int i = 1; i <= *height; i++) {
        for (int k = 1; k <= *height; k++) {
            printf("*");
        }
        printf("\n");
    }
}
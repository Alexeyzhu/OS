//
// Created by alexey on 29.08.18.
//

#include <stdio.h>
#include <memory.h>

main() {
    int l, i = 0;
    char arr[100];
    char *tail, *head;
    printf("Enter string: ");
    scanf("%s", arr);
    l = (int) strlen(arr);

    head = arr;
    tail = arr - 1 + l;

    while (i < (l / 2)) {
        char tmp = *head;
        *head = *tail;
        *tail = tmp;
        head++;
        tail--;
        i++;
    }

    printf("%s", arr);
}

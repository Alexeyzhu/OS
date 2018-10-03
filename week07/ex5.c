//
// Created by Alexey on 03.10.18.
//

#include <stdio.h>
#include <stdlib.h>

int main() {
    char **s = calloc(1, 1);
    char foo[] = "Hello World";

    *s = foo;
    printf("s is %s\n", *s);

    s[0] = foo;
    printf("s[0] is %s\n", s[0]);

    return (0);
}

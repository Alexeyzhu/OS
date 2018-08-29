//
// Created by alexey on 29.08.18.
//
#include <stdio.h>
#include <float.h>
#include <limits.h>

main(){
    int i;
    float f;
    double d;

    i = INT_MAX;
    f = FLT_MAX;
    d = DBL_MAX;

    printf("Max int is %d , size is %ld \n", i, sizeof(i));
    printf("Max float is %f , size is %ld \n", f, sizeof(f));
    printf("Max double is %f , size is %ld \n", d, sizeof(d));
}

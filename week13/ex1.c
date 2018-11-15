#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zconf.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    FILE *fpo;
    char *line = NULL;
    char *end_ptr = NULL;
    size_t len = 0;
    ssize_t read;
    int resources = 3;
    int processes = 5;


    if (argc > 1) {
        resources = (int) strtol(argv[0], NULL, 10);
        processes = (int) strtol(argv[1], NULL, 10);
    }
    fp = fopen("../input_dl.txt", "r");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    fpo = fopen("../output_dl.txt", "w");
    if (fpo == NULL) {
        exit(EXIT_FAILURE);
    }

    read = getline(&line, &len, fp);
    int *E = malloc(sizeof(int) * resources);

    end_ptr = line;
    for (int i = 0; i < resources; ++i) {
        E[i] = (int) strtol(end_ptr, &end_ptr, 10);
    }

    read = getline(&line, &len, fp); //empty string

    read = getline(&line, &len, fp);
    end_ptr = line;
    int *A = malloc(sizeof(int) * resources);
    for (int i = 0; i < resources; ++i) {
        A[i] = (int) strtol(end_ptr, &end_ptr, 10);
    }

    read = getline(&line, &len, fp); //empty string

    int **C = malloc((sizeof(int) * resources) * processes);
    for (int j = 0; j < processes; ++j) {
        read = getline(&line, &len, fp);
        end_ptr = line;
        int *arr = malloc(sizeof(int) * resources);
        for (int i = 0; i < resources; ++i) {
            arr[i] = (int) strtol(end_ptr, &end_ptr, 10);
        }
        C[j] = arr;
    }

    read = getline(&line, &len, fp); //empty string

    int **R = malloc((sizeof(int) * resources) * processes);
    for (int k = 0; k < processes; ++k) {
        read = getline(&line, &len, fp);
        end_ptr = line;
        int *arr = malloc(sizeof(int) * resources);
        for (int i = 0; i < resources; ++i) {
            arr[i] = (int) strtol(end_ptr, &end_ptr, 10);
        }
        R[k] = arr;
    }

    int *marks = malloc(sizeof(int) * processes);
    for (int n = 0; n < processes; ++n) {
        marks[n] = 0;
    }
    int not_finished = 1;

    while (not_finished) {
        not_finished = 0;
        for (int l = 0; l < processes; ++l) {
            if (marks[l] == 0) {
                int less = 1;
                for (int i = 0; i < resources; ++i) {
                    if (R[l][i] > A[i]) {
                        less = 0;
                    }
                }
                if (less) {
                    for (int i = 0; i < resources; ++i) {
                        A[i] += C[l][i];
                    }
                    marks[l] = 1;
                    not_finished = 1;
                }
            }
        }
    }

    for (int m = 0; m < processes; ++m) {
        if (marks[m] > 0) {
            fprintf(fpo, "%d : OK \n", m + 1);
        } else {
            fprintf(fpo, "%d : Deadlocked \n", m + 1);
        }
    }


    fclose(fp);
    fclose(fpo);
    return 0;
}
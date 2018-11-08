//
// Created by Alexey on 11/8/18.
//

#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <zconf.h>
#include <stdio.h>

#define BUFF_SIZE 1000

int main(int argc, char *argv[]) {
    int append_file = 0;
    int files_num = argc - 1;

    if (argc > 1) {
        if (memcmp("-a", argv[1], sizeof(char) * 2) == 0) {
            append_file = 1;
            files_num = files_num - 1;
        }


        int list_of_files[files_num];
        for (int i = 0; i < files_num; ++i) {
            if (append_file) {
                list_of_files[i] = open(argv[i + 2], O_WRONLY | O_CREAT | O_APPEND);
            } else {
                list_of_files[i] = open(argv[i + 1], O_WRONLY | O_CREAT | O_TRUNC);
            }
        }

        char *buffer = malloc(sizeof(char) * BUFF_SIZE);
        int size_input = 0;

        while (fgets(buffer, BUFF_SIZE, stdin) != NULL) {
            size_t size = strlen(buffer);
            for (int j = 0; j < files_num; ++j) {
                write(list_of_files[j], buffer, size);
            }
        }

        printf("%s \n", buffer);

        for (int k = 0; k < files_num; ++k) {
            close(list_of_files[k]);
        }
    }

    return 0;
}
#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>

#define I_NODES_MAX 100

typedef struct inno {
    ino_t inno;
    int lenght;
    char names[50][15];
} inodes;

int main() {
    FILE *fp = fopen("ex4.txt", "w");
    int size = 0;
    inodes *inodelist = malloc(I_NODES_MAX * sizeof(inodes));

    DIR *dirp = opendir("../tmp");
    if (dirp == NULL) {
        return (-1);
    }

    struct dirent *dp;
    while ((dp = readdir(dirp)) != NULL) {
        int set = 0;
        __ino_t ino = dp->d_ino;
        for (int i = 0; i < size; ++i) {
            if (inodelist[i].inno == ino) {
                strcpy(inodelist[i].names[inodelist[i].lenght], dp->d_name);
                inodelist[i].lenght = inodelist[i].lenght + 1;
                set = 1;
                break;
            }
        }
        if (set == 0) {
            inodes in;
            in.inno = ino;
            strcpy(in.names[0], dp->d_name);
            in.lenght = 1;
            inodelist[size] = in;
            size++;
        }
    }

    for (int j = 0; j < size; ++j) {
        if (inodelist[j].lenght > 1) {
            for (int i = 0; i < inodelist[j].lenght; ++i) {
                fprintf(fp, "%s \n", inodelist[j].names[i]);
            }
        }
    }

    (void) closedir(dirp);
    fclose(fp);
    return (0);
}
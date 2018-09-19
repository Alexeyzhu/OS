#include <stdio.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void *print_hello_world(void *tid) {
    printf("Hello! I'm a thread %d\n", tid);
    printf("Good bye! I'm a thread %d\n", tid);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    int number_of_threads = 10;
    pthread_t threads[number_of_threads];
    int status, i;

    printf("Parallel sequence \n");

    for (i = 0; i < number_of_threads; i++) {
        printf("Main function. Creating thread %d\n", i);
        status = pthread_create(&threads[i], NULL, print_hello_world, (void *) i);
        if (status != 0) {
            printf("Oops. pthread create returned error code %d\n", status);
            exit(-1);
        }
    }

    for (int j = 0; j < number_of_threads; ++j) {
        pthread_join(threads[i], NULL);
    }

    sleep(2);

    printf("Ordered sequence\n");

    for (i = 0; i < number_of_threads; i++) {
        printf("Main function. Creating thread %d\n", i);
        status = pthread_create(&threads[i], NULL, print_hello_world, (void *) i);
        pthread_join(threads[i], NULL);

        if (status != 0) {
            printf("Oops. pthread create returned error code %d\n", status);
            exit(-1);
        }
    }

    return 0;
}
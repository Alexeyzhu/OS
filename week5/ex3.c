//
// Created by alexey on 19.09.18.
//

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_t threads[2];
int producer_st = 1, consumer_st = 1;
int itemCount = 0, max_count = 100;

void producer();

void consumer();

int main() {
    pthread_create(&threads[0], NULL, producer, NULL);
    pthread_create(&threads[1], NULL, consumer, NULL);
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    return 0;
}

void producer() {
    while (1) {
        sleep(0.1);
        if (itemCount == max_count) {
            printf("Producer felt asleep\n");
            producer_st = 0;
        }
        if (producer_st) {
            printf("Producer added something\n");
            itemCount = itemCount + 1;
        }

        if (itemCount == 1) {
            printf("Producer woke up\n");
            consumer_st = 1;
        }
    }
}

void consumer() {
    while (1) {
        sleep(0.1);
        if (itemCount == 0) {
            printf("Consumer felt asleep\n");
            consumer_st = 0;
        }

        if (consumer_st) {
            printf("Consumer removed something\n");
            itemCount = itemCount - 1;
        }

        if (itemCount == max_count) {
            printf("Consumer woke up\n");
            producer_st = 1;
        }

    }
}
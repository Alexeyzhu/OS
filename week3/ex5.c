//
// Created by alexey on 05.09.18.
//

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

struct List {
    struct Node *head;
    struct Node *tail;
    int size;

};

struct Node {
    struct Node *next;
    struct Node *last;
    int value;
};


void print_list(struct List *);

void insert_node(struct List *, int);

int delete_node(struct List *, int);

int main() {
    struct List *list1 = malloc(sizeof(struct List));
    list1->head = NULL;
    list1->tail = NULL;
    list1->size = 0;

    insert_node(list1, 1);

    delete_node(list1, 1);
    print_list(list1);

    insert_node(list1, 2);
    insert_node(list1, 3);
    insert_node(list1, 4);
    insert_node(list1, 5);
    insert_node(list1, 6);

    delete_node(list1, 2);
    delete_node(list1, 7);
    print_list(list1);

    insert_node(list1, 9);
    insert_node(list1, 10);

    delete_node(list1, 10);

    print_list(list1);

    struct List *list2 = malloc(sizeof(struct List));
    list2->head = NULL;
    list2->tail = NULL;
    list2->size = 0;

    insert_node(list2, 3);

    delete_node(list2, 3);
    print_list(list2);

    insert_node(list2, 2);
    insert_node(list2, 9);
    insert_node(list2, 78);
    insert_node(list2, 56);
    insert_node(list2, 5);
    insert_node(list2, 48);

    delete_node(list2, 78);
    delete_node(list2, 2);
    print_list(list2);

    insert_node(list2, 9);
    insert_node(list2, 19);

    delete_node(list2, 19);

    print_list(list2);

    return 0;
}

void print_list(struct List *list) {
    struct Node *temp = list->head;
    printf("List: ");
    for (int i = 0; i < list->size; ++i) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void insert_node(struct List *list, int data) {
    struct Node *new = malloc(sizeof(struct Node));
    new->value = data;
    new->next = NULL;
    new->last = NULL;

    if (list->size == 0) {
        list->head = new;
        list->tail = new;
        list->size++;
    } else {
        list->tail->next = new;
        new->last = list->tail;
        list->tail = new;
        list->size++;
    }
}

int delete_node(struct List *list, int key) {
    if (list->size == 0) {
        return -1;
    } else if (list->size == 1) {
        list->head->next = NULL;
        free(list->tail);
        list->tail = list->head;
        list->size--;
    } else {
        struct Node *temp = list->head;
        while (temp->value != key && temp->next != NULL) {
            temp = temp->next;
        }
        if (temp->value != key) {
            return -1;
        }
        if (temp == list->head) {
            list->head = temp->next;
        } else if (temp->next != NULL) {
            temp->last->next = temp->next;
        } else {
            list->tail = temp->last;
            temp->last->next = NULL;
        }
        free(temp);
        list->size--;
    }
    return 0;
}

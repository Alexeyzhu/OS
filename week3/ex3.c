//
// Created by alexey on 05.09.18.
//

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

struct Node {
    struct Node *next;
    int value;
};

struct Node *head;
struct Node *tail;
int size;

void print_list();

void insert_node(int);

int delete_node(int);

int main() {
    head = NULL;
    tail = NULL;
    size = 0;

    insert_node(1);

    delete_node(1);
    print_list();

    insert_node(2);
    insert_node(3);
    insert_node(4);
    insert_node(5);
    insert_node(6);

    delete_node(2);
    delete_node(7);
    print_list();

    insert_node(9);
    insert_node(10);

    delete_node(10);

    print_list();

    return 0;
}

void print_list() {
    struct Node *temp = head;
    printf("List: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void insert_node(int data) {
    struct Node *new = malloc(sizeof(struct Node));
    new->value = data;
    new->next = NULL;

    if (size == 0) {
        head = new;
        tail = new;
        size++;
    } else {
        tail->next = new;
        tail = new;
        size++;
    }
}

int delete_node(int key) {
    if (size == 0) {
        return -1;
    } else if (size == 1) {
        head->next = NULL;
        free(tail);
        tail = head;
        size--;
    } else {
        struct Node *temp = head;
        struct Node *parent = head;
        while (temp->value != key && temp->next != NULL) {
            parent = temp;
            temp = temp->next;
        }
        if (temp->value != key) {
            return -1;
        }
        if (temp == head) {
            head = temp->next;
        } else if (temp->next != NULL) {
            parent->next = temp->next;
        } else {
            tail = parent;
            parent->next = NULL;
        }
        free(temp);
        size--;
    }
}

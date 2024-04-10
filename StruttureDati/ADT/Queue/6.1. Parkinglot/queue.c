#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "queue.h"
#define ERROR_MEMORY_ALLOCATION -1

struct _node {
    int data;
    struct _node* next;
};

struct _queue {
    struct _node* head;
    struct _node* tail;
};

queue queue_new() {
    struct _queue* q = (struct _queue*)malloc(sizeof(struct _queue));
    if (q != NULL) {
        q->head = NULL;
        q->tail = NULL;
    }

    return q;
}

void queue_destroy_rec (struct _node* node) {
    if (node == NULL)
        return;

    queue_destroy_rec(node->next);
    free(node->data);
    free(node);
}
void queue_destroy(queue q) {
    queue_destroy_rec (q->head);
    free(q);
}

int queue_add(queue q, int value) {
    struct _node* new = (struct _node*)malloc(sizeof(struct _node));
    if (new == NULL)
        return ERROR_MEMORY_ALLOCATION;
    
    new->data = (char*)malloc(sizeof(char) * strlen(value) + 1);
    strcpy(new->data, value);
    new->next = NULL;
    if (q->head == NULL)
        q->head = new;
    else
        q->tail->next = new;
    q->tail = new;

    return 0;
}

int queue_peek(queue q, int* result) {
    if (queue_is_empty(q)) {
        return ERROR_MEMORY_ALLOCATION;
    }

    *result = q->head->data;
    return 0;
}

int queue_poll(queue q, int* result) {
    struct _node* current = q->head;
    if (current != NULL) {
        *result = q->head->data;
        q->head = q->head->next;
        free (current);
        
        if (q->head == NULL)
            q->tail = NULL;
        return 0;
    }
    return ERROR_MEMORY_ALLOCATION;
}

int queue_size_rec(struct _node* node) {
    if (node == NULL)
        return 0;
    
    return queue_size_rec(node->next) + 1;
}
int queue_size(queue q) {
    return queue_size_rec(q->head);
}

bool queue_is_empty(queue q) {
    return q->head == NULL;
}

void alt_printa(queue q) {
    struct _node* current = q->head;
    printf("{ ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("}\n");
}
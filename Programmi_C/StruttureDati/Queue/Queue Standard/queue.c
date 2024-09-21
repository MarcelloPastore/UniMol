#include <stdlib.h>
#include <string.h>
#include "queue.h"

struct _node {
    void *data;
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

void queue_destroy_rec(struct _node* node) {
    if (node == NULL)
        return;
    
    queue_destroy_rec(node->next);
    free(node);
}

void queue_destroy(queue q) {
    queue_destroy_rec(q->head);
    free(q);
}

int queue_add(queue q, void *value) {
    struct _node* node = (struct _node*)malloc(sizeof(struct _node));
    if (node == NULL)
        return -1;
    
    node->data = value;
    node->next = NULL;
    
    if (q->tail == NULL)
        q->head = node;
    else
        q->tail->next = node;
    
    q->tail = node;
    return 0;
}

int queue_peek(queue q, void **result) {
    if (q->head == NULL)
        return -1;
    
    *result = q->head->data;
    return 0;
}

int queue_poll(queue q, void **result) {
    if (q->head == NULL)
        return -1;
    
    *result = q->head->data;
    struct _node* to_remove = q->head;
    q->head = q->head->next;
    free(to_remove);
    if (q->head == NULL)
        q->tail = NULL;
    
    return 0;
}

int queue_size_rec(struct _node* node) {
    if (node == NULL)
        return 0;
    
    return 1 + queue_size_rec(node->next);
}

int queue_size(queue q) {
    return queue_size_rec(q->head);
}

bool queue_is_empty(queue q) {
    return q->head == NULL;
}

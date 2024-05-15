#include <stdlib.h>
#include "stack.h"

struct _node {
    int data;
    struct _node *next;
};

struct _stack {
    struct _node *head;
};

// O(1)
stack stack_new() {
    struct _stack *s = (struct _stack*)malloc(sizeof(struct _stack));
    
    if (s != NULL) {
        s->head = NULL;
    }
    
    return s;
}

void stack_destroy_rec(struct _node *node) {
    if (node == NULL)
        return;
    
    stack_destroy_rec(node->next);
    free(node);
}

// O(N)
void stack_destroy(stack s) {
    stack_destroy_rec(s->head);
    free(s);
}

// O(1)
int stack_push(stack s, int value) {
    struct _node *node = (struct _node*)malloc(sizeof(struct _node));
    
    if (node == NULL)
        return -1;
    
    node->next = s->head;
    node->data = value;
    
    s->head = node;
    return 0;
}

// O(1)
int stack_peek(stack s, int *result) {
    if (stack_is_empty(s))
        return -1;
    
    *result = s->head->data;
    return 0;
}

// O(1)
int stack_pop(stack s, int *result) {
    struct _node *node = s->head;
    
    if (node == NULL)
        return -1;
    
    *result = s->head->data;
    s->head = node->next;
    free(node);
    return 0;
}

int stack_size_rec(struct _node* node) {
    if (node == NULL)
        return 0;
    
    return stack_size_rec(node->next) + 1;
}

// O(N)
int stack_size(stack s) {
    return stack_size_rec(s->head);
}

// O(1)
bool stack_is_empty(stack s) {
    return (s->head == NULL);
}

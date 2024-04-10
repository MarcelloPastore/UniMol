#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#define ERROR_MEMORY_ALLOCATION -1

struct _node {
    int data;
    struct _node* next;
};

struct _stack {
    struct _node* head;
};

stack stack_new() {
    struct _stack* s = (struct _stack*)malloc(sizeof(struct _stack));
    if (s != NULL) {
        s->head = NULL;
    }

    return s;
}

void stack_destroy_rec (struct _node* node) {
    if (node == NULL)
        return;

    stack_destroy_rec(node->next);
    free(node);
}
void stack_destroy(stack s) {
    stack_destroy_rec (s->head);
    free(s);
}

int stack_push(stack s, int value) {
    struct _node* new = (struct _node*)malloc(sizeof(struct _node));
    if (new == NULL)
        return ERROR_MEMORY_ALLOCATION;
    
    new->data = value;
    new->next = s->head;
    s->head = new;

    return 0;
}

int stack_peek(stack s, int* result) {
    if (stack_is_empty(s)) {
        return ERROR_MEMORY_ALLOCATION;
    }

    *result = s->head->data;
    return 0;
}

int stack_pop(stack s, int* result) {
    struct _node* current = s->head;
    if (current != NULL) {
        *result = s->head->data;
        s->head = s->head->next;
        free (current);
        return 0;
    }
    return ERROR_MEMORY_ALLOCATION;
}

int stack_size_rec(struct _node* node) {
    if (node == NULL)
        return 0;
    
    return stack_size_rec(node->next) + 1;
}
int stack_size(stack s) {
    return stack_size_rec(s->head);
}

bool stack_is_empty(stack s) {
    return s->head == NULL;
}

void printa(stack s) {
    struct _node* current = s->head;
    printf("{ ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("}\n");
}
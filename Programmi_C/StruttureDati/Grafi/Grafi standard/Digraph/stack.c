#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

// ! Definiamo la struttura della pila
struct _node {
    int data;
    struct _node *next;
};
struct _stack{
    struct _node *head;
};
// ! Definiamo le funzioni essenziali della pila
// * Creazione di una nuova pila  * O(1)
stack stack_new(){
    struct _stack* s = (struct _stack*)malloc(sizeof(struct _stack));

    if(s!=NULL){
        s->head = NULL;
    }
    return s;
}
// * Distruzione della memoria della pila *
void stack_destroy_rec(struct _node* node){
    if (node == NULL)
        return;
    stack_destroy_rec(node->next);
    free(node);
}
// * O(N) *
void stack_destroy(stack s){
    stack_destroy_rec(s->head);
    free(s);
}
// * Creiamo un nuovo elemento della pila e lo mettiamo in cima * O(1) *
int stack_push(stack s, int value){
    // allocare la memoria per il nodo
    struct _node* node = (struct _node*)malloc(sizeof(struct _node));
    if (node == NULL)
        return -1;

    node->next = s->head;
    node->data = value;
    s->head = node;
    
    return 0;
}
// * Ritorniamo l'elemento in cima * O(1) *
int stack_peek(stack s, int *result){
    if (s->head == NULL){
        return -1;
    }
    *result = s->head->data;
    return 0;
}
// * Ritorniamo l'elemento in cima e lo togliamo * O(1) *
int stack_pop(stack s, int *result){
    struct _node *node = s->head;
    if (node == NULL)
        return -1;
       
    *result = s->head->data;
    s->head = node->next;
    free(node);
    return 0;
}
// * Controlliamo la dimensione della pila * O(N) *
int node_rec(struct _node *node){
    if (node == NULL)
        return 0;
    return 1 + node_rec(node->next);
}   
int stack_size(stack s){
    return node_rec(s->head);
}
// * Verifichiamo se la pila è vuota o meno * O(1)*
bool stack_is_empty(stack s){
    return s->head == NULL;
};
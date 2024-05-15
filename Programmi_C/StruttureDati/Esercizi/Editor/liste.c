/*---------------------------------------------------------
    COME USARE LE LISTE !
---------------------------------------------------------*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

#define ERROR_STRUCT_NULL -1


// Mi creo la struttura dei nodi e delle liste
struct _node {
    int data; 
    struct _node* next;
};
struct _list {
    struct _node* first;
};
struct _iterator {
    struct _node* current;
    list source_list;
};


// mi creo la lista vuota
list list_new(){
    struct _list* l = (struct _list*)malloc(sizeof(struct _list));
    if (l != NULL){
        l->first = NULL;
    }
    return l;
}
// funzione che libera la memoria della lista e dei nodi
void list_destroy_rec(struct _node* node){
    if (node == NULL)
        return;

    list_destroy_rec(node->next);
    free(node);
    
}   
void list_destroy(list l){
     list_destroy_rec(l->first);
     free(l);
}

void print_list(list a) {
    struct _node* current = a->first;
    printf("[ ");
    while (current != NULL){
        printf("%d, ", current->data);
        current = current->next;
    }
    printf("]\n");
}
/* 
Tempo di esecuzione = C1 + C2 (se N = 0)
                oppure
Tempo di esecuzione = C1 + C3 * N (se N != 0) [il tempo dipende da N, O(N)]
*/
// funzione che mi aggiunge un elemento alla fine della lista
int list_append(list a, int value){
    struct _node* node = (struct _node*)malloc(sizeof(struct _node));
    if (node == NULL)
        return ERROR_STRUCT_NULL;

    node->data = value;
    node->next = NULL;
    if (a->first == NULL) {
        a->first = node;
    } else {
        struct _node* current = a->first;
        while (current ->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
    return 0;
}
// Tempo di esecuzione = C [tempo sempre costante, O(1)]
// funzione che mi aggiunge un elemento all'inizio della lista
int list_prepend(list a, int value){
    struct _node* node = (struct _node*)malloc(sizeof(struct _node));
    if (node == NULL)
        return ERROR_STRUCT_NULL;

    node->data = value;
    node->next = a->first;
    a->first = node;

    return 0;
}
// funzione che mi restituisce l'elemento iesimo
// tempo O(N)
int list_get_element_iter(list a, int i, int *result){

    struct _node* current = a->first;
    while (current != NULL && i > 0) {
        current = current->next;
        i--;
    }
    if (current == NULL) {
        return ERROR_STRUCT_NULL;
    }
    *result = current->data;
    return 0;
}

int list_get_element_rec(struct _node* node, int i, int *result){
    if (node == NULL) {
        return ERROR_STRUCT_NULL;
    }
    if (i == 0) {
        *result = node->data;
         return 0;
    }
    return list_get_element_rec(node->next, i-1, result);
}
int list_get_element(list a, int i, int *result){
    return list_get_element_rec(a->first, i, result);
}

// funzione che restituisce il primo elemento della lista
int list_get_first(list a, int *result){
    if (a == NULL) {
        return ERROR_STRUCT_NULL;
    } 
    *result = a->first->data;
    return 0;
}
// funzione che mi restituisce l'ultimo elemento della lista 
// Tempo O(N)
int list_get_last_iter(list a, int *result){
    if (a == NULL) {
        return ERROR_STRUCT_NULL;
    } 
    struct _node* current = a->first;
    while (current ->next != NULL) {
            current = current->next;
    }
    *result = current->data;
    return 0;
}
// get last versione ricorsiva
// Tempo O(N)
int list_get_last_rec(struct _node* node, int *result) {
    if (node == NULL) 
        return ERROR_STRUCT_NULL;
    if (node->next == NULL){
        *result = node->data;
        return 0;
    }
    
    return list_get_last_rec(node->next, result);
}
int list_get_last(list l, int *result){
return list_get_last_rec(l->first, result);
}
// funzione che controlla se la lista è vuota o meno
bool list_is_empty(list a){
    return a->first == NULL;
}
// funzione che restituisce il numero di elementi in una lista
// Tempo = O(N)
int list_size_iter(list a){
    int counter = 0;
    struct _node* current = a->first;
    while (current != NULL) {
            current = current->next;
            counter++;
    }
    return counter;
}
//Tempo O(N)
int node_rec(struct _node* n) {
    if (n == NULL) {
        return 0;
    }
    return 1 + node_rec(n->next);
}
int list_size(list a){
    return node_rec(a->first);
}
// Tempo O(N)
bool list_remove_first_value(list l, int value){
    struct _node* current = l->first;
    struct _node* node;
    if (l->first == NULL){
        return false;
    }
    if(l->first->data == value) {
        l->first=current->next;
        free(current);
        return true;
    }

    while (current->next->data != value && current->next != NULL)
    {
        current=current->next;
    }
    node = current->next;
    current->next=current->next->next;
    free(node);
    return true;
}

void remove_duplicates(list l){
    if (l->first == NULL){
        return;
    }if (l->first->next == NULL){
        return;
    }
    int value = l->first->data;
    list subList = list_new(); 
    subList->first = l->first->next;
    list_remove_all_values(subList, value);
    l->first->next = subList->first;
    remove_duplicates(subList);
    free(subList);

}

bool list_remove_all_values(list l, int value){
    if (l->first == NULL){
        return false;
    }
    bool flag;

    while(l->first->data == value) {
        struct _node* to_remove = l->first;
        l->first=l->first->next;
        free(to_remove);
        flag = true;

        if (l->first == NULL){
            return true;
        }
    }
    
    
    struct _node* previus = l->first;
    struct _node* current = previus->next;

    while(current != NULL){
        if (current->data == value)
        {       
            previus->next = current->next;
            free(current);
            flag = true;
        }else{
        previus = current;
        }
        current = previus->next;
    }

    return flag;
}
// ------------------------------------------
// ---------------ITERATION------------------
// ------------------------------------------
iterator list_iterate(list l){
    struct _iterator* iter = (struct _iterator*)malloc(sizeof(struct _iterator));  

    if (iter != NULL) {
        iter->source_list = l;
        iter->current = l->first;
    }   

    return iter;
}
bool iterator_has_next(iterator iter){
    return iter->current != NULL;
    
}
int iterator_next(iterator iter){
        int result = iter->current->data;
        iter->current = iter->current->next;
        return result;
}
void iterator_destroy(iterator iter){
    free(iter);
}

/*-----------------------------------------------------
------------------------THE END------------------------
-----------------------------------------------------*/
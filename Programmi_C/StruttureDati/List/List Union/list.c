#include <stdlib.h>
#include <string.h>
#include "list.h"

#define COMPARE_LISTELEMENT(type, x, y) (type == TYPE_CHAR && x.cval == y.cval) ||\
        (type == TYPE_INT && x.ival == y.ival) ||\
        (type == TYPE_FLOAT && x.fval == y.fval) ||\
        (type == TYPE_POINTER && x.pval == y.pval) ||\
        (type == TYPE_STRING && strcmp(x.sval, y.sval) == 0)

struct _node {
    listelement data;
    struct _node* next;
};

struct _list {
    struct _node* first;
    listtype type;
};

struct _iterator {
    struct _node* current;
    list source_list;
};


list list_new(listtype type) {
    struct _list* l = (struct _list*)malloc(sizeof(struct _list));
    
    if (l != NULL) {
        l->first = NULL;
        l->type = type;
    }
    
    return l;
}

void list_destroy_rec(struct _node* node, listtype type) {
    if (node == NULL)
        return;
    
    list_destroy_rec(node->next, type);
    if (type == TYPE_STRING) {
        free(node->data.sval);
    }
    free(node);
}

void list_destroy(list l) {
    list_destroy_rec(l->first, l->type);
    free(l);
}

// Tempo = O(N)
int list_append(list l, listelement value) {
    struct _node* node = (struct _node*)malloc(sizeof(struct _node));
    if (node == NULL)
        return -1;
    
    if (l->type != TYPE_STRING) {
        node->data = value;
    } else {
        char* new_string = (char*)malloc(strlen(value.sval) + 1);
        strcpy(new_string, value.sval);
        node->data.sval = new_string;
    }
    
    node->next = NULL;
    
    if (l->first == NULL) {
        l->first = node;
    } else {
        struct _node* current = l->first;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
    
    return 0;
}

// Tempo = O(1)
int list_prepend(list l, listelement value) {
    struct _node* node = (struct _node*)malloc(sizeof(struct _node));
    if (node == NULL)
        return -1;
    
    if (l->type != TYPE_STRING) {
        node->data = value;
    } else {
        char* new_string = (char*)malloc(strlen(value.sval) + 1);
        strcpy(new_string, value.sval);
        node->data.sval = new_string;
    }
    
    node->next = l->first;
    l->first = node;
    
    return 0;
}

// Tempo = O(N)
int list_size_iter(list l) {
    int size = 0;
    struct _node* current = l->first;
    while (current != NULL) {
        current = current->next;
        size++;
    }
    
    return size;
}

// Tempo = O(N)
int list_size_rec(struct _node* node) {
    if (node == NULL)
        return 0;
    
    return list_size_rec(node->next) + 1;
}

int list_size(list l) {
    return list_size_rec(l->first);
}

// Tempo = O(N)
int list_get_last_iter(list l, listelement *result) {
    struct _node* current = l->first;
    if (current == NULL) {
        return -1;
    }
    
    while (current->next != NULL) {
        current = current->next;
    }
    
    *result = current->data;
    
    return 0;
}

// Tempo = O(N)
int list_get_last_rec(struct _node* node, listelement *result) {
    if (node == NULL)
        return -1;
    
    if (node->next == NULL) {
        *result = node->data;
        return 0;
    }
    
    return list_get_last_rec(node->next, result);
}

int list_get_last(list l, listelement *result) {
    return list_get_last_rec(l->first, result);
}

// Tempo = O(N)
int list_get_element_iter(list l, int i, listelement *result) {
    if (i < 0)
        return -1;
    
    struct _node* current = l->first;
    
    while (current != NULL && i > 0) {
        current = current->next;
        i--;
    }
    
    if (current == NULL)
        return -1;
    
    *result = current->data;
    return 0;    
}

// Tempo = O(N)
int list_get_element_rec(struct _node* node, int i, listelement *result) {
    if (node == NULL || i < 0)
        return -1;
    
    if (i == 0) {
        *result = node->data;
        return 0;
    }
    
    return list_get_element_rec(node->next, i - 1, result);
}

int list_get_element(list l, int i, listelement *result) {
    return list_get_element_rec(l->first, i, result);
}

// Tempo = O(1)
int list_get_first(list l, listelement *result) {
    if (l->first == NULL)
        return -1;
    
    *result = l->first->data;
    return 0;
}

// Tempo = O(1)
bool list_is_empty(list l) {
    return (l->first == NULL);
}

// Tempo = O(N)
bool list_remove_first_value(list l, listelement value) {
    if (l->first == NULL)
        return false;
    
    if (COMPARE_LISTELEMENT(l->type, l->first->data, value)) {
        struct _node* to_remove = l->first;
        l->first = l->first->next;
        if (l->type == TYPE_STRING) {
            free(to_remove->data.sval);
        }
        free(to_remove);
        return true;
    }
    
    struct _node* previous = l->first;
    struct _node* current = previous->next;
    
    while (current != NULL) {
        if (COMPARE_LISTELEMENT(l->type, current->data, value)) {
            previous->next = current->next;
            free(current);
            return true;
        }
        previous = current;
        current = previous->next;
    }
    
    return false;
}

// Tempo = O(N)
bool list_remove_all_values(list l, listelement value) {
    if (l->first == NULL)
        return false;
    
    bool result = false;
    
    while (COMPARE_LISTELEMENT(l->type, l->first->data, value)) {
        struct _node* to_remove = l->first;
        l->first = l->first->next;
        free(to_remove);
        result = true;
        
        if (l->first == NULL) {
            return true;
        }
    }
    
    struct _node* previous = l->first;
    struct _node* current = previous->next;
    
    while (current != NULL) {
        if (COMPARE_LISTELEMENT(l->type, current->data, value)) {
            previous->next = current->next;
            free(current);
            result = true;
        } else {
            previous = current;
        }
        current = previous->next;
    }
    
    return result;
}

// TODO DA AGGIORNARE CON LISTELEMENT!
bool list_filter(list l, bool (*predicate)(listelement)) {
    if (l->first == NULL)
        return false;
    
    bool result = false;
    
    while (predicate(l->first->data)) {
        struct _node* to_remove = l->first;
        l->first = l->first->next;
        free(to_remove);
        result = true;
        
        if (l->first == NULL) {
            return true;
        }
    }
    
    struct _node* previous = l->first;
    struct _node* current = previous->next;
    
    while (current != NULL) {
        if (predicate(current->data)) {
            previous->next = current->next;
            free(current);
            result = true;
        } else {
            previous = current;
        }
        current = previous->next;
    }
    
    return result;
}

// TODO DA AGGIORNARE CON LISTELEMENT!
void list_remove_duplicates(list l) {
    if (l->first == NULL)
        return;
    
    if (l->first->next == NULL)
        return;
    
    listelement value = l->first->data;
    
    list sublist = list_new(l->type);
    sublist->first = l->first->next;
    list_remove_all_values(sublist, value);
    l->first->next = sublist->first;
    list_remove_duplicates(sublist);
    free(sublist);
}

iterator list_iterate(list l) {
    struct _iterator* iter = (struct _iterator*)malloc(sizeof(struct _iterator));
    
    if (iter != NULL) {
        iter->source_list = l;
        iter->current = l->first;
    }
    
    return iter;
}

bool iterator_has_next(iterator iter) {
    return iter->current != NULL;
}

// TODO DA AGGIORNARE CON LISTELEMENT!
listelement iterator_next(iterator iter) {
    listelement result = iter->current->data;
    iter->current = iter->current->next;
    return result;
}

void iterator_destroy(iterator iter) {
    free(iter);
}

// TODO DA AGGIORNARE CON LISTELEMENT!
void list_foreach(list l, void (*f)(listelement)) {
    struct _node* current = l->first;
    while (current != NULL) {
        f(current->data);
        current = current->next;
    }
}

// TODO DA AGGIORNARE CON LISTELEMENT!
listelement list_reduce(list l, listelement initial_value, listelement (*f)(listelement, listelement)) {
    listelement partial_total = initial_value;
    
    struct _node* current = l->first;
    while (current != NULL) {
        partial_total = f(partial_total, current->data);
        current = current->next;
    }
    
    return partial_total;
}

#include <stdbool.h>

typedef union _listelement {
    char cval;
    int ival;
    float fval;

    void* pval;
    char* sval;
} listelement;

typedef char listype;

#define TYPE_CHAR 0
#define TYPE_INT 1
#define TYPE_FLOAT 2
#define TYPE_POINTER 3
#define TYPE_STRING 4

typedef struct _list* list;

typedef struct _iterator* iterator;

list list_new(listype type);

void print_list(list a);

void list_destroy(list a);

int list_append(list a, listelement value);

int list_prepend(list a, listelement value);

int list_get_element(list a, int i, listelement *result);

int list_get_first(list a, listelement *result);

int list_get_last(list a, listelement *result);

bool list_filter(list l, bool (*predicate)(listelement));

void list_foreach(list l, void (*f)(listelement));

int list_reduce(list l, listelement initial_value, int (*f)(listelement));

bool list_is_empty(list a);

int list_size(list a);

int list_size_rec(list a);

bool list_remove_first_value(list l, int value);

bool list_remove_all_values(list l, int value);

iterator list_iterate(list l);

bool iterator_has_next(iterator iter);

int iterator_next(iterator iter);

void iterator_destroy(iterator iter);

void remove_duplicates(list l);


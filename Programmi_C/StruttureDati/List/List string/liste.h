#include <stdbool.h>

typedef struct _list* list;

typedef struct _iterator* iterator;

list list_new();

void print_list(list a);

void list_destroy(list a);

int list_append(list a, int value);

int list_prepend(list a, int value);

int list_get_element(list a, int i, int *result);

int list_get_first(list a, int *result);

int list_get_last(list a, int *result);

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


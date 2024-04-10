#include "dynarray.h"
#include <stdlib.h>
#include <stdio.h>
#define MAX_DYNARRAY_SIZE 2

struct _dynarray {
    int* values;
    int psize;
    int size;
};

dynarray dynarray_new () {
    struct _dynarray* x = (struct _dynarray*)malloc(sizeof(struct _dynarray));
    if (x != NULL) {
        x->values = (int*)calloc(MAX_DYNARRAY_SIZE, sizeof(int));
        x->size = 0;
        x->psize = MAX_DYNARRAY_SIZE;
    }

    return x;
}

void dynarray_destroy(dynarray x) {
    if (x != NULL) {
        free(x->values);
        free(x);
    }
}

int dynarray_add_element (dynarray a, int element) {
    if (a->size == a->psize) {
        a->psize = a->psize * 2;
        a->values = (int*)realloc(a->values, a->psize * sizeof(int));
        if (a->values == NULL) {
            return ERROR_FULL_DYNARRAY;
        }
    }

    a->values[a->size] = element;
    a->size++;
    return 0;
}

void dynarray_clear (dynarray a) {
    a->size = 0;
}

int dynarray_get_element (dynarray a, int i, int* result) {
    if (i >= 0 && i < a->size) {
        *result = a->values[i];
        return 0;
    } else {
        return ERROR_INVALID_INDEX;
    }
}

int dynarray_set_element (dynarray a, int i, int value) {
    if (i >= 0 && i < a->size) {
        a->values[i] = value;
        return 0;
    } else {
        return ERROR_INVALID_INDEX;
    }
}

int dynarray_size (dynarray a) {
    return a->size;
}

void dynarray_print (dynarray a) {
    printf("{ ");
    for (int i=0; i < a->size; i++) {
        printf("%d ", a->values[i]);
    }
    printf("}");
}
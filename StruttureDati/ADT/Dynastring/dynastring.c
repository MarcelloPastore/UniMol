#include "dynastring.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_DYNASTRING_SIZE 2

struct _dynastring {
    char** values;
    int psize;
    int size;
};

dynastring dynastring_new () {
    struct _dynastring* x = (struct _dynastring*)malloc(sizeof(struct _dynastring));
    if (x != NULL) {
        x->values = (char**)calloc(MAX_DYNASTRING_SIZE, sizeof(char*));
        x->psize = MAX_DYNASTRING_SIZE;
        x->size = 0;
    }

    return x;
}

void dynastring_destroy(dynastring x) {
    if (x != NULL) {
        for (int i=0; i<x->size; i++) {
            free (x->values[i]);
        }
        free(x->values);
        free(x);
    }
}

int dynastring_add_element (dynastring a, char* element) {
    if (a->size == a->psize) {
        a->psize = a->psize * 2;
        a->values = (char**)realloc(a->values, a->psize * sizeof(char*));
        if (a->values == NULL) {
            return ERROR_FULL_DYNARRAY;
        }
    }

    int lenght = strlen(element);
    char* new_string = (char*)malloc(sizeof(char) * lenght + 1);
    strcpy(new_string, element);

    a->values[a->size] = new_string;
    a->size++;
    return 0;
}

void dynastring_clear (dynastring a) {
    a->size = 0;
}

int dynastring_set_element (dynastring a, int i, char* value) {
    if (i >= 0 && i < a->size) {
        int lenght = strlen(value);
        char* new_string = (char*)malloc(sizeof(char) * lenght + 1);
        strcpy(new_string, value);
        free(a->values[i]);

        a->values[i] = new_string;
        return 0;
    } else {
        return ERROR_INVALID_INDEX;
    }
}

void dynastring_remove_element (dynastring a, int i) {
    a->values[i] = "\0";

    if (a->size == a->psize/4) {
        a->values = (char**)realloc(a->values, (a->psize/2) * sizeof(char*));
    }
}

int dynastring_size (dynastring a) {
    return a->size;
}

void dynastring_print (dynastring a) {
    printf("{\n");
    for (int i=0; i < a->size; i++) {
        printf("%s\n", a->values[i]);
    }
    printf("}");
}


#include <stdio.h>
#include <stdlib.h>
#include "gestione.h"
#define ERROR_INVALID_INDEX 1

struct _gestione {
    int* nums;
    int size;
};

gestione new_array (int n) {
    struct _gestione* a = (struct _gestione*)malloc(sizeof(struct _gestione));
    if (a != NULL) {
        a->nums = (int*)calloc(n, sizeof(int));
        a->size = n;
    }

    return a;
}

void destroy_array (gestione a) {
    if (a != NULL) {
        free (a->nums);
        free (a);
    }
}

int set_element (gestione a, int i, int element) {
    a->nums[i] = element;
}

int get_element (gestione a, int i, int *result) {
    if (i >= 0 && i < a->size) {
        *result = a->nums[i];
        return 0;
    } else {
        return ERROR_INVALID_INDEX;
    }
}

int size_array (gestione a) {
    return a->size;
}

gestione copy_array (gestione a) {
    gestione x = new_array(a->size);
    if (x != NULL) {
        x->nums = (int*)malloc(a->size * sizeof(int));
        for (int i=0; i<a->size; i++) {
            x->nums[i] = a->nums[i];
        }
    }
    return x;
}

int compare_array (gestione a, gestione b) {
    if (a->size != b->size) {
        return 0;
    }

    for (int i=0; i<a->size; i++) {
            if (a->nums[i] != b->nums[i]) {
                return 0;
            }
    }
    return 1;
}

void rotate_array (gestione a) {
    int temp = a->nums[a->size-1];
    for (int i=a->size-1; i>0; i--) {
        a->nums[i] = a->nums[i-1];
    }
    a->nums[0] = temp;
}

float media_array (gestione a) {
    int somma = 0;
    for (int i=0; i<a->size; i++) {
        somma += a->nums[i];
    }
    float media = (float) somma/(a->size); 

    return media;
}

void resize_array (gestione a, int new_size) {
    a->size = new_size;
}

void array_print (gestione a) {
    printf("{ ");
    for (int i=0; i < a->size; i++) {
        printf("%d ", a->nums[i]);
    }
    printf("}\n");
}
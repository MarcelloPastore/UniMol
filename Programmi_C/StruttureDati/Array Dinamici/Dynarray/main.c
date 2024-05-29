#include <stdio.h>
#include "dynarray.h"

int main () {
    dynarray x = dynarray_new();
    if (x == NULL) {
        printf("Errore: Memoria insufficiente.");
        return -1;
    }

    int answer;
    do {
        printf("Inserisci un valore oppure -1 per uscire: ");
        scanf("%d", &answer);
        if (answer != -1)
            dynarray_add_element(x, answer);
    } while (answer != -1);

    dynarray_print (x);
    dynarray_destroy (x);
}


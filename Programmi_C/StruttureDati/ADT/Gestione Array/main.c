#include <stdio.h>
#include "gestione.h"

int main () {
    int size;

    //Creo l'array e la richiesta della size
    printf("Seleziona la grandezza dell'array: ");
    scanf("%d", &size);

    //Creazione array
    gestione x = new_array(size);
    if (x == NULL) {
        printf("Errore: Memoria insufficiente.");
        return -1;
    }
    array_print (x);

    //Inserimento valori array
    int answer;
    do {
        printf("Inserisci la posizione [0 - %d] oppure -1 per uscire: ", size_array(x)-1);
        scanf("%d", &answer);
        if (answer != -1) {
            int element;
            printf("Che elemento vuoi inserire nella posizione %d? ", answer);
            scanf("%d", &element);
            set_element(x, answer, element);
        }
    } while (answer != -1);
    array_print (x);

    //Richiesta per rotazione array
    int risposta;
    printf("Vuoi ruotare l'array? [1/0]\n");
    scanf("%d", &risposta);
    //Funzione rotazione array
    if (risposta) {
        rotate_array(x);
        array_print (x);
    }

    //Media valori dell'array
    printf("Media: %.2f", media_array(x));
    //Liberazione memoria
    destroy_array (x);

    return 0;
}
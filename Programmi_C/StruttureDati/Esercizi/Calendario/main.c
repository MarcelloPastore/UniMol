#include <stdio.h>
#include "calendario.h"
#define EDIT 1
#define ADD 2
#define SUBTRACT 3
#define EXIT 0


int main () {
    int scelta, giorno, mese, anno;

    calendario data = nuova_data();
    do {
        printf("Seleziona un'operazione: ");
        scanf("%d", &scelta);
        switch (scelta) {
            case 1:
                printf ("-- Imposta la data --\nDammi il giorno: ");
                scanf("%d", &giorno);
                printf ("Dammi il mese: ");
                scanf("%d", &mese);
                printf ("Dammi l'anno: ");
                scanf("%d", &anno);
                set_data (data, giorno, mese, anno);
                break;
            case 2:
                printf("Quanti giorni vuoi sommare? ");
                scanf("%d", &giorno);
                somma_giorni (data, giorno);
                break;
            case 3:
                printf("Quanti giorni vuoi sottrarre? ");
                scanf("%d", &giorno);
                differenza_giorni (data, giorno);

                break;
            case 0:
                break;
            default:
                printf("Scelta errata.");
        }
    } while (scelta != 0);
}
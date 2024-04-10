#include <stdio.h>

#define DIM 5

#define STAMPA 1
#define MODIFICA 2
#define RICERCA 3
#define STATISTICHE 4
#define USCITA 0

int main()
{
    int numeri[DIM];
    int i, scelta, pos, max, min, somma, n;
    float media;

    // Carico l'array
    printf("Caricamento dati...\n");
    for (i = 0; i < DIM; i++) {
        printf("Dammi il valore dell'elemento %d: ", i+1);
        scanf("%d", &numeri[i]);
    }
    
    do {
        // Visualizzo il menù
        printf("%d. Stampa valori\n", STAMPA);
        printf("%d. Modifica valore\n", MODIFICA);
        printf("%d. Ricerca valore\n", RICERCA);
        printf("%d. Statistiche\n", STATISTICHE);
        printf("%d. Uscita\n", USCITA);
        printf("Scelta: ");
        scanf("%d", &scelta);
        
        // Avvio una specifica procedura in base alla scelta dell'utente
        switch (scelta) {
            case STAMPA:
                printf("Stampa dei valori...\n");
                for (i = 0; i < DIM; i++)
                    printf("Valore[%d] = %d\n", i, numeri[i]);
                break;
            case MODIFICA:
                printf("Modifica di un valore...\n");
                do {
                    printf("In che posizione si trova l'elemento da modificare?\n");
                    scanf("%d", &pos);
                    if (pos <= 0 || pos > DIM) {
                        printf ("Attento, hai inserito una posizione non valida. L'array ha %d elementi.\n", DIM);
                    }

                } while (pos <= 0 || pos > DIM);

                printf("Inserici il nuovo valore dell'elemento con indice %d: ", pos-1);
                scanf("%d", &numeri[pos-1]);
                printf("\n");
                break;
            case RICERCA:
                printf("Ricercando il valore...\n");
                    printf("Che valore vuoi ricercare nell'array?\n");
                    scanf("%d", &n);

                    i = 0;
                    while (i < DIM) {
                    if (numeri[i] == n) {
                        break;
                    }
                    i++;
                    }
                    
                    if (i == 5) {
                        printf("L'elemento %d non è presente nell'array.\n\n", n);
                    } else {
                        printf("L'elemento %d è presente nell'array con indice %d.\n\n", n, i);
                    }
                break;
            case STATISTICHE:
                printf("Elaborando le statistiche...\n");
                somma = 0;
                max = numeri[0];
                min = numeri[0];
                for (i = 0; i < DIM; i++) {
                    somma += numeri[i];
                    if (numeri[i] > max) {
                        max = numeri[i];
                    } else if (numeri[i] < min) {
                        min = numeri[i];
                    }
                }
                media = (float) somma / DIM;

                printf("La somma dei valori è %d\n", somma);
                printf("Il massimo è %d\n", max);
                printf("Il minimo è %d\n", min);
                printf("La media è %.1f\n\n", media);
                break;
            case USCITA:
                printf("Fine lavoro...\n");
                break;
            default:
                printf("Scelta errata.\n\n");
        }
    } while (scelta != USCITA);
}

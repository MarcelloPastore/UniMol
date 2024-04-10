#include <stdio.h>

#define DIM_NOME 50
#define DIM_VOTI 5
#define DIM 3
#define ADD 1
#define MEDIA 2
#define EXIT 0

typedef struct {
    char nome[DIM_NOME];
    int matricola;
    float voti[DIM_VOTI];
} Studente;

float media_studente (float *_array, float *_media) {
    for (int i=0; i<DIM_VOTI; i++) {
        *_media += _array[i];
    }
    *_media = (float) *_media/DIM_VOTI;
}

int main () {
    int size, k;
    float media = 0;
    Studente studente[DIM];
    studente.matricola = 0;

    do {
        printf("\n---------MENU---------\n\n");
        printf("%d. Aggiunta studente\n", ADD);
        printf("%d. Calcolo della media\n", MEDIA);
        printf("%d. Uscita\n\n", EXIT);
        printf("Inserisci la scelta: ");
        scanf("%d", &k);

        switch (k) {
            case ADD:
                ++studente.matricola;

                printf("Dammi il nome dello studente: ");
                scanf("%s", studente[studente.matricola].nome);

                for (int i=0; i<DIM_VOTI; ++i) {
                    printf("Dammi il voto #%d.", i+1);
                    scanf("%f", studente[studente.matricola].voti[i]);
                }
                break;
            case MEDIA:
                int i;
                printf("Inserisci la matricola dello studente da controllare: ");
                scanf("%d", &i);
                
                media_studente(studente[i].voti, &media);
                printf("La media dei voti dello studente insierito è: %.2f.", media);
                break;
            case EXIT:
            break;
            default:
                printf("Scelta errata.\n\n");
        }
    } while (k != 0);
}
#include <stdio.h>
#define ADD 1
#define VIEW 2
#define SEARCH 3
#define EDIT 4
#define EXIT 0

#define MAX_TAGLIA_NOMI 20
#define MAX_TAGLIA_NUMERO 11
#define MAX_CONTATTI 10

typedef struct {
    int progressivo;
    char nome[MAX_TAGLIA_NOMI];
    char cognome[MAX_TAGLIA_NOMI];
    char numero[MAX_TAGLIA_NUMERO];
} Contatto;

typedef struct {
    Contatto array_contatti[MAX_CONTATTI];
    int numero_contatti;
} Rubrica;


int main () {

    int scelta;
    Contatto contatto;
    Rubrica rubrica;
    rubrica.numero_contatti = 0;
    do {
        printf("|--------------------------|\n\n----------------------------\n------------MENU------------\n----------------------------\n");
        printf("%d. Aggiunta contatto\n", ADD);
        printf("%d. Visualizza contatti\n", VIEW);
        printf("%d. Ricerca contatto\n", SEARCH);
        printf("%d. Modifica contatto\n", EDIT);
        printf("%d. Uscita\n\n", EXIT);

        printf("Inserisci scelta: ");
        scanf("%d", &scelta);
        printf("|--------------------------|\n\n");

        switch (scelta) {
            case ADD:
                printf("Inserisci il nuovo contatto.\nDammi il nome: ");
                scanf("%s", contatto.nome);
                printf("Dammi il cognome: ");
                scanf("%s", contatto.cognome);
                printf("Dammi il numero: ");
                scanf("%s", contatto.numero);

                rubrica.numero_contatti++;
            break;
            case VIEW:
            break;
            case SEARCH:
            break;
            case EDIT:
            break;
            case EXIT:
            break;
            default:
                printf("Scelta non consentita.\n");
        }

    } while (scelta !=0);
}
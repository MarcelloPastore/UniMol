#include "rubrica.h"
#include <stdio.h>
#define ADD 1
#define VIEW 2
#define SEARCH 3
#define EDIT 4
#define EXIT 0

int main () {
    int scelta;
    char* nome;
    char* cognome;
    char* numero;
    char* cognome_old;
    rubrica rubrica;
    contatto contatto;
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
                scanf("%s", nome);
                printf("Dammi il cognome: ");
                scanf("%s", cognome);
                printf("Dammi il numero: ");
                scanf("%s", numero);

                int result = add_contact (contatto, rubrica, nome, cognome, numero);
                if (result != ERROR_FULL_RUBRICA) {
                    printf("Il contatto è stato aggiunto con successo!");
                } else {
                    printf("Errore! Rubrica piena!");
                }
            break;
            case VIEW:
                view_contacts (contatto, rubrica);
            break;
            case SEARCH:
                printf("Dammi il cognome del contatto da ricercare: ");
                scanf("%s", cognome);

                char* risultato = search_contact (contatto, rubrica, cognome);
                if (risultato == NULL) {
                    printf("Errore! Contatto non trovato!");
                } else {
                    printf("%s", risultato);
                }
            break;
            case EDIT:
                printf("Inserisci il cognome del contatto da modificare:" );
                printf("%s", cognome_old);

                printf("Dammi il nuovo nome: ");
                scanf("%s", nome);
                printf("Dammi il nuovo cognome: ");
                scanf("%s", cognome);
                printf("Dammi il nuovo numero: ");
                scanf("%s", numero);

                edit_contact (contatto, rubrica, cognome_old, nome, cognome, numero);
            break;
            case EXIT:
            break;
            default:
                printf("Scelta non consentita.\n");
        }

    } while (scelta !=0);
}
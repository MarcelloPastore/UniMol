#include <stdio.h>
#include "dynastring.h"

int main () {
    dynastring x = dynastring_new();
    if (x == NULL) {
        printf("Errore: Memoria insufficiente.");
        return -1;
    }

    char answer[100];
    do {
        printf("Inserisci una stringa oppure digita EXIT per uscire: ");
        scanf("%s", answer);
        if (answer != "EXIT")
            dynastring_add_element(x, answer);
    } while (answer != "EXIT");

    int ans;
    printf("Inserisci la posizione dell'elemento da rimuovere: ");
    scanf("%d", &ans);
    dynastring_remove_element(x, ans);


    dynastring_print (x);
    dynastring_destroy (x);
}
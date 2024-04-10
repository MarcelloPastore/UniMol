#include <stdio.h>
#define DIM 100
//Data una stringa in input, verificare se è presente un carattere

int main (){
    char stringa[DIM];
    char carattere;
    size_t i=0;

    printf("Dammi il carattere da ricercare: ");
    scanf("%c", &carattere);

    printf("Inserisci stringa: ");
    scanf("%s", stringa);

/*    for (size_t i=0; stringa[i] != '\0'; i++){
        if (stringa[i] == carattere){
            printf("Il carattere %c è presente nella stringa con indice %zu.", carattere, i);
            break;
            } 
    }*/

    while (stringa[i] != '\0') {
        if (stringa[i] == carattere) {
            printf("Il carattere %c è presente nella stringa con indice %zu.", carattere, i);
            break;
        }
    i++;
    }

    if (stringa[i] == '\0') {
        printf("Carattere non trovato.");
    }
}
#include <stdio.h>
#define MASSIMA_TAGLIA 100

int main(){
    char stringa[MASSIMA_TAGLIA];
    char copia[MASSIMA_TAGLIA];
    int i;

    printf("Inserisci stringa: ");
    scanf("%s", stringa);

    for (i=0; stringa[i] != '\0'; ++i){
        copia[i] = stringa[i];
    }
    copia[i] = '\0';

    printf("Copia: %s", copia);
}
#include <stdio.h>
#define MASSIMA_TAGLIA 100

int main(){
    char stringa[MASSIMA_TAGLIA];
    int i=0;

    printf("Inserisci stringa: ");
    scanf("%s", stringa);

    while (stringa[i] != '\0') {
        printf("[%d] %c\n", i, stringa[i]);
        i++;
    }

    printf("Lunghezza stringa: %d", i);
    
}
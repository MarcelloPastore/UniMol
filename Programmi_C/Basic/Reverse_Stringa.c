#include <stdio.h>
#define MASSIMA_TAGLIA 100

int main (){
    char stringa[MASSIMA_TAGLIA];
    char reverse[MASSIMA_TAGLIA];
    int i, j, x;

    printf("Inserisci stringa: ");
    scanf("%s", stringa);

    while (stringa[i] != '\0'){
        i++;
    }

    j = 0;
    x = i - 1;
    while (x >= 0){
        reverse[j] = stringa[x];
        j++;
        x--;
    }
    reverse[j] = '\0';

    printf("Il reverse della stringa è: %s", reverse);
}
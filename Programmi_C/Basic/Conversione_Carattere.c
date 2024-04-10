#include <stdio.h>

//65 - 90 _ 97 - 122; 

int main () {

    char a, carattere;

    do {
        printf("Dammi una lettera: ");
        scanf("%c", &a);

        if (!((a >= 65 && a <= 90) || (a >= 97 && a <= 122))) {
            printf("Non hai inserito una lettera.\n");
        }
    } while (!((a >= 65 && a <= 90) || (a >= 97 && a <= 122)));
 
    if (a < 97) {
        carattere = a + 32;
    } else {
        carattere = a - 32;
    }

    printf("La tua lettera con caps invertito è: %c.\n", carattere);
    printf("Codice Ascii: %d.", carattere);
}
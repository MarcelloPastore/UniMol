#include <stdio.h>

int main () {
    int carta;

    scanf("%d", &carta);

    switch (carta) {
        case 1:
            printf("Asso \n");
            break;
        case 8:
        case 9:
        case 10:
            printf("Figura \n");
            break;
        default:
            printf("%d \n", carta);
    printf("Ecco la tua carta! ...Bene...");
    }
}
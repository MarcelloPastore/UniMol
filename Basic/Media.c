#include <stdio.h>

int main() {
    int n, v, i, media;

    printf("Numero di voti: ");
    scanf("%d", &n);

    media = 0;
    i = 0;

    if (n < 0) {
        printf("Bastardo, non mettere numeri negativi!");
    } else {
        while (i < n) {
            printf("Voto: ");
            scanf("%d", &v);
            media += v;
            ++i;
        }

        media = media / n;

        printf("La media è %d.", media);
    }
}
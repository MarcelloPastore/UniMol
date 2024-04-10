#include <stdio.h>

int main() {
    int n, num, i, max;

    printf("Numeri da confrontare: ");
    scanf("%d", &n);

    i = 0;
    max = 0;

    if (n < 0) {
        printf("Bastardo, non mettere numeri negativi!");
    } else {
        while (i < n) {
            printf("Numero: ");
            scanf("%d", &num);
            if (i == 0) {
                max = num;
            }
            if (num > max) {
                max = num;
            }
            ++i;
        }

        printf("Il numero più grande è %d.", max);
    }
}
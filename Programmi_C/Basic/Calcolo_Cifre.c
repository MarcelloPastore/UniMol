#include <stdio.h>

int main() {

    int n, val, cifre;

    printf("Dammi il numero: ");
    scanf("%d", &n);

    val = n;
    cifre = 1;

    if (n < 0) {
        val = -n;
    }

    while (val >= 10) {
        val = val / 10;
        ++cifre;
    }

    printf("Il numero è composto da %d cifre.", cifre);
}
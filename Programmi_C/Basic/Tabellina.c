#include <stdio.h>

int main()
{
    /*Tabellina del n*/
    
    int base, i, n;

    printf("Dammi il numero di cui fare la tabellina: ");
    scanf("%d", &base);

    i = 1;
    n = base;

    while (i <= 10) {
        n = base * i;
        printf("%d\n", n);
        i++;
    }
}
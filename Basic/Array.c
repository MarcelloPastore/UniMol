#include <stdio.h>

#define DIM 5

int main()
{
    int numeri[DIM];
    int i;

    for (i = 0; i < DIM; i++) {
        printf("Dammi il valore dell'elemento %d: ", i+1);
        scanf("%d", &numeri[i]);
    }
    
    return 0;
}

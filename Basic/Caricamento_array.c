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

    printf("Il tuo array è composto dagli elementi: {");
    for (i = 0; i < DIM; i++) {
        printf("%d", numeri[i]);
        if (i < (DIM - 1)) {
            printf(", ");
        }
    }
    printf("}\n");

    printf("Che scritti al contrario sono: {");
    for (i = DIM-1; i >= 0; i--) {
        printf("%d", numeri[i]);
        if (i > 0) {
            printf(", ");
        }
    }
    printf("}");

    return 0;
}
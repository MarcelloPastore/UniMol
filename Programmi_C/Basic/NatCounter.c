#include <stdio.h>

int main() {
    
    int n, i;

    printf("Dammi il numero: ");
    scanf("%d", &n);

    i= 0;

    while (n >= i) {
        printf("%d ", i);
        ++i;
    }
}
#include <stdio.h>

int main () {

    int n, i = 2;
    
    printf("Dammi il numero: ");
    scanf("%d", &n);

    while ((i <= n/2)&&(n%i !=0)) {
        ++i;        
    }

    if ((n%i ==0)||(n <= 0)) {
        printf("Il numero non è primo.");
    } else {
        printf("Il numero è primo.");
    }
}
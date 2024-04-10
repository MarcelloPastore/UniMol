#include <stdio.h>

int main () {

    int B, b, h, area;

    printf("Dammi la base maggiore: ");
    scanf("%d", &B);

    printf("Dammi la base minore: ");
    scanf("%d", &b);
    
    printf("Dammi l'altezza: ");
    scanf("%d", &h);
    
    area = (B + b) * h / 2;

    printf("L'area è %d.", area);
}
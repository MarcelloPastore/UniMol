#include <stdio.h>

// Stampa triangolo rettangolo formato da asterischi, prendendo in input l'altezza
// Stampa triangolo equilatero formato da asterischi, prendendo in input l'altezza

int main (){
    int h;

    printf("Dammi l'altezza del triangolo: ");
    scanf("%d", &h);
    
    for (int i=0; i < h; i++) {
        for (int j=0; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    int num_spazi = h-1;
    int num_asterischi = 1;
    for (int i=0; i < h; i++){
        for (int j=0; j < num_spazi; j++){
            printf(" ");
        }
        for (int k=0; k < num_asterischi; k++){
            printf("*");
        }
        printf("\n");
        num_spazi--;
        num_asterischi += 2;
    }
}
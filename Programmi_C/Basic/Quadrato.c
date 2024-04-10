#include <stdio.h>

// Stampa quadrato formato da asterischi, prendendo in input il lato

int main (){
    int l;

    printf("Dammi il lato del quadrato: ");
    scanf("%d", &l);
    
    for (int i=0; i < l; i++){
        for (int j=0; j < l; j++){
            printf("* ");
        }
        printf("\n");
    }
}
#include <stdio.h>
#define DIM 5

int main(){

    int i=0;
    char nome[DIM]= "ROMA";

    printf("Stampa completa: %s\n", nome);
    printf("Stampa per carattere:\n"); 
    
    while (i < (DIM-1)) {
    printf("[%c]\n", nome[i]);
    ++i;
    }
}
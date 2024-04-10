#include <stdio.h>

int main(){

    char nome[20];
    printf("Inserisci il tuo nome e cognome: ");

    //Memorizzo variabili separate da uno spazio
    scanf("%[^\n]s", nome);
    printf("Stampa il valore inserito: %s", nome);
}
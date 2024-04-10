#include <stdio.h>

void spostaDisco(int n, char sorgente, char destinazione, char ausiliario) {
    if (n == 1) {
        printf("Sposta il disco 1 da %c a %c\n", sorgente, destinazione);
        return;
    }

    spostaDisco(n - 1, sorgente, ausiliario, destinazione);
    printf("Sposta il disco %d da %c a %c\n", n, sorgente, destinazione);
    spostaDisco(n - 1, ausiliario, destinazione, sorgente);
}

int main() {
    int numDischi = 104;  // Puoi impostare il numero di dischi desiderato
    char sorgente = 'A';
    char destinazione = 'C';
    char ausiliario = 'B';

    if (numDischi > 0)
        spostaDisco(numDischi, sorgente, destinazione, ausiliario);
}
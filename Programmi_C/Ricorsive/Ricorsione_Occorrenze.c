#include <stdio.h>
#include <stdlib.h>

/*
 * Scrivere una funzione ricorsiva in C che, dati in input
 * un array di interi numbers e un valore intero key,
 * calcola il numero di occorrenze di key in numbers.
 */

int count_occurrences(int *numbers, int size, int key) {
    if (size == 0) {
        return 0;
    }

    if (numbers[size - 1] == key) {
        return 1 + count_occurrences(numbers, size - 1, key);
    } else {
        return count_occurrences(numbers, size - 1, key);
    }
}

int main() {
    int size;
    int *numbers = (int *)malloc(size * sizeof(int));
    int key;

    printf("Inserisci il numero di elementi nell'array: ");
    scanf("%d", &size);

    if (numbers == NULL) {
        printf("Errore nell'allocazione di memoria.");
        return 1;
    }

    printf("Inserisci gli elementi dell'array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &numbers[i]);
    }

    printf("Inserisci la chiave: ");
    scanf("%d", &key);

    int occurrences = count_occurrences(numbers, size, key);

    printf("Il valore %d compare %d volte nell'array.\n", key, occurrences);

    return 0;
}


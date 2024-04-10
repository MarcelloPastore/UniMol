#include <stdio.h>

int coefficienteBinomiale(int n, int k) {
    if (k == 0 || k == n)
        return 1;
    else
        return coefficienteBinomiale(n - 1, k - 1) + coefficienteBinomiale(n - 1, k);
}

void stampaTriangoloPascal(int righe) {
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", coefficienteBinomiale(i, j));
        }
        printf("\n");
    }
}

int main() {
    int righe;
    printf("Inserisci il numero di righe per il triangolo di Pascal: ");
    scanf("%d", &righe);

    stampaTriangoloPascal(righe);
}
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// 1. Scrivi una funzione che prende in input una stringa e la restituisce invertita, non modificare l'input

// 2. Scrivi una funzione che ricerca un carattere in una stringa e restituisce la prima posizione in cui lo trova

// 3. Scrivi una funzione ricorsiva che, dati in input due interi n e k, restituisce il valore di n^k (n elevato a k)

// 4. Scrivi una funzione che prende in input un array di interi e
// restituisce 1 se è ordinato in modo crescente, 0 se è ordinato in modo descrescente, -1 se non è ordinato

// 5. Scrivi una funzione che prende in input una matrice di interi e restituisce la somma di ogni riga e colonna


//1.
char* inversione (char *_stringa) {

    int size = strlen(_stringa);

    char* copia = (char *) malloc(size * sizeof(char));
    strcpy(copia, _stringa);

    strrev(copia);

    return copia;
}

//2.
int ricerca_carattere (char _stringa[], char carattere) {
    int size = strlen(_stringa);
    int i, flag = 0;

    for (i=0; i<size-1; i++) {
        if (_stringa[i] == carattere) {
            flag = 1;
            break;
        }
    }

    if (flag == 1)
        return i;
    return -1;
}

//3.
int esp_ricorsiva (int _n, int _k) {
    if (_k == 0)
        return 1;

    return _n * esp_ricorsiva (_n, _k-1);
}

//4.
int ordinamento (int* _nums, int _size) {
    int contatore_cr = 0;
    int contatore_decr = 0;

    for (int i=0; i<_size; i++) {
        if (_nums[i]< _nums[i+1])
            contatore_cr++;
        if (_nums[i]> _nums[i+1])
            contatore_decr++;
    }

    if (contatore_cr == _size-1)
        return 1;
    if (contatore_decr == _size-1)
        return 0;
    return -1;
}

//5.
typedef struct {
    int righe[3];
    int colonne[3];
} Somma;

Somma somma_matrice (int _rows, int _cols, int _matrice[_rows][_cols]) {
    Somma somma;

    for (int i=0; i<_rows; i++){
        somma.righe[i] = 0;
        for (int j=0; j<_cols; j++){
            somma.righe[i] += _matrice[i][j];
        }
    }

    for (int i=0; i<_rows; i++){
        somma.colonne[i] = 0;
        for (int j=0; j<_cols; j++){
            somma.colonne[i] += _matrice[j][i];
        }
    }
    
    return somma;
}

int main () {

}
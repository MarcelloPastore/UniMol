#include <stdio.h>
#define DIM 4

typedef struct {
    int giorno;
    int mese;
    int anno;
} Data;

typedef struct {
    char nome[50];
    char cognome[50];
    Data compleanno;
} Persona;

typedef struct {
    int x;
    int y;
} Punto;

int main () {
    Punto p[DIM];

    for (int i = 0; i < DIM; i++) {
        printf("Dammi il valore della x del punto %d: ", i+1);
        scanf("%d", &p[i].x);
        printf("Dammi il valore della y del punto %d: ", i+1);
        scanf("%d", &p[i].y);
    }

    for (int i = 0; i < DIM; i++) {
        printf("(%d, %d)\n", p[i].x, p[i].y);
    }
}
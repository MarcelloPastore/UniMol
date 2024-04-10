#include <stdio.h>

// Calcolare area e perimetro di un triangolo usando le strutture
typedef struct {
    int lato_a;
    int base;
    int lato_c;
    int altezza;
    float area;
    int perimetro;
} Triangolo;


int main () {

    Triangolo struttura = {2, 5, 3, 3};

    struttura.perimetro = struttura.base + struttura.lato_a + struttura.lato_c;
    struttura.area = (float) struttura.base*struttura.altezza / 2;

    printf("Perimetro: %d\n", struttura.perimetro);
    printf("Area: %.2f", struttura.area);
}
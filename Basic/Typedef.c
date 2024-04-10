#include <stdio.h>

//Enum va fuori dal blocco di istruzioni
enum Color {RED, GREEN, BLUE};

int main() {

    struct Punto {
        int x;
        int y;
    };

    struct Punto punto1, punto2;
    punto1.x = 6;
    punto1.y = 7;

    typedef int intero;
    intero numero = 6;


//Typedef e struct possono essere mischiati, punto diventerà il nuovo data type
    typedef struct {
        int x;
        int y;
    } punto;

    punto punto1 = {6, 7};
}
#include <stdio.h>

/*Ex: 3x + 2y = 8; 6x - 4y = 8*/

int main () {

    int a, b, c, d, e, f;
    float Dx, Dy, D, x, y;

    printf("Prima equazione. Dammi la x: ");
    scanf("%d", &a);
    printf("Dammi la y: ");
    scanf("%d", &b);
    printf("Dammi il termine noto: ");
    scanf("%d", &c);

    if (b >= 0) {
        printf("La prima equazione del sistema è: %dx +%dy = %d.\n", a, b, c);
    } else {
        printf("La prima equazione del sistema è: %dx %dy = %d.\n", a, b, c);
    }

    printf("Seconda equazione. Dammi la x: ");
    scanf("%d", &d);
    printf("Dammi la y: ");
    scanf("%d", &e);
    printf("Dammi il termine noto: ");
    scanf("%d", &f);

    if (e >= 0) {
        printf("La seconda equazione del sistema è: %dx +%dy = %d.\n", d, e, f);
    } else {
        printf("La seconda equazione del sistema è: %dx %dy = %d.\n", d, e, f);
    }

    D = a * e - d * b;
    Dx = c * e - f * b;
    Dy = a * f - d * c;

    x = Dx / D;
    y = Dy / D;

    printf("I valori che risolvono il sistema sono x = %.2f, y = %.2f.", x, y);
}
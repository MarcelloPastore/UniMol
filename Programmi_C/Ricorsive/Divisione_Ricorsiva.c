#include <stdio.h>

int divisione_ricorsiva(int, int);

int main () {
    int a, b, red;

    printf("Dammi il numeratore: ");
    scanf("%d", &a);
    printf("Dammi il denominatore: ");
    scanf("%d", &b);

    printf("%d", divisione_ricorsiva(a, b));


}

int divisione_ricorsiva(int _num, int _den) {
    if (_num <= 0) {
	    return 0;
    } else {
	    return 1 + divisione_ricorsiva(_num - _den, _den);
    }
}
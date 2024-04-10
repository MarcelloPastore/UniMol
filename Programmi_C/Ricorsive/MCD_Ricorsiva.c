// Massimo comun divisore tra due interi (Eulero)

#include <stdio.h>

int massimo_comun_divisore (int a, int b) {
    if (a == b) {
        return b;
    }

    if (a>b) {
        return massimo_comun_divisore(a-b, b);
    }
    return massimo_comun_divisore(a, b-a);
}

int main () {
    int a = 18;
    int b = 9;
    
    printf("%d", massimo_comun_divisore(a, b));

}

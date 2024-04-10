// Crea una funzione ricorsiva che sommi solo le cifre prime di un dato numero. 
// Ad esempio, per 1234, la somma dovrebbe essere 2 + 3.

#include <stdio.h>

int somma_primi_ricorsiva (int _n) { //1245 , 124 5

    if (_n <= 0) 
        return 0;

    int somma = 0;
    int flag = 0;
    int resto = _n%10;

    for (int i=2; i<resto; i++) {
        if (resto%i == 0)
            flag = 1;
    }

    if (flag == 0) 
        somma += resto;

    return somma + somma_primi_ricorsiva(_n/10);
}

int main () {

    int n = 125593521;

    printf("%d", somma_primi_ricorsiva(n));
}
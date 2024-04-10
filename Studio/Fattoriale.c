#include <stdio.h>

long long int fattoriale (int n) {
    if (n == 0) {
        return 1;
    }

    return n * fattoriale (n-1);
}

int main () {
    int n = 19;

    printf("%lld", fattoriale(n));
}
#include <stdio.h>

void tabella (int n, int i, int j) {
    if (i <= n) {
        if (j <= n) {
            printf("%d ", i * j);
            tabella(n, i, j + 1);
        } else {
            printf("\n");
            tabella(n, i + 1, 1);
        }
    }
}

int main () {
    int n = 10;
    int i = 1;
    int j = 1;

    tabella(n, i, j);
}
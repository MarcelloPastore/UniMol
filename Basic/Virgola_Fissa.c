#include <stdio.h>
#define MAX_ARRAY 15

int main() {

    int n;
    int parte_int[MAX_ARRAY];
    float dec;

    printf("Inserisci il numero da trasformare in virgola mobile.\n");
    printf("Dammi la parte intera: ");
    scanf("%d", &n);

    printf("Dammi la parte decimale: ");
    scanf("%f", &dec);

    //Converto gli interi in binario
    int j=0;
    int i=0;
    while (n > 0) {
        parte_int[i] = n%2;
        n = n/2;
        i++;
        j++;
    }
    int size_int = j-1;

    //Converto i decimali in binario
    int parte_dec[MAX_ARRAY];
    int k=0;
    i=0;
    while (dec != 0 && i < MAX_ARRAY) {
        dec = dec*2;
        if (dec >= 1) {
            dec = (dec-1);
            parte_dec[i] = 1;
        } else {
            parte_dec[i] = 0;
        }
        k++;
        i++;
    }
    int size_dec = k;

    printf("Binario:\n");
    for (i=size_int; i>=0; i--)
        printf("%d", parte_int[i]);
    printf(",");
    for (i=0; i<size_dec; i++)
        printf("%d", parte_dec[i]);
}
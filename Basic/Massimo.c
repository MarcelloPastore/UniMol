#include <stdio.h>

int main() {

    int num, max;

    printf("Inserisci il primo numero: ");
    scanf("%d", &max);

    for (int i=0; i<2; ++i){

        printf("Inserisci il prossimo numero: ");
        scanf("%d", &num);
        
        if (num > max) {
            max = num;
        }
    }

    printf("Il massimo tra i numeri che hai inserito è: %d.", max);
    return 0;
}
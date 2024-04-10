#include <stdio.h>

int main (){

    int i, j, ris;

    for (i=1; i<=10; ++i){
        for (j=1; j<=10; ++j){
            ris = i*j;

            if (ris < 10){
                printf("  ");
            } else if (ris < 100){
                printf(" ");
            }
            printf("%d ", ris);
        }
        printf("\n");
    }
}
#include <omp.h>
#include <stdio.h>
#include <pthread.h>

int main() {
    printf("Questa è la regione principale\n");

    #pragma omp parallel
    {
        printf("Questa è una regione parallela\n");
    }
    return 0;
}   
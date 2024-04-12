#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int somma;
void *thread1(void *arg){
    int i;
     int n = *(int *)arg;
    somma = 0;
    for(i=0; i<=n; i++){
        somma += i;
    }
}
void main(int argc, char *argv[]) {
    pthread_t th1; // identifico il thread
    int n = atoi(argv[1]); //rendo il puntatore un intero
    pthread_create(&th1, NULL,(void *) thread1, &n);//creo il processo
    pthread_join(th1, NULL);//attendo che il processo finisca

    printf("Il valore della somma: %d \n", somma);
    printf("Termine del MAIN\n");
}
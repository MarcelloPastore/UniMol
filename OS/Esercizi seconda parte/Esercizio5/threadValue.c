#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>

int valore = 0;

void *thread1(void*argc){
    valore = 10;
    pthread_exit(0);
}

void main () {
    pid_t pid;
    pthread_t th1;
    pid = fork();

    if(pid==0){
        //processo Figlio
        pthread_create(&th1, NULL, (void *) thread1, "1");
        pthread_join(th1, NULL);

        printf("Il numero è: %d\n", valore);
        
    }else if (pid > 0){
        //processo Padre
        wait(NULL);
        printf("Processo padre n: %d\n", pid);
        printf("Il numero è: %d\n", valore);
    }else {
        printf("Attendo il completamento del processo figlio n: %d\n", pid);
        printf("Il processo figlio è terminato\n");
    }
    
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>
#include <semaphore.h>

sem_t semaforo;

void *thread1(void*argc){
    //sezione critica ingresso 
    sem_wait(&semaforo);
    for (int i = 0; i < 15; i++){
        printf("%s", (char *) argc);     
    }
    //sezione critica uscita
    sem_post(&semaforo);
    pthread_exit(0);
}

void main () {
    
    pthread_t th1, th2, th3;
    sem_init(&semaforo, 0, 1);

    pthread_create(&th1, NULL, (void *) thread1, ".");
    pthread_create(&th2, NULL, (void *) thread1, "#");
    pthread_create(&th3, NULL, (void *) thread1, "o");

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    pthread_join(th3, NULL);


    
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>
#include <semaphore.h>

sem_t semaforo;
int nums = 1;

void *thread1(void*argc){
    //sezione critica ingresso 
    sem_wait(&semaforo);
    printf("Thread B: %d\n", (nums++));     
    //sezione critica uscita
    sem_post(&semaforo);
    pthread_exit(0);
}

void *thread2(void*argc){
    //sezione critica ingresso 
    sem_wait(&semaforo);
    printf("Thread A: %d\n", (nums++));     
    //sezione critica uscita
    sem_post(&semaforo);
    pthread_exit(0);
}

void main () {
    
    pthread_t th1, th2;
    sem_init(&semaforo, 0, 1);
    while (nums<99){
        if(pthread_create(&th1, NULL, (void *) thread1, "B")){
            exit(1);
        }
        if(pthread_create(&th2, NULL, (void *) thread2, "A")){
            exit(1);
        }
    }
    
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);    
}
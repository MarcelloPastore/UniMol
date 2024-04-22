#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t first_mutex;
pthread_mutex_t second_mutex;


void *thread1(void *param){
    int ok = 0;
    while(!ok){
    pthread_mutex_lock(&first_mutex);
    if(pthread_mutex_trylock(&second_mutex)){
        {
            printf("Sono il thread 1\n");
        }
        pthread_mutex_unlock(&second_mutex);
        pthread_mutex_unlock(&first_mutex); 
        ok = 1;
        }else {
        pthread_mutex_unlock(&first_mutex); 
        }
    }
    pthread_exit(0);
}

void *thread2(void *param){
    int ok = 0;
    while(!ok){
        pthread_mutex_lock(&second_mutex);
            if (pthread_mutex_trylock(&first_mutex)){
            {
                printf("Sono il thread 2\n");
            }
            pthread_mutex_unlock(&first_mutex);
            pthread_mutex_unlock(&second_mutex); 
            ok = 1;
        }else { 
            pthread_mutex_unlock(&second_mutex);
        }
    }
    pthread_exit(0);
}

void main () {
    pthread_t th1, th2;

    pthread_mutex_init(&first_mutex, NULL);
    pthread_mutex_init(&second_mutex, NULL);
    if(pthread_create(&th1, NULL, (void *)thread1,NULL)<0){
        printf("Errore nella creazione del thread uno\n");
        exit(1);
    }

    if(pthread_create(&th2, NULL, (void *)thread2,NULL)<0){
        printf("Errore nella creazione del thread due\n");
        exit(1);
    }

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
int a = 1;
int b = 1;

void thread1(void *arg){
    void *error;
    {
        printf("Sono il primo thread. Ho parametro %s\n", (char *) arg);
        pthread_mutex_lock(&m);
        a+=1;
        b+=1;
        pthread_mutex_unlock(&m);
    }
    pthread_exit((void *)error);
}
void thread2(void *arg){
    void *error;
    {
        printf("Sono il secondo thread. Ho parametro %s\n", (char *) arg);
        pthread_mutex_lock(&m);
        a = a*2;
        b = b*2;
        pthread_mutex_unlock(&m);
    }
    pthread_exit((void *)error);
}

void main () {
    
    void *uscita;

    pthread_t th1, th2; // due identificativi per i thread
    pthread_create(&th1, NULL,(void *) thread1, "1");//creo il processo1
    sleep(1);

    pthread_create(&th2, NULL,(void *) thread2, "2");//creo il processo2
    sleep(1);

    pthread_join(th1, &uscita);//controllo e stato lo stato del thread
    printf("Stato 1: %d\n", (int *)uscita);

    pthread_join(th2, &uscita);//controllo e stato lo stato del thread
    printf("Stato 2: %d\n", (int *)uscita);

    printf("Valore di a: %d\n", a);
    printf("Valore di b: %d\n", b);
    printf("Termine del MAIN\n");
}


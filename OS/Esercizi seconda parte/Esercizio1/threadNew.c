#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void thread1(void *arg){
    printf("Sono il primo thread. Ho parametro %s\n", (char *) arg);
}
void thread2(void *arg){
    printf("Sono il secondo thread. Ho parametro %s\n", (char *) arg);
}

void main () {
    pthread_t th1, th2; // due identificativi per i thread

    pthread_create(&th1, NULL,(void *) thread1, "1");//creo il processo1
    sleep(1);
    pthread_create(&th2, NULL,(void *) thread2, "2");//creo il processo2
    sleep(1);
    printf("Termine del MAIN\n");
}


#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void thread1(void *arg){
    void *error;
    {
        printf("Sono il primo thread. Ho parametro %s\n", (char *) arg);
    }
    pthread_exit((void *)error);
}
void thread2(void *arg){
    void *error;
    {
        printf("Sono il secondo thread. Ho parametro %s\n", (char *) arg);
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

    pthread_join(th1, &uscita);//controllo e stamo lo stato del thread
    printf("Stato 1: %d\n", (int *)uscita);

    pthread_join(th2, &uscita);//controllo e stamo lo stato del thread
    printf("Stato 2: %d\n", (int *)uscita);

    printf("Termine del MAIN\n");
}


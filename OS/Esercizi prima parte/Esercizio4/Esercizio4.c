#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int pid, status;
    pid = fork();
    if(pid<0){
        fprintf(stderr, "generazione del nuovo processo fallita");
        return 1;
    }else if (pid == 0){
        int i;
        for ( i = 0; i < 10; i++)
        {
            printf("Sono il figlio \n");
        }
        exit(2);

    }else {
        printf("Attendo il completamento del processo figlio n: %d\n", pid);
        wait(&status);
        printf("Il processo figlio è terminato\n");
    }
    return 0;
}
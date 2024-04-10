#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid;
    pid = fork();
    if(pid<0){
        fprintf(stderr, "generazione del nuovo processo fallita");
        return 1;
    }else if (pid == 0){
        printf("Processo figlio n: %d\n", pid);
        execl("/bin/cd", "cd"," ..", NULL);
        execl("/bin/cd", "cd"," Esercizio2", NULL);
        // sleep(3);
        execl("/bin/ls", "ls"," ../Esercizio2", NULL);
        // execl("/bin/code", "code"," /Esercizio2/Esercizio.c", NULL);

    }else {
        printf("Attendo il completamento del processo figlio n: %d\n", pid);
        wait(NULL);
        printf("Il processo figlio è terminato\n");
    }
    return 0;
}
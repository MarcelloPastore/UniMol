#include <stdio.h>
#include <unistd.h>

int main() {
  int pid;
    pid = fork();
    if(pid<0){
        printf("generazione del nuovo processo fallita");
        return 1;
    }else if (pid == 0){
        printf("Processo figlio n: %d\n", pid);
    }else {
        printf("Sono il processo padre, il pid di mio figlio e': %d\n", pid);
    }
    sleep(20);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>


int main(void) {
    
    const int SIZE = 4096;

    const char *name = "OS";

    const char *message_0= "La Ferrari ";
    const char *message_1= "Vincerà il Mondiale ";
    const char *message_2= "di Formula 1! al 100% ";
    const char *message_3= "I sogni sono gli ultimi a morire\n";

    int shm_fd;

    void *ptr;
    
    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);

    ftruncate(shm_fd, SIZE);
    
    ptr = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (ptr == MAP_FAILED)
    {
        printf("Map Failed\n");
        return -1;
    }
    
    sprintf(ptr, "%s", message_0);
    ptr += strlen(message_0); 
    sprintf(ptr, "%s", message_1);
    ptr += strlen(message_1); 
    sprintf(ptr, "%s", message_2);
    ptr += strlen(message_2);
    sprintf(ptr, "%s", message_3);
    ptr += strlen(message_3);

    return 0;
}
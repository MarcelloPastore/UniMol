#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

int main () {
    const int SIZE = 4096;
    const char *name = "OS";
    int shm_fd;
    void *ptr;
    int i;

    shm_fd = shm_open(name, O_RDONLY, 0666);
    if(shm_fd == -1){
        printf("shared memory failed");
        exit(-1);
    }

    ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
    if (ptr == MAP_FAILED)
    {
        printf("Map Failed\n");
        exit(-1);
    }
    printf("%s", (char *) ptr);

    if (shm_unlink(name) == -1){
        printf("Error removing %s\n", name);
        exit(-1);
    }
    return 0;
}
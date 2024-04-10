#include <stdio.h>
#include <unistd.h>

int main()
{
    int durata, val, i;

    printf("Dammi la durata del timer: ");
    scanf("%d", &durata);

    val= durata;
    i= 0;

    while (val > i) {
        printf("%d \n", val);
        sleep(1);
        val--;
    }

    printf("Boom!");
}
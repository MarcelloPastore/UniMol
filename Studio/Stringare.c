#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main () {
    char a[25] = "Hello world";
    char b[25] = "hello world";
    char copy[25];

    int size1 = strlen(a);
    int size2 = strlen(b);
    
    strcpy(copy, a);
    
    for (int i=0; i<size1; i++) {
        a[i] = tolower(a[i]);
    }
    
    printf("%s\n", a);
    
    printf("%s\n", copy);

    if (strcmp(a, b) == 0) {
        printf("Sono uguali.\n");
    } else {
        printf("Sono diverse.\n");
    }

    printf("%d", size1);
}
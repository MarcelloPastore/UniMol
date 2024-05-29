#include <stdio.h>
int main() {
    FILE *f = fopen("./test.txt", "r");
    fprintf(f, "Hello World!");
    fclose(f);
    return 0;
}
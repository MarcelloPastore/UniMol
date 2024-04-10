 #include<stdio.h>

 int main() {
 
    int n, i;

    n = 8;
    i = 1;

    while (i <= 6) {
        n += 8;
    
        if (n > 30) {
            printf("%d\n", n);
            i++;
        }
    }
 }
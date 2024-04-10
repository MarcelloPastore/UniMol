#include<stdio.h>

int main()
{
	int a, i, somma;
	
	printf("Dammi un numero: ");
	scanf("%d", &a);

  	if (a < 0) {
        	printf("Hai inserito un numero non Naturale. Riavvia il programma.");
    	}
	else {
    
		somma = 0;
		i = 1;
    
    		while (i <= a) {
        		somma = somma + i;
        		i++;
    		}

    		printf("La somma dei primi %d numeri naturali è %d.", a, somma);
	}
}
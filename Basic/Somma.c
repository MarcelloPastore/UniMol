#include<stdio.h>

int main()
{
	int a, b, somma;
	
	printf("Dammi il primo numero: ");
	scanf("%d", &a);
	printf("Dammi il secondo numero: ");
	scanf("%d", &b);
	
	somma = a + b;
	
	printf("La somma tra i numeri %d e %d risulta %d.", a, b, somma);
	return 0;
}
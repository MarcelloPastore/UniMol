#include<stdio.h>

int main()
{
	int a, i, n, fattoriale;
	
	printf("Dammi un numero: ");
	scanf("%d", &a);

	fattoriale = 1;
	i = 2;
	n = a;

	if (a < 0) {
		n = -a;
	}
	
	while (i <= n) {
		fattoriale = fattoriale * i;
		i++;
	}
	
	if ((a < 0)&&(n%2 !=0)) {
		fattoriale = -fattoriale;
	}
	
	printf("Il fattoriale di %d è %d.", a, fattoriale);
}
#include<stdio.h>

int main()
{
	int a, b, c, max;
	
	printf("Dammi il primo numero: ");
	scanf("%d", &a);
	printf("Dammi il secondo numero: ");
	scanf("%d", &b);
	printf("Dammi il terzo numero: ");
	scanf("%d", &c);
	
	if ((a > b)&&(a > c)) {
		max = a;
	}
	else if ((b > a)&&(b > c)) {
		max = b;
	}
	else {
		max = c;
	}
	
	printf("Il numero più grande tra %d, %d e %d è %d.", a, b, c, max);
}
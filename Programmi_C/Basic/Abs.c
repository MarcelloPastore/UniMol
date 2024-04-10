#include<stdio.h>

int main()
{
	int a, abs;
	
	printf("Dammi il numero: ");
	scanf("%d", &a);
	
	if (a < 0){
		abs = -a;
	}
	else {
		abs = a;
	}
	
	printf("Il valore assoluto di %d è uguale a %d.", a, abs);

	return 0;
}
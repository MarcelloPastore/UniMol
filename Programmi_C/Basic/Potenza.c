#include<stdio.h>

int main()
{
	int b, e, i, val, pot;
	
	printf("Dammi la base: ");
	scanf("%d", &b);
	printf("Dammi l'esponente: ");
	scanf("%d", &e);
	
	i = 1;
	pot = 1;
	val = e;
	
	if (e < 0) {
		val = -e;
		
		if (b == 0) {
			pot = 0;
		}
	}
	
	while (i <= val) {
		pot *= b;
		i++;
	}
	
	if ((e < 0)&&(b !=0)) {
		printf("Il numero %d elevato alla %d, risulta 1/%d.", b, e, pot);

	}
	else {
		printf("Il numero %d elevato alla %d, risulta %d.", b, e, pot);

	}
}
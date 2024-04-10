#include <stdio.h>

main () {

	float n1, n2, media;

	printf("Dammi il primo numero: ");
	scanf("%f", &n1);
	printf("Dammi il secondo numero: ");
	scanf("%f", &n2);

	media = (n1 + n2) / 2;

	printf("La media è: %f", media);
}
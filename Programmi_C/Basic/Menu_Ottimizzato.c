// Online C compiler to run C program online
#include <stdio.h>

int main() {
  int scelta, num1, num2, risultato, tronc;
  double quoziente, n, dec;

    do {
        // Visualizzo le voci di menù
        printf ("**** OPERAZIONI ARITMETICHE ****\n");
        printf ("1. Somma\n");
        printf ("2. Sottrazione\n");
        printf ("3. Moltiplicazione\n");
        printf ("4. Divisione\n");
        printf ("5. Resto della divisione\n");
        printf ("6. Arrotondamento\n");
        printf ("7. Troncamento\n");
        printf ("0. Uscita\n\n");
        
        // Leggo la scelta dell'utente
        printf ("Scelta: ");
        scanf ("%d", &scelta);
        
        switch (scelta) {
            case 1:
                printf("Somma tra due numeri.\n");
                printf("Dammi il primo numero: ");
                scanf("%d", &num1);
                printf("Dammi il secondo numero: ");
                scanf("%d", &num2);
                
                risultato = num1 + num2;
                
                printf("%d + %d = %d\n\n", num1, num2, risultato);
                break;
            case 2:
                printf("Sottrazione tra due numeri.\n");
                printf("Dammi il primo numero: ");
                scanf("%d", &num1);
                printf("Dammi il secondo numero: ");
                scanf("%d", &num2);
                
                risultato = num1 - num2;
                
                printf("%d - %d = %d\n\n", num1, num2, risultato);
                break;
            case 3:
                printf("Moltiplicazione tra due numeri.\n");
                printf("Dammi il primo numero: ");
                scanf("%d", &num1);
                printf("Dammi il secondo numero: ");
                scanf("%d", &num2);
                
                risultato = num1 * num2;
                
                printf("%d * %d = %d\n\n", num1, num2, risultato);
                break;
            case 4:
                printf("Divisione tra due numeri.\n");
                printf("Dammi il primo numero: ");
                scanf("%d", &num1);
                printf("Dammi il secondo numero: ");
                scanf("%d", &num2);
                
                quoziente = (double) num1 / num2;
                
                printf("%d / %d = %.2f\n\n", num1, num2, quoziente);
                break;
            case 5:
                printf("Calcolo del resto.\n");
                printf("Dammi il primo numero: ");
                scanf("%d", &num1);
                printf("Dammi il secondo numero: ");
                scanf("%d", &num2);
                
                risultato = num1 % num2;
                
                printf("Il resto, dividendo %d per %d è uguale a %d\n\n", num1, num2, risultato);
                break;
            case 6:
                printf("Hai selezionato Arrotondamento.\n");

                printf("Dammi il numero da approssimare: ");
                scanf("%lf", &n);

                tronc = (int) n;
                dec = n - tronc;

                if (dec < 0.5) {
                    risultato = tronc;
                } else {
                    risultato = tronc + 1;
                }

                printf("Il numero %f arrotondato è %d\n\n", n, risultato);
                break;
            case 7:
                printf("Hai selezionato il troncamento.\n");

                printf("Dammi il numero da troncare: ");
                scanf("%lf", &n);

                risultato = (int) n;

                printf("Il numero %f troncato è %d\n\n", n, risultato);
                break;
            case 0:
                printf("Fine lavoro. Ciao!");
                break;
            default:
                printf("Scelta errata.\n\n");
        }
    } while (scelta != 0);
}
//5 operazioni sui numeri interi (+ - * / %). Mostra un menù di scelta per l'operazione da fare ed esegui a seconda.

#include <stdio.h>

int main () {

int op, a, b, risultato;

printf("Benvenuto. Che operazione desideri fare?\n");

do {
printf("1 - Addizione\n2 - Sottrazione\n3 - Moltiplicazione\n4 - Divisione\n5 - Calcolo del resto\n\tOperazione scelta: ");
scanf("%d", &op);
if (op < 1 || op > 5) {
    printf("Per favore, inserisci una delle opzioni sotto elencate: \n");
}
} while (op < 1 || op > 5);

switch (op) {
    case 2:
        printf(" Hai selezionato la sottrazione!\nInserisci il primo numero: ");
        scanf("%d", &a);
        printf("Inserisci il secondo numero: ");
        scanf("%d", &b);

        risultato = a - b;
        break;
    case 3:
        printf(" Hai selezionato la moltiplicazione!\nInserisci il primo numero: ");
        scanf("%d", &a);
        printf("Inserisci il secondo numero: ");
        scanf("%d", &b);

        risultato = a * b;
        break;
    case 4:
        printf(" Hai selezionato la divisione!\nInserisci il primo numero: ");
        scanf("%d", &a);
        printf("Inserisci il secondo numero: ");
        scanf("%d", &b);

        risultato = a / b;
        break;
    case 5:
        printf(" Hai selezionato il calcolo del resto!\nInserisci il primo numero: ");
        scanf("%d", &a);
        printf("Inserisci il secondo numero: ");
        scanf("%d", &b);

        risultato = a % b;
        break;
    default:
        printf(" Hai selezionato l'addizione!\nInserisci il primo numero: ");
        scanf("%d", &a);
        printf("Inserisci il secondo numero: ");
        scanf("%d", &b);

        risultato = a + b;
        break;
}

printf("Risultato = %d.", risultato);

}
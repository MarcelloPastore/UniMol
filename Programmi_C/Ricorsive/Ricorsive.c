// Ricorsiva Moltiplicazione, Divisione, Potenza, MCD, Fibonacci

#include <stdio.h>

// 1.
int moltiplicazione (int numero, int n) {
    if (n == 0) {
        return 0;
    }

    return numero +  moltiplicazione (numero, n-1);
}
// 2.
int divisione (int num, int den) {
    if (num == 0) {
        return 0;
    }

    return 1 + divisione (num - den, den);
}

// 3.
int potenza (int numero, int n) {
    if (n == 0) {
        return 1;
    }

    return numero * potenza (numero, n-1);
}

// 4.
int mcd (int a, int b) {
    if (a == b) {
        return a;
    }

    if (a>b) {
        return mcd (a-b, b);
    }
    return mcd (a, b-a);
}

// 5.
int fibonacci (int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    return fibonacci (n-1) + fibonacci (n-2);
}

// 6.
int somma (int a, int b) {
    if (b == 0) {
        return a;
    }

    return somma (a+1, b-1);
}

// 7.
int sottrazione (int a, int b) {
    if (b == 0) {
        return a;
    }

    return sottrazione (a-1, b-1);
}

// 8.
int inserimento_array (int size, int k, int *array) {
    if (k > size) {
        return printf("\n");
    }

    printf("Inserisci l'elemento n°%d: ", k+1);
    scanf("%d", &array[k]);
    
    return inserimento_array(size, k+1, array);
}

// 9.
int stampa_array (int size, int *array) {
    if (size == 0) {
       return printf("\n");
    }

    printf("[%d] ", *array);
    return stampa_array(size-1, array+1);
}

int main () {
    int numero = 6;
    int n = 3;

    int array[5] = {0, 4, -1, 18, 6};

    printf("%d\n", moltiplicazione(numero, n));
    printf("%d\n", divisione(numero, n));
    printf("%d\n", potenza(numero, n));
    printf("%d\n", mcd(numero, n));
    printf("%d\n", fibonacci(numero));
    printf("%d\n", somma(numero, n));
    printf("%d\n", sottrazione(numero, n));

    stampa_array(5, array);
    inserimento_array(5-1, 0, array);
}
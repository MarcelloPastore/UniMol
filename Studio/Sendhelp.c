/******************************************************************************

Funzioni stringhe: 
	- strlen
	- strcpy & strncpy (prende in input 2 params) - (prende in input 3 params, 4)
	- strcat & strncat
	- strcmp & strncmp
	- strchr & strstr
	- strtok
	- islower, tolower, isupper, toupper

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define DIM 104

int main()
{

    char * stringa = "Fratm e Franco\0";
    int lunghezza = strlen(stringa);
    
    char src[DIM] = "String iniziale";
    char dest[DIM];
    // int *pNumero = NULL;

    char word1[DIM] = "Maurone ha ";
    char word2[DIM] = "il pisellone golosone";
    char * wordZ;
    
    char compare1[DIM] = "Nicola HA troPPi AnNi per l'università";
    char compare2[DIM] = "nicola ha troppi anni per l'università";
    
    char text[] = "Ogni cane ha il suo giorno";
    char word[] = " ";
    char * pFound = NULL;
    pFound = strstr(text, word);
    
    char charText[] = "La volpe marrone con il cagone";
    char charWord = ' ';
    char * pCharFound = NULL;
    pCharFound = strchr(charText, charWord);
    
    char tokenString[DIM] = "Ciao Pistolo - Nel fiume Grande - Trovo Anna Frank - con Davide che sorride!";
    const char s[2] = "-\0";
    char * token;
    
    // ------------------------------------------
    // STRLEN
    // printf("%d", lunghezza);
    // for (int i = 0; i < strlen(stringa); i++) {
    //     printf("%c\n", stringa[i]);
    // }
    
    // ------------------------------------------
    // STRCPY & STRNCPY
    // printf("%s\n", src);
    // printf("%s\n", dest);
    
    // strcpy(dest, src);
    // printf("%s\n", src);
    // printf("%s\n", dest);
    
    // strncpy(dest, src, 6);
    // printf("%s\n", src);
    // printf("%s\n", dest);
    
    // ------------------------------------------
    // STRCAT & STRNCAT
    // printf("%s\n", word1);
    // printf("%s\n\n", word2);
    
    // wordZ = strcat(word1, word2);
    // wordZ = strncat(word1, word2, 12);
    
    // printf("%s\n", wordZ);
    
    
    // ------------------------------------------
    // STRCMP & STRNCMP == 0, <0, >0
    
    //islower - tolower
    // printf("%s\n", compare1);
    // for (int i = 0; i < strlen(compare1); i++) {
    //     // compare1[i] = toupper(compare1[i]);
    //     compare1[i] = tolower(compare1[i]);
    // }
    // printf("%s\n", compare1);
    
    // if(strcmp(compare1, compare2) == 0) {
    //     printf("%d\n", strcmp(compare1, compare2));
    //     printf("Le strighe sono identiche");
    // } else {
    //     printf("%d\n", strcmp(compare1, compare2));
    //     printf("Davide ha ucciso il maiale");
    // }
    
    // ------------------------------------------
    // STRCHR & STRSTR
    // printf("%s\n", pFound);
    // printf("%s\n", pCharFound);
    
    // ------------------------------------------
    // STRTOK
    printf("%s\n", tokenString);
    token = strtok(tokenString, s);
    
    int contatorePerDavide = 0;
    while(token != NULL) {
        printf("%s\n", token);
        
        token = strtok(NULL, s);
        contatorePerDavide++;
    }

    printf("%d\n", contatorePerDavide);


    return 0;
}


------------------------------------------------------------------------------------------------------

/******************************************************************************

1) Array bidimensionali
- Funzioni ricorsive
- Gestire un array con funzioni ricorsive
2) Esercizio stampa binario da intero (traccia esercizio oliveto)
3) Esercizio calcolo somma valori univoci

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define DIM 104
#define RIGHE 3
#define COLONNE 3
#define RIGHEROCCO 6

void stampaRicorsiva(int *_array, int _size);

int main()
{
    int arrayRocco[RIGHEROCCO] = { 3, 18, 15, 44, 77, 98 };
    int array[RIGHE][COLONNE];
    
    for (int i = 0; i < RIGHE; i++) {
        for (int j = 0; j < COLONNE; j++) {
            array[i][j];
        }
    }
    
    stampaRicorsiva(arrayRocco, RIGHEROCCO);
    
    
    
    return 0;
}


void stampaRicorsiva(int *_array, int _size) {
    if (_size == 0) {
        printf("\n");
    } else {
        printf("%d , ", *_array);
        stampaRicorsiva(_array + 1, _size - 1);
    }
}


int fattoriale(int _n) {
    int res = 0;
    
    if((_n == 0) || (_n == 1)) {
        return 1;
    } else {
        return res = _n * fattoriale(_n - 1);
    }
}

--------------------------------------------------------------------------------------

#include <stdio.h>
#define DIM 30

void decToBinary(int num, int binaryNum[], int *index);
void printBinary(int binaryNum[], int size);

int main(void) {
    int numero;
    int binaryNum[DIM];
    int i = 0;

    // Chiedere all'utente di inserire un numero intero
    printf("Inserisci un numero intero: ");
    scanf("%d", &numero);

    // Chiamare la funzione per la conversione
    decToBinary(numero, binaryNum, &i);

    // Stampare la rappresentazione binaria
    printf("Rappresentazione binaria: ");
    printBinary(binaryNum, i);

    return 0;
}

void decToBinary(int _num, int *_binaryNum, int *_i) {
    
    // Caso base
    if (_num > 0) {
        // Chiamare la funzione ricorsiva con il quoziente
        decToBinary(_num / 2, _binaryNum, _i);

        // Memorizzare il resto come bit corrente
        printf("%d\n",  _binaryNum[(*_i)++] = _num % 2);
    }
}

void printBinary(int *_binaryNum, int _size) {
    for (int i = 0; i < _size; i++) {
            printf("%d", _binaryNum[i]);
        }
       printf("\n");
}

--------------------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define DIM 8

int sommaNonUnivoci(int _valori[], int count);
int sommaUnivoci(int _valori[], int count);

int main() {
    int valori[DIM] = {7, 5, 7, 7, 8, 6, 5, 3};

    int nonUnivoci = sommaNonUnivoci(valori, DIM);
    int univoci = sommaUnivoci(valori, DIM);
    
    printf("%d\n", nonUnivoci);
    printf("%d\n", univoci);

    return 0;
    
}

int sommaNonUnivoci(int _valori[], int count) {
    int somma = 0;
    int flag = 0;
    
    for (int i = 0; i < count; i++) {
        flag = 0;
        for (int j = 0; j < count; j++) {
            if (i != j) {
                if (_valori[i] == _valori[j])
                    flag = 1;
            }
        }
        if (flag == 1)
                    somma += _valori[i];
    }
    return somma;
}

int sommaUnivoci(int _valori[], int count) {
    int somma = 0;
    int flag = 1;
    
    for (int i = 0; i < count; i++) {
        flag = 1;
        for (int j = 0; j < count; j++) {
            if (i != j) {
                if (_valori[i] == _valori[j])
                    flag = 0;
            }
        }
        if (flag == 1)
                    somma += _valori[i];
    }
    return somma;
}
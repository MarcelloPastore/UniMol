#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 1.
int univoci (int *nums, int size) {
    int sum_univoci=0;
    int sum_non_univoci=0;

    for (int i=0; i<size; i++) {
        int flag = 0;
        for (int j=0; j<size; j++) {
            if (i != j) {
                if (nums[i] == nums[j]) {
                    flag = 1;
                }
            }
        }
        if (flag == 0)
            sum_univoci += nums[i];
        else
            sum_non_univoci += nums[i];
    }

    return (sum_univoci - sum_non_univoci);
}

// 2.
int confronto (int rows, int cols, char word1[][cols], char word2[][cols]) {

    char * concatenazione1 = (char*) malloc(rows * cols);
    char * concatenazione2 = (char*) malloc(rows * cols);

    int k=0;
    for (int i=0; i<rows; i++) {
        int j=0;
        while (word1[i][j] != '\0') {
            concatenazione1[k] = word1[i][j];
            j++;
            k++;
        }
    }
    concatenazione1[k] = '\0';

    k=0;
    for (int i=0; i<rows; i++) {
        int j=0;
        while (word2[i][j] != '\0') {
            concatenazione2[k] = word2[i][j];
            j++;
            k++;
        }
    }
    concatenazione2[k] = '\0';

    strrev(concatenazione2);

    if (strcmp(concatenazione1, concatenazione2) == 0) 
        return 1;
    return 0;
}

// 3.
int quoziente (int num, int den) {
    if (num < den) {
        return 0;
    }

    return 1 + quoziente (num-den, den);
}

#define RIGHE 3
#define COLONNE 15
int main () {
    char stringa_temporanea[COLONNE];

    char word1[RIGHE][COLONNE];
    char word2[RIGHE][COLONNE];

    for (int i=0; i<RIGHE; i++) {
        printf("word1: Inserisci la stringa n°%d: ", i+1);
        scanf("%s", stringa_temporanea);
        strcpy(word1[i], stringa_temporanea);
    }
    printf("\n");
    for (int i=0; i<RIGHE; i++) {
        printf("word2: Inserisci la stringa n°%d: ", i+1);
        scanf("%s", stringa_temporanea);
        strcpy(word2[i], stringa_temporanea);
    }

    int risultato = confronto (RIGHE, COLONNE, word1, word2);

    if (risultato == 1)
        printf("Le stringhe concatenate sono uguali.\n");
    else
        printf("Le stringhe concatenate sono diverse.\n");
}
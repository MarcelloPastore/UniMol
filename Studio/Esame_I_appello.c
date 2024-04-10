#include <stdio.h>

// Coppie
int coppie (int nums[], int size, int k) {
    int n_coppie = 0;

    for (int i=0; i <(size-1); i++) {
        for (int j=i+1; j<size; j++){
            if (nums[i]-nums[j] == k)
                n_coppie++;
        }    
    }

    return n_coppie;
}

//Calcolo laser nella banca
int laser (int righe, int colonne, char bank[][colonne]) {
    int n_laser = 0;

    for (int i=0; i<(righe-1); i++) {
        int j=0;
        while (bank[i][j] != '\0') {
            if (bank[i][j] == '1') {
                int trovato = 0;
                for (int k=i+1; k<righe && !trovato; k++) {
                    int m=0;
                    while (bank[k][m] != '\0') {
                        if (bank[k][m] == '1') {
                            trovato = 1;
                            n_laser++;
                        }
                        m++;
                    }
                }
            }
            j++;
        }
    }

    return n_laser;
}

// Somma dispari ricorsiva
int somma (int *nums, int size) {
    if (size == 0)
        return 0;

    if (*nums % 2 != 0)
        return *nums + somma (nums+1, size-1);

    return somma (nums+1, size-1);
}

int main () {
    char bank[4][7] = {"000100", "101100", "000000", "101000"};

    printf("%d", laser (4, 7, bank));
}
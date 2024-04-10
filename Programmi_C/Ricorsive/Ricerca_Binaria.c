#include <stdio.h>

int ricerca_binaria (int *nums, int inf, int sup, int k) {
    if (nums[(sup+inf)/2] == k)
        return (sup+inf)/2;
    else if (sup - inf == 1)
        return -1;
    
    if (nums[(sup+inf)/2] > k) {
        return ricerca_binaria (nums, inf, (sup+inf)/2, k);
    } else {
        return ricerca_binaria (nums, (sup+inf)/2, sup, k);
    }
}

int main () {
    int nums[9] = {0, 2, 6, 9, 15, 18, 24, 25, 32};
    int k = 18;

    int risultato = ricerca_binaria (nums, 0, 9, k);
    if (risultato >= 0) {
        printf("Il numero si trova nell'array con indice: %d.", risultato);
    } else {
        printf("Il numero non è presente nell'array.");
    }
}
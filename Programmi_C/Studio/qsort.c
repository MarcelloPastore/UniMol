#include <stdio.h>
#include <stdlib.h>

int comp (const void *a, const void *b) {
    return (*(char*)a - *(char*)b);
}

int diff_univoci (int _nums[], int _n) {
    int somma_univoci = 0;
    int somma_non_univoci = 0;

    qsort(_nums, _n, sizeof(int), comp);

    if (_nums[0] == _nums[1])
        somma_non_univoci++;
    else
        somma_univoci++;

    for (int i=0; i<_n-1, i++) {
        if () {

        }
    }
}
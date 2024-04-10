#include <stdio.h>

#define DIM 4

typedef struct {
    int start;
    int end;
} Interval;

int main () {
    Interval intervalli[4] = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    Interval risultato[4];

    risultato[0] = intervalli[0];
    int j=0;
    for (int i=1; i < 4; i++) {
        if (intervalli[i].start <= risultato[j].end) {
            risultato[j].end = intervalli[i].end;
        } else {
            j++;
            risultato[j] = intervalli[i];
        }
    }

    printf("Gli intervalli uniti sono: \n");
    for (int i=0; i <= j; i++) {
        printf("{%d, %d}", risultato[i].start, risultato[i].end);
    }
}
#include <stdio.h>

int differenza (int a, int b) {
    if (b==0)
        return a;

    return differenza (a-1, b-1);
}

int
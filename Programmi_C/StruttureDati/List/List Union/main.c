#include <stdio.h>
#include "list.h"

int main() {
    list l = list_new(TYPE_STRING);

    listelement a;
    a.sval = "ciao";
    list_append(l, a);

    a.sval = "test2";
    list_append(l, a);
    
    a.sval = "test3";
    list_append(l, a);

    listelement result;
    list_get_last(l, &result);
    printf("%s\n", result.sval);
    
    list l2 = list_new(TYPE_FLOAT);

    listelement b;
    b.fval = 3.2;
    list_append(l2, b);

    b.fval = 23;
    list_append(l2, b);
    
    b.fval = 2.01;
    list_append(l2, b);

    listelement result2;
    list_get_last(l2, &result2);
    printf("%f\n", result2.fval);
}

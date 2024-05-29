#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int main() {
    hash h = hash_new(4);

    hash_set(h, "Mario Rossi", 1);
    hash_set(h, "Maria Bianchi", 2);
    hash_set(h, "Marco Verdi", 3);
    hash_set(h, "Giovanna Gialli", 4);
    hash_set(h, "Giovanna Blu", 5);

    printf("%d", hash_get(h, "Mario Rossi"));
    printf("%d", hash_get(h, "Maria Bianchi"));
    printf("%d", hash_get(h, "Marco Verdi"));
    printf("%d", hash_get(h, "Giovanna Gialli"));
    printf("%d", hash_get(h, "Giovanna Blu"));
    destroy_hash(h);

}
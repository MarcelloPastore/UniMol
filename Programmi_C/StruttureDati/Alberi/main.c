#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main() {
    tree t = tree_new();
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 3; j++)
    {
        tree_add(t, j);
    }   
    }   
    int valore;
    printf("Dimmi quale valore vuoi ricercare: ");
    scanf("%d", &valore);

    printf("\nAltezza albero: %d", tree_height(t));
    printf("\nSize albero: %d\n", tree_size(t));
    // printf("Nodo root: %d\n", tree_get_root_data(t));
    printf("Foglie: %d\n", tree_breadth(t));
    printf("Livello del valore %d: livello %d\n", valore, tree_level(t, valore));
    tree_delete(t, valore);
    printf("\nAltezza albero: %d", tree_height(t));
    printf("Foglie: %d\n", tree_breadth(t));
    printf("\nSize albero: %d\n", tree_size(t));

    return 0;
}
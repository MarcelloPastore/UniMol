#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
void stampa_valore(treenode value){
    printf("-->%d\n", treenode);
}
int main() {
    tree t = tree_new();
    tree_add(t, 3);
    tree_add(t, 12);
    tree_add(t, 4);
    tree_add(t, 5);
    tree_add(t, 2);
    tree_add(t, 6);
    tree_add(t, 3);
    int valore;
    // printf("Dimmi quale valore vuoi ricercare: ");
    // scanf("%d", &valore);

    // printf("\nAltezza albero: %d", tree_height(t));
    // printf("\nSize albero: %d\n", tree_size(t));
    // printf("Nodo root: %d\n", tree_get_root_data(t));
    // printf("Foglie: %d\n", tree_breadth(t));
    // printf("Livello del valore %d: livello %d\n", valore, tree_level(t, valore));
    // tree_delete(t, valore);
    // printf("\nAltezza albero: %d", tree_height(t));
    // printf("Foglie: %d\n", tree_breadth(t));
    // printf("\nSize albero: %d\n", tree_size(t));
    tree_preorder_visit(t, stampa_valore);

    return 0;
}
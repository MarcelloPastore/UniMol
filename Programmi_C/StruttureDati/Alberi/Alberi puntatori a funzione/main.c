#include "tree.h"
#include <stdio.h>

void stampa_valore(treenode node) {
    printf("--> %d\n", treenode_value(node));
}

int main() {
    tree t = tree_new();
        
    tree_add(t, 3);
    tree_add(t, 3);
    tree_add(t, 30);
    tree_add(t, 4);
    tree_add(t, 13);
    tree_add(t, 3);
        
    tree_preorder_visit(t, stampa_valore);
}

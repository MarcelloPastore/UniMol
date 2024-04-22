#include "tree.h"
#include <stdio.h>

int main() {
    tree t = tree_new();
        
    tree_add(t, 0);
    tree_add(t, 1);
    tree_add(t, 2);
    tree_add(t, 3);
    tree_add(t, 4);
    
    printf("%d", tree_size_bf(t));
}

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main() {
    tree t = tree_create();
    treenode node1 = treenode_create(1);
    treenode node2 = treenode_create(2);
    treenode node3 = treenode_create(3);
    treenode node4 = treenode_create(4);
    treenode node5 = treenode_create(5);
    treenode node6 = treenode_create(5);

    tree_set_root(t, node1);

    treenode_set_left(node1, node2);
    treenode_set_left(node2, node3);
    treenode_set_right(node1, node4);
    treenode_set_right(node4, node5);
    treenode_set_left(node3, node6);

    printf("\nAltezza albero: %d", tree_height(t));
    printf("\nSize albero: %d\n", tree_size(t));
    printf("Nodo root: %d\n", tree_get_root_data(t));

    return 0;
}
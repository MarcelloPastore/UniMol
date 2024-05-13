#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "undigraph.h"
 
int main() {
    undigraph g = undigraph_new(10);

    int n0 = undigraph_add_node(g, 0);
    int n1 = undigraph_add_node(g, 1);
    int n2 = undigraph_add_node(g, 2);
    int n3 = undigraph_add_node(g, 3);
    int n4 = undigraph_add_node(g, 4);
    int n5 = undigraph_add_node(g, 5);
    int n6 = undigraph_add_node(g, 6);

    undigraph_add_edge(g, n1, n3);
    undigraph_add_edge(g, n2, n1);
    undigraph_add_edge(g, n1, n3);
    undigraph_add_edge(g, n1, n4);
    undigraph_add_edge(g, n2, n5);
    undigraph_add_edge(g, n2, n3);
    undigraph_add_edge(g, n3, n6);
    undigraph_add_edge(g, n6, n1);
    
    printf("Depth visit: \n");
    undigraph_dfs(g, n3);
    printf("\n");
    printf("Breath visit: \n");
    undigraph_bfs(g, n3);
    printf("\n");
    printf("Depth visit iterative: \n");
    undigraph_dfs_iter(g, n3);
    printf("\n");
    printf("Path exist?\n");
    undigraph_path_exist(g, n3, n2);
    
    
    undigraph_destroy(g);
}

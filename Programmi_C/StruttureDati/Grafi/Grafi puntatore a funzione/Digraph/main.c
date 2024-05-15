#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "digraph.h"
 
int main() {
    digraph g = digraph_new(10);

    int n0 = digraph_add_node(g, 0);
    int n1 = digraph_add_node(g, 1);
    int n2 = digraph_add_node(g, 2);
    int n3 = digraph_add_node(g, 3);
    int n4 = digraph_add_node(g, 4);
    int n5 = digraph_add_node(g, 5);
    int n6 = digraph_add_node(g, 6);

    digraph_add_edge(g, n1, n2);
    digraph_add_edge(g, n1, n3);
    digraph_add_edge(g, n1, n4);
    digraph_add_edge(g, n2, n3);
    digraph_add_edge(g, n2, n5);
    digraph_add_edge(g, n3, n6);
    digraph_add_edge(g, n6, n1);
    
    printf("Depth visit: \n");
    digraph_dfs(g, n3);
    printf("\n");
    printf("Breath visit: \n");
    digraph_bfs(g, n3);
    printf("\n");
    printf("Depth visit iterative: \n");
    digraph_dfs_iter(g, n3);
    printf("\n");
    printf("Path exist?\n");
    digraph_path_exist(g, n3, n2);
    
    
    digraph_destroy(g);
}

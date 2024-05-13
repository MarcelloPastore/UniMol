#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "wegraph.h"
 
int main() {
    wegraph g = wegraph_new(10);

    int n0 = wegraph_add_node(g, 0);
    int n1 = wegraph_add_node(g, 1);
    int n2 = wegraph_add_node(g, 2);
    int n3 = wegraph_add_node(g, 3);
    int n4 = wegraph_add_node(g, 4);
    int n5 = wegraph_add_node(g, 5);
    int n6 = wegraph_add_node(g, 6);

    wegraph_add_edge(g, n1, n2);
    wegraph_add_edge(g, n1, n3);
    wegraph_add_edge(g, n1, n4);
    wegraph_add_edge(g, n2, n3);
    wegraph_add_edge(g, n2, n5);
    wegraph_add_edge(g, n3, n6);
    wegraph_add_edge(g, n6, n1);
    
    printf("Depth visit: \n");
    wegraph_dfs(g, n3);
    printf("\n");
    printf("Breath visit: \n");
    wegraph_bfs(g, n3);
    printf("\n");
    printf("Depth visit iterative: \n");
    wegraph_dfs_iter(g, n3);
    printf("\n");
    printf("Path exist?\n");
    wegraph_path_exist(g, n3, n2);
    
    
    wegraph_destroy(g);
}

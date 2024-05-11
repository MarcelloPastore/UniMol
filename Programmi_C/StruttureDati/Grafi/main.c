#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"
 
int main() {
    graph g = graph_new(10);

    int n0 = graph_add_node(g, 0);
    int n1 = graph_add_node(g, 1);
    int n2 = graph_add_node(g, 2);
    int n3 = graph_add_node(g, 3);
    int n4 = graph_add_node(g, 4);
    int n5 = graph_add_node(g, 5);
    int n6 = graph_add_node(g, 6);

    graph_add_edge(g, n1, n2);
    graph_add_edge(g, n1, n3);
    graph_add_edge(g, n1, n4);
    graph_add_edge(g, n2, n3);
    graph_add_edge(g, n2, n5);
    graph_add_edge(g, n3, n6);
    graph_add_edge(g, n6, n1);
    
    printf("Depth visit: \n");
    graph_dfs(g, n3);
    printf("\n");
    printf("Breath visit: \n");
    graph_bfs(g, n3);
    printf("\n");
    printf("Depth visit iterative: \n");
    graph_dfs_iter(g, n3);
    printf("\n");
    printf("Path exist?\n");
    graph_path_exist(g, n3, n2);
    
    
    graph_destroy(g);
}

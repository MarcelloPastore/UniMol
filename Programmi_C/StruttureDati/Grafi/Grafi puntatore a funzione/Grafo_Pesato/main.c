#include <stdio.h>
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
    
    digraph_add_edge(g, n1, n2, 1);
    digraph_add_edge(g, n1, n3, 2);
    digraph_add_edge(g, n1, n4, 3);
    digraph_add_edge(g, n2, n5, 4);
    digraph_add_edge(g, n2, n3, 5);
    digraph_add_edge(g, n3, n6, 6);
    digraph_add_edge(g, n6, n1, 7);
    
    float cost = digraph_path_cost(g, n1, n6);
    printf("%f\n", cost);
        
    digraph_destroy(g);
}

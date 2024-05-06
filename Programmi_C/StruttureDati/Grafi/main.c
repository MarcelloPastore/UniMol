#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"
 
int main() {
    graph g = graph_new(10);

    int n0 = graph_add_node(g, 5);
    int n1 = graph_add_node(g, 6);
    int n2 = graph_add_node(g, 12);
    int n3 = graph_add_node(g, 8);
    int n4 = graph_add_node(g, 5);

    graph_add_edge(g, n0, n2);
    graph_add_edge(g, n2, n1);
    graph_add_edge(g, n1, n3);
    graph_add_edge(g, n3, n4);
    graph_destroy(g);
}

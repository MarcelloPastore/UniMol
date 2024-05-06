#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"

struct _graph {
    int *nodes;
    bool **edges;

    int max_size;
    int size;
};

graph graph_new(int max_size){
    struct _graph* g = (struct _graph*)malloc(sizeof(struct _graph));
    if (g != NULL){
        g->nodes = (int*)malloc(sizeof(int)*max_size);
        g->edges = (bool**)malloc(sizeof(bool*)*max_size);
        for(int i = 0; i<max_size;i++){
            g->edges[i] = (bool*)calloc(max_size, sizeof(bool));
        }
        g->max_size=max_size;
        g->size=0;
    }
    return g;
}
void graph_destroy(graph g){
    free(g->nodes);
    for(int i = 0; i<g->max_size;i++){
        free(g->edges[i]);
    }
    free(g->edges);
    free(g);    
}

int graph_add_node(graph g, int node_value){
    if (g->size >= g->max_size){
        return -1;
    }
    g->nodes[g->size] = node_value;
    g->size++;
    return g->size - 1;
}

int graph_add_edge(graph g, int node1_id, int node2_id){
    if( node1_id < 0 || node1_id > g->size){
        return -1;
    }
    if( node2_id < 0 || node2_id > g->size){
        return -2;
    }
    g->edges[node1_id][node2_id] = true;
    return 0;
}

int graph_remove_edge(graph g, int node1_id, int node2_id){
    if( node1_id < 0 || node1_id > g->size){
        return -1;
    }
    if( node2_id < 0 || node2_id > g->size){
        return -2;
    }
    g->edges[node1_id][node2_id] = false;
    return 0;
}

int graph_search_node(graph g, int node_value){
    bool found = false;
    int i = 0;
    while (!found && i<g->size){
        if(g->nodes[i] == node_value){
            found = true;
        } else {
            i++;
        }
    }
    if (found) 
        return i;
    else 
        return -1;
}

int graph_size(graph g){
    return g->size;
}

bool graph_adjacent(graph g, int node1_id, int node2_id){
    return g->edges[node1_id][node2_id];
}

int graph_neighbors(graph g, int node, int *result){
    
}

void graph_bfs(graph g);
void graph_dfs(graph g);

bool graph_path_exist(graph g, int node1, int node2);


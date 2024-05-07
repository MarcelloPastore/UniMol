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
    int count = 0;
    for (int i = 0; i < g->size; i++){
        if (g->edges[node][i]){
            result[count]=i;
            count ++;
        }  
    }
    return count;
}

void graph_bfs(graph g, int start_node){

}

void graph_dfs_rec(graph g, int start_node, bool* visited){
    //caso base: Nodo visitato => return (mi fermo)
    if (visited[start_node]) 
        return;
    //Nota: se il nodo non ha vicini => lo visito e mi fermo
     printf("%d, ", g->nodes[start_node]);
    //passo: visito il nodo e ricorsivamente visito tutti i vicini
    int neighbors[g->size];
    int n = graph_neighbors(g, start_node, neighbors);
    visited[start_node] = true;
    for (int i = 0; i < n; i++){
        graph_dfs_rec(g, neighbors[i], visited);
    }

}
void graph_dfs(graph g, int start_node){
    //creare l'array visited
    // Versione mia
    // !bool *visited = (bool*)calloc(g->size, sizeof(bool));
    // Versione prof
    bool visited[g->size];
    for (int i = 0; i < g->size; i++){
        visited[i] = false;
    }
    //chiamare graph rec
    graph_dfs_rec(g, start_node, visited);
}

bool graph_path_exist(graph g, int node1, int node2);


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "digraph.h"
#include "queue.h"
#include "stack.h"

struct _didigraph {
    int *nodes;
    bool **edges;

    int max_size;
    int size;
};

didigraph didigraph_new(int max_size){
    struct _digraph* g = (struct _didigraph*)malloc(sizeof(struct _digraph));
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
void didigraph_destroy(digraph g){
    free(g->nodes);
    for(int i = 0; i<g->max_size;i++){
        free(g->edges[i]);
    }
    free(g->edges);
    free(g);    
}

int didigraph_add_node(didigraph g, int node_value){
    if (g->size >= g->max_size){
        return -1;
    }
    g->nodes[g->size] = node_value;
    g->size++;
    return g->size - 1;
}

int didigraph_add_edge(didigraph g, int node1_id, int node2_id){
    if( node1_id < 0 || node1_id > g->size){
        return -1;
    }
    if( node2_id < 0 || node2_id > g->size){
        return -2;
    }
    g->edges[node1_id][node2_id] = true;
    return 0;
}

int didigraph_remove_edge(didigraph g, int node1_id, int node2_id){
    if( node1_id < 0 || node1_id > g->size){
        return -1;
    }
    if( node2_id < 0 || node2_id > g->size){
        return -2;
    }
    g->edges[node1_id][node2_id] = false;
    return 0;
}

int didigraph_search_node(didigraph g, int node_value){
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

int didigraph_size(digraph g){
    return g->size;
}

bool didigraph_adjacent(didigraph g, int node1_id, int node2_id){
    return g->edges[node1_id][node2_id];
}

int didigraph_neighbors(didigraph g, int node, int *result){
    int count = 0;
    for (int i = 0; i < g->size; i++){
        if (g->edges[node][i]){
            result[count]=i;
            count ++;
        }  
    }
    return count;
}

void digraph_bfs(digraph g, int start_node){
    queue q = queue_new();
    bool visited[g->size];
    for (int i = 0; i < g->size; i++){
        visited[i] = false;
    }
    queue_add(q, start_node);
    int node_to_analyze;

    while(!queue_is_empty(q)){
        queue_poll(q, &node_to_analyze);

        if(!visited[node_to_analyze]){
            printf("Visited node: %d\n", g->nodes[node_to_analyze]);
            visited[node_to_analyze] = true;

            int neighbors[g->size];
            int n = digraph_neighbors(g, node_to_analyze, neighbors);
            for (int i = 0; i < n; i++){
                if(!visited[neighbors[i]])
                    queue_add(q, neighbors[i]);
            }
        }
    }   
    queue_destroy(q);
}

void digraph_dfs_rec(digraph g, int start_node, bool* visited){
    //caso base: Nodo visitato => return (mi fermo)
    if (visited[start_node]) 
        return;
    //Nota: se il nodo non ha vicini => lo visito e mi fermo
     printf("Visited node: %d\n", g->nodes[start_node]);
    //passo: visito il nodo e ricorsivamente visito tutti i vicini
    int neighbors[g->size];
    int n = digraph_neighbors(g, start_node, neighbors);
    visited[start_node] = true;
    for (int i = 0; i < n; i++){
        digraph_dfs_rec(g, neighbors[i], visited);
    }

}
void digraph_dfs(digraph g, int start_node){
    //creare l'array visited
    // Versione mia
    // !bool *visited = (bool*)calloc(g->size, sizeof(bool));
    // Versione prof
    bool visited[g->size];
    for (int i = 0; i < g->size; i++){
        visited[i] = false;
    }
    //chiamare digraph rec
    digraph_dfs_rec(g, start_node, visited);
}
void digraph_dfs_iter(digraph g, int start_node){
    stack s = stack_new();
    bool visited[g->size];
    for (int i = 0; i < g->size; i++){
        visited[i] = false;
    }
    stack_push(s, start_node);
    int node_to_analyze;

    while(!stack_is_empty(s)){
        stack_pop(s, &node_to_analyze);

        if(!visited[node_to_analyze]){
            printf("Visited node: %d\n", g->nodes[node_to_analyze]);
            visited[node_to_analyze] = true;

            int neighbors[g->size];
            int n = digraph_neighbors(g, node_to_analyze, neighbors);
            for (int i = n-1; i >= 0; i--){
                if(!visited[neighbors[i]])
                    stack_push(s, neighbors[i]);
            }
        }
    }   
    stack_destroy(s);
}

bool digraph_path_exist(digraph g, int node1, int node2){
    
    queue q = queue_new();
    bool visited[g->size];
    for (int i = 0; i < g->size; i++){
        visited[i] = false;
    }
    queue_add(q, node1);
    int node_to_analyze;
    int counter = 0;
    while(!queue_is_empty(q) && node_to_analyze!=node2){
        queue_poll(q, &node_to_analyze);

        if(!visited[node_to_analyze]){
            printf("Visited node: %d\n", g->nodes[node_to_analyze]);
            visited[node_to_analyze] = true;

            int neighbors[g->size];
            int n = digraph_neighbors(g, node_to_analyze, neighbors);
            for (int i = 0; i < n; i++){
                if(!visited[neighbors[i]])
                    queue_add(q, neighbors[i]);
            }
        }
        counter++;
    }   
    queue_destroy(q);
    if (counter>0)
        return true;
    return false;   
}


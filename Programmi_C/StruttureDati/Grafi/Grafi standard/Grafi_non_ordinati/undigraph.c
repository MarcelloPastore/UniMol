#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "undigraph.h"
#include "queue.h"
#include "stack.h"

struct _undigraph {
    int *nodes;
    bool **edges;

    int max_size;
    int size;
};

undigraph undigraph_new(int max_size){
    struct _undigraph* g = (struct _undigraph*)malloc(sizeof(struct _undigraph));
    if (g != NULL){
        g->nodes = (int*)malloc(sizeof(int)*max_size);
        g->edges = (bool**)malloc(sizeof(bool*)*max_size);
        for(int i = 0; i<max_size;i++){
            g->edges[i] = (bool*)calloc(max_size-i, sizeof(bool));
        }
        g->max_size=max_size;
        g->size=0;
    }
    return g;
}
/* 
?matrice triangolare inferiore
?0----
?00---
?110--
?1000-
?00100
*Matrice triangolare superiore
*00110
*-0100
*--001
*---00
*----0
*/
void undigraph_destroy(undigraph g){
    free(g->nodes);
    for(int i = 0; i<g->max_size;i++){
        free(g->edges[i]);
    }
    free(g->edges);
    free(g);    
}

int undigraph_add_node(undigraph g, int node_value){
    if (g->size >= g->max_size){
        return -1;
    }
    g->nodes[g->size] = node_value;
    g->size++;
    return g->size - 1;
}

int undigraph_add_edge(undigraph g, int node1_id, int node2_id){
    if( node1_id < 0 || node1_id > g->size){
        return -1;
    }
    if( node2_id < 0 || node2_id > g->size){
        return -2;
    }
    int i;
    int j;
    if (node1_id > node2_id){
        i=node2_id;
        j=node1_id;
    }else {
        i=node1_id;
        j=node2_id;
    }
    g->edges[i][j] = true;
    return 0;
}

int undigraph_remove_edge(undigraph g, int node1_id, int node2_id){
    if( node1_id < 0 || node1_id > g->size){
        return -1;
    }
    if( node2_id < 0 || node2_id > g->size){
        return -2;
    }
    int i;
    int j;
    if (node1_id > node2_id){
        i=node2_id;
        j=node1_id;
    }else {
        i=node1_id;
        j=node2_id;
    }
    g->edges[i][j] = false;
    return 0;
}

int undigraph_search_node(undigraph g, int node_value){
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

int undigraph_size(undigraph g){
    return g->size;
}

bool undigraph_adjacent(undigraph g, int node1_id, int node2_id){
    int i;
    int j;
    if (node1_id > node2_id){
        i=node2_id;
        j=node1_id;
    }else {
        i=node1_id;
        j=node2_id;
    }
    return g->edges[i][j];
}

int undigraph_neighbors(undigraph g, int node, int *result){
    int count = 0;
    for (int i = 0; i < g->size; i++){
        if (undigraph_adjacent(g, node, i)){ //* L'utilizzo della funzione "adiacenti" ci permette di risplvere il problema di controllo dei nodi adiacenti per i grafi non ordinati
            result[count]=i;
            count ++;
        }  
    }
    return count;
}

void undigraph_dfs_rec(undigraph g, int start_node, bool* visited){
    //caso base: Nodo visitato => return (mi fermo)
    if (visited[start_node]) 
        return;
    //Nota: se il nodo non ha vicini => lo visito e mi fermo
     printf("Visited node: %d\n", g->nodes[start_node]);
    //passo: visito il nodo e ricorsivamente visito tutti i vicini
    int neighbors[g->size];
    int n = undigraph_neighbors(g, start_node, neighbors);//* chiamando la funzione dei vicini questa funzione funziona allo stesso modo anche per i grafi indiretti
    visited[start_node] = true;
    for (int i = 0; i < n; i++){
        undigraph_dfs_rec(g, neighbors[i], visited);
    }

}
void undigraph_dfs(undigraph g, int start_node){
    //creare l'array visited
    // Versione mia
    //!  bool *visited = (bool*)calloc(g->size, sizeof(bool));  funziona ma non conviene
    // Versione prof
    bool visited[g->size];
    for (int i = 0; i < g->size; i++){
        visited[i] = false;
    }
    //chiamare undigraph rec
    undigraph_dfs_rec(g, start_node, visited);
}
void undigraph_dfs_iter(undigraph g, int start_node){
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
            int n = undigraph_neighbors(g, node_to_analyze, neighbors);
            for (int i = n-1; i >= 0; i--){
                if(!visited[neighbors[i]])
                    stack_push(s, neighbors[i]);
            }
        }
    }   
    stack_destroy(s);
}

void undigraph_bfs(undigraph g, int start_node){
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
            int n = undigraph_neighbors(g, node_to_analyze, neighbors);
            for (int i = 0; i < n; i++){
                if(!visited[neighbors[i]])
                    queue_add(q, neighbors[i]);
            }
        }
    }   
    queue_destroy(q);
}

bool undigraph_path_exist(undigraph g, int node1, int node2){
    
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
            int n = undigraph_neighbors(g, node_to_analyze, neighbors);
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


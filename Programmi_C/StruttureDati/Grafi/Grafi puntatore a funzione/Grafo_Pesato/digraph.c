#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include "digraph.h"
#include "queue.h"
#include "stack.h"

struct _digraph {
    int *nodes;
    bool **edges;
    float **weights;
    int size;
    int max_size;
};

digraph digraph_new(int max_size) {
    struct _digraph* g = (struct _digraph*)malloc(sizeof(struct _digraph));
    if (g != NULL) {
        g->nodes = (int*)malloc(sizeof(int) * max_size);
        
        g->edges = (bool**)malloc(sizeof(bool*) * max_size);
        for (int i = 0; i < max_size; i++) {
            g->edges[i] = (bool*)calloc(max_size, sizeof(bool));
        }
        
        g->weights = (float**)malloc(sizeof(float*) * max_size);
        for (int i = 0; i < max_size; i++) {
            g->weights[i] = (float*)calloc(max_size, sizeof(float));
        }
        
        g->size = 0;
        g->max_size = max_size;
    }
    
    return g;
}

void digraph_destroy(digraph g) {
    free(g->nodes);
    for (int i = 0; i < g->max_size; i++) {
        free(g->edges[i]);
        free(g->weights[i]);
    }
    free(g->edges);
    free(g->weights);
    free(g);
}

int digraph_add_node(digraph g, int node_value) {
    if (g->size >= g->max_size) {
        return -1;
    }
    
    g->nodes[g->size] = node_value;
    g->size++;
    return g->size - 1;
}

int digraph_add_edge(digraph g, int node1, int node2, float weight) {
    if (node1 < 0 || node1 >= g->size)
        return -1;
    
    if (node2 < 0 || node2 >= g->size)
        return -2;
    
    g->edges[node1][node2] = true;
    g->weights[node1][node2] = weight;
    return 0;
}

int digraph_remove_edge(digraph g, int node1, int node2) {
    if (node1 < 0 || node1 >= g->size)
        return -1;
    
    if (node2 < 0 || node2 >= g->size)
        return -2;
    
    g->edges[node1][node2] = false;
    return 0;
}

int digraph_search_node(digraph g, int node_value) {
    bool found = false;
    int i = 0;
    while (!found && i < g->size) {
        if (g->nodes[i] == node_value) {
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

int digraph_size(digraph g) {
    return g->size;
}

bool digraph_adjacent(digraph g, int node1, int node2) {
    return g->edges[node1][node2];
}

bool digraph_weight(digraph g, int node1, int node2, float* result) {
    if (!digraph_adjacent(g, node1, node2)) {
        return false;
    }
    
    *result = g->weights[node1][node2];
    
    return true;
}

int digraph_neighbors(digraph g, int node, int* result) {
    int result_size = 0;
    for (int i = 0; i < g->size; i++) {
        if (g->edges[node][i]) {
            result[result_size] = i;
            result_size++;
        }
    }
    
    return result_size;
}

void digraph_dfs_rec(digraph g, int start_node, bool* visited) {
    if (visited[start_node])
        return;
    
    printf("%d\n", g->nodes[start_node]);
    visited[start_node] = true;
    
    int neighbors[g->size];
    int num_neighbors = digraph_neighbors(g, start_node, neighbors);
    for (int i = 0; i < num_neighbors; i++) {
        digraph_dfs_rec(g, neighbors[i], visited);
    }
}

void digraph_dfs_iter(digraph g, int start_node, bool* visited) {
    stack s = stack_new();
    stack_push(s, start_node);
    
    int node_to_analyze;
    while (!stack_is_empty(s)) {
        stack_pop(s, &node_to_analyze);
        
        if (!visited[node_to_analyze]) {
            printf("%d\n", g->nodes[node_to_analyze]);
            visited[node_to_analyze] = true;
            
            int neighbors[g->size];
            int num_neighbors = digraph_neighbors(g, node_to_analyze, neighbors);
            for (int i = num_neighbors - 1; i >= 0; i--) {
                if (!visited[neighbors[i]])
                    stack_push(s, neighbors[i]);
            }
        }
    }
    
    stack_destroy(s);
}

void digraph_dfs(digraph g, int start_node) {
    bool visited[g->size];
    for (int i = 0; i < g->size; i++)
        visited[i] = false;
    
    digraph_dfs_iter(g, start_node, visited);
}

// Complessità: O(N^2)
void digraph_bfs(digraph g, int start_node) {
    bool visited[g->size];
    for (int i = 0; i < g->size; i++)
        visited[i] = false;
    
    queue q = queue_new();
    queue_add(q, start_node);
    
    int node_to_analyze;
    
    while (!queue_is_empty(q)) {
        queue_poll(q, &node_to_analyze);
        
        if (!visited[node_to_analyze]) {
            printf("%d\n", g->nodes[node_to_analyze]);
            visited[node_to_analyze] = true;
            
            int neighbors[g->size];
            int num_neighbors = digraph_neighbors(g, node_to_analyze, neighbors);
            for (int i = 0; i < num_neighbors; i++) {
                if (!visited[neighbors[i]])
                    queue_add(q, neighbors[i]);
            }
        }
    }
    
    queue_destroy(q);
}

bool digraph_path_exists(digraph g, int start_node, int target_node) {
    bool visited[g->size];
    for (int i = 0; i < g->size; i++)
        visited[i] = false;
    
    queue q = queue_new();
    queue_add(q, start_node);
    
    int node_to_analyze;
    bool found = false;
    while (!queue_is_empty(q) && !found) {
        queue_poll(q, &node_to_analyze);
        
        if (!visited[node_to_analyze]) {
            if (node_to_analyze == target_node) {
                found = true;
            } else {
                visited[node_to_analyze] = true;
                
                int neighbors[g->size];
                int num_neighbors = digraph_neighbors(g, node_to_analyze, neighbors);
                for (int i = 0; i < num_neighbors; i++) {
                    if (!visited[neighbors[i]])
                        queue_add(q, neighbors[i]);
                }
            }
        }
    }
    queue_destroy(q);
    return found;
}

// Assuming that all the edges have positive cost
float digraph_path_cost_rec(digraph g, int start_node, int target_node, bool* visited, float cumulative_cost) {
    if (visited[start_node])
        return FLT_MAX;
    
    if (start_node == target_node)
        return cumulative_cost;
    
    visited[start_node] = true;
    
    int neighbors[g->size];
    int num_neighbors = digraph_neighbors(g, start_node, neighbors);
    
    float min_cost = FLT_MAX;
    for (int i = 0; i < num_neighbors; i++) {
        float cost = digraph_path_cost_rec(g, neighbors[i], target_node, visited, cumulative_cost + g->weights[start_node][neighbors[i]]);
        
        if (cost < min_cost)
            min_cost = cost;
    }
    
    return min_cost;
}

float digraph_path_cost(digraph g, int node1, int node2) {
    bool visited[g->size];
    for (int i = 0; i < g->size; i++) {
        visited[i] = false;
    }
    
    return digraph_path_cost_rec(g, node1, node2, visited, 0);
}

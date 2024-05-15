#include <stdbool.h>

typedef struct _digraph* digraph;

digraph digraph_new(int max_size);
void digraph_destroy(digraph g);

int digraph_add_node(digraph g, int node_value);
int digraph_add_edge(digraph g, int node1, int node2, float weight);
int digraph_remove_edge(digraph g, int node1, int node2);
int digraph_search_node(digraph g, int node_value);

int digraph_size(digraph g);
bool digraph_adjacent(digraph g, int node1, int node2);
bool digraph_weight(digraph g, int node1, int node2, float* result);

int digraph_neighbors(digraph g, int node, int* result);

void digraph_dfs(digraph g, int start_node);
void digraph_bfs(digraph g, int start_node);

bool digraph_path_exists(digraph g, int node1, int node2);
float digraph_path_cost(digraph g, int node1, int node2);

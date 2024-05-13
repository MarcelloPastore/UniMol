#include <stdbool.h>

typedef struct _wegraph* wegraph;
/**
 * @brief Crea un nuovo grafo immettendo il numero massimo di nodi da inserire
 * 
 * @param max_size numero massimo di nodi
 * @return grafo
 */
wegraph wegraph_new(int max_size);
/**
 * @brief Distrugge il grafo (e la memoria allocata ad esso)
 */
void wegraph_destroy();
/**
 * @brief Aggiunge un nodo del grafo immettendone un valore 
 * 
 * @param g grafo
 * @param node_value valore del nodo  
 */
int wegraph_add_node(wegraph g, int node_value);
/**
 * @brief Aggiunge un arco associato a due nodi
 * 
 * @param g grafo
 * @param node1_id Nodo di partenza 
 * @param node2_id Nodo di arrivo
 * @return (-1 in caso di errore sul primo nodo, -2 sul secondo)
 */
int wegraph_add_edge(wegraph g, int node1_id, int node2_id);
/**
 * @brief Rimuove l'arco associato tra due nodi
 * 
 * @param g grafo
 * @param node1_id Nodo di partenza
 * @param node2_id Nodo di arrivo
 * @return (-1 in caso di errore sul primo nodo, -2 sul secondo)
 */
int wegraph_remove_edge(wegraph g, int node1_id, int node2_id);
/**
 * @brief Cerca il valore del nodo presente nel grafo
 * 
 * @param g grafo
 * @param node_value valore del nodo 
 */
int wegraph_search_node(wegraph g, int node_value);
/**
 * @brief Definisce la grandezza del grafo
 * 
 * @param g grafo
 * @return dimensione
 */
int wegraph_size(wegraph g);
/**
 * @brief cerca se esiste l'adiacenza di una coppia di nodi
 * 
 * @param g grafo
 * @param node1_id Nodo di partenza
 * @param node2_id Nodo di arrivo
 * @return true i nodi sono adiacenti
 * @return false i nodi non sono adiacenti
 */
bool wegraph_adjacent(wegraph g, int node1_id, int node2_id);
/**
 * @brief Controlla tutti i "vicini" di un nodo, NB: i nodi vicini sono quelli con achi uscenti dal nodo dato
 * 
 * @param g Grafo
 * @param node Nodo di partenza
 * @param result Array di tutti i nodi vicini del nodo dato 
 * @return int 
 */
 bool wegraph_weight(wegraph g, int node1, int node2, float* result);
int wegraph_neighbors(wegraph g, int node, int *result);
/**
 * @brief Definisce la visita del grafo in ampiezza
 * 
 * @param start_node nodo di partenza
 * @param g grafo
 */
void wegraph_bfs(wegraph g, int start_node);
/**
 * @brief Definisce la visità del grafo in profondità
 * 
 * @param start_node nodo di partenza
 * @param g Grafo
 */
void wegraph_dfs(wegraph g, int start_node);
/**
 * @brief Definisce la visita del grafo in profondità in maniera iterativa (no ricorsione in here) usando uno stack
 * 
 * @param g grafo
 * @param start_node nodo di partenza 
 */
void wegraph_dfs_iter(wegraph g, int start_node);
/**
 * @brief Verifica l'esistenza di un percorso che collega due nodi
 * 
 * @param g Grafo
 * @param node1 Nodo di partenza
 * @param node2 Nodo di arrivo
 * @return true Se il percorso esiste
 * @return false Se il percorso NON esiste
 */
bool wegraph_path_exist(wegraph g, int node1, int node2);

float wegraph_path_cost(wegraph g, int node1, int node2);
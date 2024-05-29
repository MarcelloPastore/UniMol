#include <stdbool.h>
/**
 * @brief Creazione della union con i possibili tupi da utilizzare per la  lista.
 * 
 */
typedef union _listelement {
    char cval;
    int ival;
    float fval;
    
    void* pval;
    char* sval;
} listelement;

typedef char listtype;

#define TYPE_CHAR 0
#define TYPE_INT 1
#define TYPE_FLOAT 2
#define TYPE_POINTER 3
#define TYPE_STRING 4

typedef struct _list* list;
typedef struct _iterator* iterator;
/**
 * @brief Creazione della lista
 * 
 * @param type aggiunge informazione sul tipo di dato da inserire 
 * @return list ritorna la lista vuota (lista di tipo type)
 */
list list_new(listtype type);
/**
 * @brief funizone che cancella la lista e la memoria allocata
 * 
 * @param l lista l
 */
void list_destroy(list l);
/**
 * @brief funzione che aggiunge un elemento all'ultima posizione della lista
 * 
 * @param l lista l
 * @param value valore da aggiungere
 * @return int 
 */
int  list_append(list l, listelement value);
/**
 * @brief funzione che aggiunge un elemento all'inizio della lista
 * 
 * @param l lista l
 * @param value valore da aggiungere
 */
int  list_prepend(list l, listelement value);
/**
 * @brief funzione che restituisce la dimensione della lista
 * 
 * @param l lista l
 * @return int 
 */
int  list_size(list l);
/**
 * @brief funzione che restituisce l'ultimo elemento della lista
 * 
 * @param l lista l
 * @param result elemento restituito
 * @return int 
 */
int  list_get_last(list l, listelement *result);
/**
 * @brief funzione che restituisce l'elemento ricercato nella lista
 * 
 * @param l lista l
 * @param result elemento restituito
 */
int  list_get_element(list l, int i, listelement *result);
/**
 * @brief funzione che restituisce il primo elemento della lista
 * 
 * @param l lista l
 * @param result elemento restituito
 * @return int 
 */
int  list_get_first(list l, listelement *result);
/**
 * @brief funzione che controlla se la lista è vuota
 * 
 * @param l lista l
 * @return true se la lista è vuota
 * @return false se la lista non è vuota
 */
bool list_is_empty(list l);
/**
 * @brief funzione che rimuove il primo elemento ricercato nella lista
 * 
 * @param l lista l
 * @param value valore da rimuovere
 * @return true se è stato rimosso l'elemento
 * @return false se non è stato rimosso l'elemento
 */
bool list_remove_first_value(list l, listelement value);
/**
 * @brief funzione che rimuove tutti gli elementi ricercati nella lista
 * 
 * @param l lista l
 * @param value valore da rimuovere
 * @return true se tutti gli elementi sono stati rimossi
 * @return false se sono gli elementi non stati rimossi
 */
bool list_remove_all_values(list l, listelement value);
/**
 * @brief funzione che rimuove l'iesimo elemento della lista
 * 
 * @param l lista l
 * @param i iesimo elemento da rimuovere
 * @return true elemento rimosso
 * @return false elemeno non rimosso
 */
bool list_remove_by_index(list l, int i);
/**
 * @brief funzione che rimuove tutti i duplicati di una lista
 * 
 * @param l lista l
 */
void list_remove_duplicates(list l);
/**
 * @brief 
 * 
 * @param l 
 * @param predicate 
 * @return true 
 * @return false 
 */
bool list_filter(list l, bool (*predicate)(listelement));
/**
 * @brief 
 * 
 * @param l 
 * @param f 
 */
void list_foreach(list l, void (*f)(listelement));
/**
 * @brief 
 * 
 * @param l 
 * @param initial_value 
 * @param f 
 * @return listelement 
 */
listelement list_reduce(list l, listelement initial_value, listelement (*f)(listelement, listelement));
/**
 * @brief 
 * 
 * @param l 
 * @return iterator 
 */
iterator list_iterate(list l);
/**
 * @brief 
 * 
 * @param iter 
 * @return true 
 * @return false 
 */
bool iterator_has_next(iterator iter);
/**
 * @brief 
 * 
 * @param iter 
 * @return listelement 
 */
listelement iterator_next(iterator iter);
/**
 * @brief 
 * 
 * @param iter 
 */
void iterator_destroy(iterator iter);

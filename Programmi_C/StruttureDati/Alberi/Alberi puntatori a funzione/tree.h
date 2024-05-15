typedef struct _tree* tree;
typedef struct _treenode* treenode;

/**
 * Crea un nuovo nodo di un albero.
 * @param int dato da memorizzare nel nodo
 * @return il nodo creato
 */
treenode treenode_new(int data);

/**
 * Elimina un sotto-albero che ha come radice il nodo
 * dato in input.
 * @param node radice del sotto-albero da eliminare
 */
void treenode_destroy(treenode node);

/**
 * Imposta il figlio sinistro di un dato nodo di un albero.
 * @param parent nodo padre
 * @param child nodo figlio (sinistro)
 */
void treenode_set_left(treenode parent, treenode child);

/**
 * Imposta il figlio destro di un dato nodo di un albero.
 * @param parent nodo padre
 * @param child nodo figlio (destro)
 */
void treenode_set_right(treenode parent, treenode child);

/**
 * Restituisce il figlio sinistro di un nodo.
 * @return figlio sinistro (se presente) o NULL.
 */
treenode treenode_get_left(treenode node);

/**
 * Restituisce il figlio destro di un nodo.
 * @return figlio destro (se presente) o NULL.
 */
treenode treenode_get_right(treenode node);

/**
 * Restituisce il valore memorizzato nel nodo di un albero.
 * @return il valore memorizzato nel nodo
 */
int treenode_value(treenode node);

/**
 * Crea un nuovo albero vuoto.
 * @return un albero vuoto.
 */
tree tree_new();

/**
 * Elimina l'albero dato in input.
 * @param t albero da eliminare
 */
void tree_destroy(tree t);

/**
 * Aggiunge a un albero completo un nodo in modo da mantenere l'albero completo.
 * @param t albero
 * @param value valore da aggiungere
 */
void tree_add(tree t, int value);

/**
 * Imposta la radice di un albero.
 * @param t albero
 * @param root nodo radice da impostare
 */
void tree_set_root(tree t, treenode root);

/**
 * Restituisce il nodo radice di un albero.
 * @param t albero
 * @return il nodo radice dell'albero o NULL (se è vuoto)
 */
treenode tree_get_root(tree t);

/**
 * Effettua una visita pre-order di un dato albero. Stampa il contenuto dei nodi.
 * @param t albero
 * @param f funzione da chiamare ogni volta che si visita un nodo
 */
void tree_preorder_visit(tree t, void (*f)(treenode));

/**
 * Effettua una visita in-order di un dato albero. Stampa il contenuto dei nodi.
 * @param t albero
 * @param f funzione da chiamare ogni volta che si visita un nodo
 */
void tree_inorder_visit(tree t, void (*f)(treenode));

/**
 * Effettua una visita post-order di un dato albero. Stampa il contenuto dei nodi.
 * @param t albero
 * @param f funzione da chiamare ogni volta che si visita un nodo
 */
void tree_postorder_visit(tree t, void (*f)(treenode));

/**
 * Calcola e restituisce l'altezza di un albero.
 * @param t albero
 * @return altezza dell'albero
 */
int tree_height(tree t);

/**
 * Calcola e restituisce il numero di nodi di un albero.
 * @param t albero
 * @return numero di nodi dell'albero
 */
int tree_size(tree t);

/**
 * Dato in input un albero, la funzione restituisce
 * il numero totale di foglie.
 * @param t albero
 * @return numero di foglie (0 se l'albero è vuoto)
 */
int tree_breadth(tree t);

/**
 * Calcola e restituisce il primo livello a cui si trova il valore dato in input.
 * @param t albero
 * @param value valore da ricercare nell'albero
 * @return livello a cui si trova il valore o -1 se non è presente
 */
int tree_level(tree t, int value);

/**
 * Elimina dall'albero tutti i nodi con il valore dato in input.
 * @param t albero
 * @param value valore da eliminare
 * @return numero di nodi che non ha potuto eliminare
 */
int tree_delete(tree t, int value);

/**
 * Conta il numero di occorrenze di un valore dato presenti nell'albero.
 * @param t albero
 * @param value valore di cui contare le occorrenze
 * @return numero di occorrenze di value in t
 */
int tree_count_values(tree t, int value);

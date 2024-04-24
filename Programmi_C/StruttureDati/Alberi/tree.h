

typedef struct _treenode* treenode;
typedef struct _tree* tree;

treenode treenode_new(int data);
void treenode_destroy(treenode node);
void treenode_set_left(treenode parent, treenode child);
void treenode_set_right(treenode parent, treenode child);
treenode treenode_get_left(treenode node);
treenode treenode_get_right(treenode node);
treenode tree_get_root(tree t);
int tree_get_root_data(tree t);

tree tree_new();
void tree_destroy(tree t);
void tree_set_root(tree t, treenode root);
void tree_add(tree t, int value);


void tree_preorder_visit(tree t);
void tree_inorder_visit(tree t);
void tree_postorder_visit(tree t);


int tree_size(tree t);
/**
*  dato in input un albero la funzione restituisce il numero totale di foglie
*  @param t albero
*  @return numero di foglie (0 se l'albero è vuoto)
*/
int tree_breadth(tree t);
/**
*  dato in input un albero la funzione restituisce il livello in cui si trova il primo valore
*  @param t albero
*  @return livello
*/
int tree_level(tree t, int value);
/**
 * Elimina il nodo contenente l'elemento selezionato
 * @param t albero
 * @param value valore da eliminare
 * @return numero di nodi che non ha potuto eliminare
 */ 
int tree_delete(tree t, int value);
int tree_count_values(tree t, int value);
int tree_height(tree t);
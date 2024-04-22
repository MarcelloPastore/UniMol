typedef struct _tree* tree;
typedef struct _treenode* treenode;

treenode treenode_new(int data);
void treenode_destroy(treenode node);
void treenode_set_left(treenode parent, treenode child);
void treenode_set_right(treenode parent, treenode child);
treenode treenode_get_left(treenode node);
treenode treenode_get_right(treenode node);
int treenode_value(treenode node);

tree tree_new();
void tree_destroy(tree t);
void tree_add(tree t, int value);

void tree_set_root(tree t, treenode root);
treenode tree_get_root(tree t);

void tree_preorder_visit(tree t);
void tree_inorder_visit(tree t);
void tree_postorder_visit(tree t);

int tree_height(tree t);

int tree_size(tree t);

/**
 * Dato in input un albero, la funzione restituisce
 * il numero totale di foglie.
 * @param t albero
 * @return numero di foglie (0 se l'albero è vuoto)
 */
int tree_breadth(tree t);
int tree_level(tree t, int value);

// void tree_delete_node(tree t, treenode n);

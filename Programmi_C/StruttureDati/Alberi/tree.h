

typedef struct _treenode* treenode;
typedef struct _tree* tree;

treenode treenode_create(int data);
void treenode_destroy(treenode node);
void treenode_set_left(treenode parent, treenode child);
void treenode_set_right(treenode parent, treenode child);
treenode treenode_get_left(treenode node);
treenode treenode_get_right(treenode node);
treenode tree_get_root(tree t);
int tree_get_root_data(tree t);

tree tree_create();
void tree_destroy(tree t);
void tree_set_root(tree t, treenode root);

int tree_size(tree t);
int tree_height(tree t);
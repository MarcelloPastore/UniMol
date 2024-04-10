#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"

// ! Setup delle strutture nodi e albero
struct _treenode {
    int data;
    struct _treenode* left;
    struct _treenode* right;
};
struct _tree {
    struct _treenode* root;
};
// ! Setup delle funzioni 
treenode treenode_create(int data){
    struct _treenode* node = (struct _treenode*)malloc(sizeof(struct _treenode));
    if(node != NULL){
        node->data = data;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}
void treenode_destroy(treenode node){
    if (node == NULL) return;

    treenode_destroy(node->left);
    treenode_destroy(node->right);
    free(node);
}
void treenode_set_left(treenode parent, treenode child){
    parent->left = child;
}
void treenode_set_right(treenode parent, treenode child){
    parent->right = child;
}
treenode treenode_get_left(treenode node){
    return node->left;
}
treenode treenode_get_right(treenode node){
    return node->right;
}
treenode tree_get_root(tree t){
    return t->root;
}
int tree_get_root_data(tree t){
    return t->root->data;
}
void tree_add(tree t, int value){
    treenode node = treenode_create(value);
    
}
tree tree_create(){
    struct _tree* t = (struct _tree*)malloc(sizeof(struct _tree));
    if(t != NULL){
        t->root = NULL;
    }
    return t;
}
void tree_destroy(tree t){

}
void tree_set_root(tree t, treenode root){
    t->root = root;
}

int treenode_size_rec(treenode node){
    if (node==NULL){
        return 0;
    }  
    int hl = treenode_size_rec(node->left);
    int hr = treenode_size_rec(node->right);

    return hl + hr + 1;
}   
int tree_size(tree t){
    return treenode_size_rec(t->root);
}
int treenode_height(treenode node){
    if (node == NULL) {
        return 0;
    }
    int hl = treenode_height(node->left);
    int hr = treenode_height(node->right);

    if (hl>hr)
        return hl+1;
    else 
        return hr +1;
}
int tree_height(tree t){
    return treenode_height(t->root);
}
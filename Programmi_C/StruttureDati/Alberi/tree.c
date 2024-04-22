#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"
#include "queue.h"

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
treenode treenode_new(int data){
    struct _treenode* node = (struct _treenode*)malloc(sizeof(struct _treenode));
    if(node != NULL){
        node->data = data;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}
tree tree_new(){
    struct _tree* t = (struct _tree*)malloc(sizeof(struct _tree));
    if(t != NULL){
        t->root = NULL;
    }
    return t;
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
void tree_add(tree t, int value) {
    treenode node = treenode_new(value);
    if (t->root == NULL) {
        t->root = node;
        return;
    }
    
    queue to_analyze = queue_new();
    queue_add(to_analyze, t->root);
    
    bool found = false;
    while (!queue_is_empty(to_analyze) && !found) {
        treenode current;
        queue_poll(to_analyze, (void**)&current);
        if (current->left == NULL) {
            current->left = node;
            found = true;
        } else if (current->right == NULL) {
            current->right = node;
            found = true;
        } else {
            queue_add(to_analyze, current->left);
            queue_add(to_analyze, current->right);
        }
    }
    queue_destroy(to_analyze);
}

void treenode_preorder_visit(treenode node) {
    if (node == NULL)
        return;
    
    printf("%d\n", node->data);
    treenode_preorder_visit(node->left);
    treenode_preorder_visit(node->right);
}

void treenode_inorder_visit(treenode node) {
    if (node == NULL)
        return;
    
    treenode_inorder_visit(node->left);
    printf("%d\n", node->data);
    treenode_inorder_visit(node->right);
}

void treenode_postorder_visit(treenode node) {
    if (node == NULL)
        return;
    
    treenode_postorder_visit(node->left);
    treenode_postorder_visit(node->right);
    printf("%d\n", node->data);
}

void tree_preorder_visit(tree t) {
    treenode_preorder_visit(t->root);
}

void tree_inorder_visit(tree t) {
    treenode_inorder_visit(t->root);
}

void tree_postorder_visit(tree t) {
    treenode_postorder_visit(t->root);
}

void tree_destroy(tree t){
    treenode_destroy(t->root);
    free(t);
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
/*
    ! Prof choice (better solution) 
    in treenode_size(treenode node) {
        if (node == NULL)
            return 0;
        return treenode_size(node->left) + treenode_size(node->right) +1;
    }

    Prof choice   
    tree_size_bf(){
        queue to_analyze = queue_new();
        if (root != NULL)
            queue(to_analyze, (void **) &current)
        int counter;
        while (!queue_is_empty(to_analyze)) {
            if(current->left != NULL)
                queue_add(to_analyze, current->left)
            if(current->right != NULL)
                queue_add(to_analyze, current->right)
            
            counter ++;
        }
        queue_destroy(to_analyze);
        return counter;
    }
    void treenode_size_df(treenode node, int *counter){
        if (node == NULL)
            return;
        ++(*counter);
        treenode_size_df(node->left);
        treenode_size_df(node->right);
    }
    int tree_size_df(tree t){
        int counter = 0;
        treenode_size_df(t->root, &counter);
        return counter;
    }
*/
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

int treenode_breadth(treenode node){
    if(node == NULL)
        return 0;
    if(node->left==NULL && node->right==NULL)
        return 1;
    return treenode_breadth(node->left) + treenode_breadth(node->right);
}
int tree_breadth(tree t){
    return treenode_breadth(t->root);
}
int treenode_level(treenode node, int value){
    if (node == NULL)
        return -1;
    if (node->data == value)
        return 0;
    int level_left = treenode_level(node->left, value);
    int level_right = treenode_level(node->right, value);

    if (level_left == -1 && level_right == -1)
        return -1;
    if (level_left!= -1 && level_right!=-1){
        if(level_left<level_right)
            return level_right +1;
        else    
            return level_right+1;
    }
    if (level_left!=-1)
        return level_left+1;
    else
        return level_right+1;
}
int tree_level(tree t, int value){
    return treenode_level(t->root, value);
}



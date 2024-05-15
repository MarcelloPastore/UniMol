#include <stdlib.h>
#include "tree.h"
#include "queue.h"

struct _treenode {
    int data;
    struct _treenode* left;
    struct _treenode* right;
};

struct _tree {
    struct _treenode* root;
};

// O(1)
treenode treenode_new(int data) {
    struct _treenode* node = (struct _treenode*)malloc(sizeof(struct _treenode));
    
    if (node != NULL) {
        node->data = data;
        node->left = NULL;
        node->right = NULL;
    }
    
    return node;
}

void tree_destroy(tree t) {
    tree_postorder_visit(t, free);
    free(t);
}

void treenode_set_left(treenode parent, treenode child) {
    parent->left = child;
}

void treenode_set_right(treenode parent, treenode child) {
    parent->right = child;
}

treenode treenode_get_left(treenode node) {
    return node->left;
}

treenode treenode_get_right(treenode node) {
    return node->right;
}

int treenode_value(treenode node) {
    return node->data;
}

tree tree_new() {
    struct _tree* t = (struct _tree*)malloc(sizeof(struct _tree));
    
    if (t != NULL) {
        t->root = NULL;
    }
    
    return t;
}

void tree_set_root(tree t, treenode root) {
    t->root = root;
}

treenode tree_get_root(tree t) {
    return t->root;
}


int treenode_height(treenode node) {
    if (node == NULL)
        return 0;
    
    int hl = treenode_height(node->left);
    int hr = treenode_height(node->right);
    
    if (hl > hr)
        return hl + 1;
    else
        return hr + 1;
}

int tree_height(tree t) {
    if (t->root == NULL)
        return 0;
    
    return treenode_height(t->root) - 1;
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

void treenode_preorder_visit(treenode node, void (*f)(treenode)) {
    if (node == NULL)
        return;
    
    f(node);
    treenode_preorder_visit(node->left, f);
    treenode_preorder_visit(node->right, f);
}

void treenode_inorder_visit(treenode node, void (*f)(treenode)) {
    if (node == NULL)
        return;
    
    treenode_inorder_visit(node->left, f);
    f(node);
    treenode_inorder_visit(node->right, f);
}

void treenode_postorder_visit(treenode node, void (*f)(treenode)) {
    if (node == NULL)
        return;
    
    treenode_postorder_visit(node->left, f);
    treenode_postorder_visit(node->right, f);
    f(node);
}

void tree_preorder_visit(tree t, void (*f)(treenode)) {
    treenode_preorder_visit(t->root, f);
}

void tree_inorder_visit(tree t, void (*f)(treenode)) {
    treenode_inorder_visit(t->root, f);
}

void tree_postorder_visit(tree t, void (*f)(treenode)) {
    treenode_postorder_visit(t->root, f);
}

int treenode_size_rec(treenode node) {
    if (node == NULL)
        return 0;
    
    return treenode_size_rec(node->left) + treenode_size_rec(node->right) + 1;
}

int tree_size(tree t) {
    return treenode_size_rec(t->root);
}

int tree_size_bf(tree t) {
    queue to_analyze = queue_new();
    if (t->root != NULL)
        queue_add(to_analyze, t->root);
    
    int counter = 0;
    while (!queue_is_empty(to_analyze)) {
        treenode current;
        queue_poll(to_analyze, (void**)&current);
        
        if (current->left != NULL)
            queue_add(to_analyze, current->left);
        
        if (current->right != NULL)
            queue_add(to_analyze, current->right);
        
        counter++;
    }
    queue_destroy(to_analyze);
    
    return counter;
}

void treenode_size_df(treenode node, int* counter) {
    if (node == NULL)
        return;
    
    ++(*counter);
    treenode_size_df(node->left, counter);
    treenode_size_df(node->right, counter);
}

int tree_size_df(tree t) {
    int counter = 0;
    treenode_size_df(t->root, &counter);
    return counter;
}

int treenode_breadth(treenode node) {
    if (node == NULL)
        return 0;
    
    if (node->left == NULL && node->right == NULL)
        return 1;
    
    return treenode_breadth(node->left) + treenode_breadth(node->right);
}

int tree_breadth(tree t) {
    return treenode_breadth(t->root);
}

int treenode_level(treenode node, int value) {
    if (node == NULL)
        return -1;
    
    if (node->data == value)
        return 0;
    
    int level_left = treenode_level(node->left, value);
    int level_right = treenode_level(node->right, value);
    
    if (level_right == -1 && level_left == -1)
        return -1;
    
    if (level_left != -1 && level_right != -1) {
        if (level_left < level_right)
            return level_left + 1;
        else
            return level_right + 1;
    }
    
    if (level_left != -1) {
        return level_left + 1;
    } else {
        return level_right + 1;
    }
}

int tree_level(tree t, int value) {
    return treenode_level(t->root, value);
}

treenode treenode_delete_node(treenode node, int value, int* counter) {
    if (node == NULL)
        return NULL;
    
    node->left  = treenode_delete_node(node->left, value, counter);
    node->right = treenode_delete_node(node->right, value, counter);
    
    if (node->data == value) {
        if (node->right != NULL && node->left != NULL)
            ++(*counter);
        else {
            treenode next_root;
            
            if (node->left == NULL) {
                next_root = node->right;
            } else {
                next_root = node->left;
            }
            
            free(node);
            return next_root;
        }
    }
    
    return node;
}


int treenode_count_values(treenode node, int value) {
    if (node == NULL) {
        return 0;
    }
    
    int total = 0;
    if (node->data == value)
        total++;
    
    total += treenode_count_values(node->left, value);
    total += treenode_count_values(node->right, value);
    
    return total;
}

int tree_count_values(tree t, int value) {
    return treenode_count_values(t->root, value);
}

int tree_delete(tree t, int value) {
    int counter = 0;
    t->root = treenode_delete_node(t->root, value, &counter);
    return counter;
}

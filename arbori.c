// arbori.c
#include <stdio.h>
#include <stdlib.h>
#include "arbori.h"

t_nod_arb *make_root(t_arbore *a, int key) {
    t_nod_arb *new_node = (t_nod_arb *)malloc(sizeof(t_nod_arb));
    if (!new_node) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    new_node->key = key;
    new_node->left = new_node->right = new_node->parent = NULL;
    a->root = new_node;
    return new_node;
}

void inorder_walk(t_nod_arb *root) {
    if (root != NULL) {
        inorder_walk(root->left);
        printf("%d ", root->key);
        inorder_walk(root->right);
    }
}

void preorder_walk(t_nod_arb *root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorder_walk(root->left);
        preorder_walk(root->right);
    }
}

void postorder_walk(t_nod_arb *root) {
    if (root != NULL) {
        postorder_walk(root->left);
        postorder_walk(root->right);
        printf("%d ", root->key);
    }
}

t_nod_arb *create_node(int key) {
    t_nod_arb *new_node = (t_nod_arb *)malloc(sizeof(t_nod_arb));
    if (!new_node) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    new_node->key = key;
    new_node->left = new_node->right = new_node->parent = NULL;
    return new_node;
}

t_nod_arb *tree_min(t_nod_arb *n) {
    while (n && n->left != NULL)
        n = n->left;
    return n;
}

t_nod_arb *tree_max(t_nod_arb *n) {
    while (n && n->right != NULL)
        n = n->right;
    return n;
}

t_nod_arb *tree_search(t_nod_arb *n, int key) {
    if (n == NULL || n->key == key)
        return n;
    if (key < n->key)
        return tree_search(n->left, key);
    else
        return tree_search(n->right, key);
}

t_nod_arb *tree_succesor(t_nod_arb *n) {
    if (n->right != NULL)
        return tree_min(n->right);
    t_nod_arb *y = n->parent;
    while (y != NULL && n == y->right) {
        n = y;
        y = y->parent;
    }
    return y;
}

t_nod_arb *it_tree_search(t_nod_arb *n, int key) {
    while (n != NULL && key != n->key) {
        if (key < n->key)
            n = n->left;
        else
            n = n->right;
    }
    return n;
}

void transplant(t_arbore *a, t_nod_arb *u, t_nod_arb *v) {
    if (u->parent == NULL)
        a->root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    if (v != NULL)
        v->parent = u->parent;
}

void tree_insert(t_arbore *a, t_nod_arb *n) {
    t_nod_arb *y = NULL;
    t_nod_arb *x = a->root;
    while (x != NULL) {
        y = x;
        if (n->key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    n->parent = y;
    if (y == NULL)
        a->root = n;
    else if (n->key < y->key)
        y->left = n;
    else
        y->right = n;
}

void tree_delete(t_arbore *a, t_nod_arb *n) {
    if (n->left == NULL)
        transplant(a, n, n->right);
    else if (n->right == NULL)
        transplant(a, n, n->left);
    else {
        t_nod_arb *y = tree_min(n->right);
        if (y->parent != n) {
            transplant(a, y, y->right);
            y->right = n->right;
            y->right->parent = y;
        }
        transplant(a, n, y);
        y->left = n->left;
        y->left->parent = y;
    }
    free(n);
}

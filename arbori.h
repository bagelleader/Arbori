#ifndef ARBORI_H_INCLUDED
#define ARBORI_H_INCLUDED

typedef struct nod_arb {
    int key;
    struct nod_arb *left, *right, *parent;
} t_nod_arb;

typedef struct {
    t_nod_arb *root;
} t_arbore;

t_nod_arb *make_root(t_arbore *a, int key);
void inorder_walk(t_nod_arb *root);
void preorder_walk(t_nod_arb *root);
void postorder_walk(t_nod_arb *root);
t_nod_arb *create_node(int key);
t_nod_arb *tree_min(t_nod_arb *n);
t_nod_arb *tree_max(t_nod_arb *n);
t_nod_arb *tree_search(t_nod_arb *n, int key);
t_nod_arb *tree_succesor(t_nod_arb *n);
t_nod_arb *it_tree_search(t_nod_arb *n, int key);
void transplant(t_arbore *a, t_nod_arb *u, t_nod_arb *v);
void tree_insert(t_arbore *a, t_nod_arb *n);
void tree_delete(t_arbore *a, t_nod_arb *n);

#endif // ARBORI_H_INCLUDED

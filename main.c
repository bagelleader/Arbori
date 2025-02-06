#include <stdio.h>
#include <stdlib.h>
#include "arbori.h"

int main() {
    t_arbore T = {NULL}; // Inițializare arbore
    t_nod_arb *s, *r, *n;
    int x;

    printf("Nodul radacina cu cheia x=");
    scanf("%d", &x);
    r = make_root(&T, x);

    printf("Introduceti x pana la citirea 0\n");
    printf("x=");
    scanf("%d", &x);

    while (x != 0) {
        n = create_node(x);
        if (n == NULL) {
            printf("Eroare la alocarea nodului!\n");
            return 1;
        }
        tree_insert(&T, n);
        printf("x=");
        scanf("%d", &x);
    }

    printf("In-order walk:\n");
    inorder_walk(r);
    printf("\nPre-order walk:\n");
    preorder_walk(r);
    printf("\nPost-order walk:\n");
    postorder_walk(r);
    printf("\n");

    printf("Regasire nod cu cheia x=");
    scanf("%d", &x);
    n = it_tree_search(r, x);
    if (n != NULL)
        printf("Nodul cu cheia %d gasit iterativ\n", n->key);
    else
        printf("Nodul nu a fost gasit iterativ\n");

    n = tree_search(r, x);
    if (n != NULL)
        printf("Nodul cu cheia %d gasit recursiv\n", n->key);
    else
        printf("Nodul nu a fost gasit recursiv\n");

    n = tree_min(r);
    printf("Tree minimum: %d\n", n->key);

    n = tree_max(r);
    printf("Tree maximum: %d\n", n->key);

    printf("Succesorul lui x=");
    scanf("%d", &x);
    n = tree_search(r, x);
    s = tree_succesor(n);
    if (s != NULL)
        printf("Nod succesor: %d\n", s->key);
    else
        printf("NULL\n");

    printf("Stergere nod cu cheia x=");
    scanf("%d", &x);
    n = tree_search(r, x);
    if (n != NULL) {
        tree_delete(&T, n);
        printf("Nod sters \n");
        inorder_walk(T.root); // Se trece arborele actualizat
    } else {
        printf("Nod negasit!\n");
    }

    return 0;
}


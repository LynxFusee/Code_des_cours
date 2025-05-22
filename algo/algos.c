#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node *fg;
    struct node *fd;
};

int Hauteur(struct node *R){
    if (R == NULL) {
        return -1;
    }
    D = Hauteur(R->fd);
    G = Hauteur(R->fg);
    if (D > G) {
        return D+1;
    }
    return G+1;
}

int Profondeur_d_un_noeud(struct node *R, struct node *C) {
    
}

void Parc_Prof_Rec(struct node *R) {
    if (R == NULL) { return; }
    printf("Prefix = %d\n", R->num);
    Parc_Prof_Rec(R->fg);
    printf("Infix = %d\n", R->num);
    Parc_Prof_Rec(R->fd);
    printf("Suffix = %d\n", R->num);
}

void Parc_Prof_Iter(struct node *R) {
    stack *S = stack();
    struct node *a;
    if (R != NULL) {
        S = Push(S, R);
        while (S.isempty != 0) {
            a = Pop(S);
            printf("Prefixe = %d\n", a->num);
            if (a->fd != NULL) {
                S = Push(S, a->fd);
            }
            if (a->fg != NULL) {
                S = Push(S, a->fg);
            }
        }
    }
}

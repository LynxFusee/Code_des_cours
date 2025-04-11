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



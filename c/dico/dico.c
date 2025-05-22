#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list_c {
    char *clef;
    int value;
    struct list_c *next;
};

struct dico {
    int size;
    struct list_c **tab_lc;
};

int hash(char *str) {
    int a = str[0] + 55;
    a++;
    a /= 2;
    a += 52;
    a /= 8;
    a += str[1];
    return a;
}

struct list_c *create(char *clef, int value){
    struct list_c *new = malloc(sizeof(struct list_c));
    new->clef = clef,
    new->value = value;
    new->next = NULL;
    return new;
}

struct list_c *add(struct list_c *base, char *clef, int value){
    if (base == NULL){
        struct list_c *new = create(clef, value);
        return new;
    }
    struct list_c *scan = base;
    while (scan->next != NULL ){
        if (strcmp(scan->clef, clef) == 0){
            scan->value = value;
            return base;
        }
        scan = scan->next;
    }
    struct list_c *new = create(clef, value);
    new->next = base;
    return new;
}

struct list_c *supp(struct list_c *base, char *clef){
    struct list_c *scan = base;
    while (scan != NULL || strcmp(scan->clef, clef))
        scan = scan->next;
    if (scan == NULL)
        return base;
    if (scan == base){
        base = base->next;
        free(scan);
        return base;
    }
    struct list_c *before = base;
    while (before->next != scan)
        before = before->next;
    before->next = scan->next;
    free(scan);
    return base;
}

struct list_c *destroy(struct list_c *base){
    struct list_c *des = base;
    while (base != NULL){
        base = base->next;
        free(des);
        des = base;
    }
    return base;
}

struct dico *create_dico (int size) {
    struct dico *new = malloc(sizeof(struct dico));
    new->size = size;
    new->tab_lc = calloc(size, sizeof(struct list_c *));
    return new;
}

void clear_dico(struct dico *dico){
    for (int i = 0; i < dico->size; i++)
        dico->tab_lc[i] = destroy(dico->tab_lc[i]);
}

void destroy_dico(struct dico *dico){
    clear_dico(dico);
    free(dico->tab_lc);
    free(dico);
}

void add_to_dico (struct dico *dico, char *clef, int value){
    int hash_c = hash(clef);
    hash_c %= dico->size;
    dico->tab_lc[hash_c] = add(dico->tab_lc[hash_c], clef, value);
}


int main(void){
    struct dico *test = create_dico(10);
    destroy_dico(tect);
    return 0;
}

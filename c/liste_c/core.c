#include <stdio.h>
#include <stdlib.h>

struct list {
	struct node *first;
	struct node *last;
	int size;
};

struct node {
	int data;
	struct node *next;
	struct node *previous;
};

struct list *create(void){
	struct list *new = malloc(sizeof(struct list));
	new->first = NULL;
	new->last = NULL;
	new->size = 0;
	return new;
}

void destroy(struct list *des) {
	if (des == NULL) {
		return;
    }
    if (des->first != NULL) {
        struct node *first = des->first;
        struct node *second = first;
        while (first->next != NULL){
            first = first->next;
            free(second);
            second=first;
        }
    }
	free(des);
}

void add(struct list *add, int data) {
    struct node *next = malloc(sizeof(struct node));
    next->previous = add->last;
    if (add->last != NULL) {
        add->last->next = next;
    }
    if (add->first == NULL) {
        add->first = next;
    }
    next->next = NULL;
    next->data = data;
    add->last = next;
    add->size++;
}

void supp(struct list *supp, int pos) {
    struct node *tosupp = supp->first;
    int b = 0;
    while (b != pos) {
        tosupp = tosupp->next;
        b++;
    }
    struct node *pre = tosupp->previous;
    struct node *aft = tosupp->next;
    if(pre != NULL) {
        pre->next = aft;
    }
    if (aft != NULL){
        aft->previous = pre;
    }
    if (aft == NULL){
        supp->last = pre;
    }
    if (pre == NULL){
        supp->first = aft;
    }
    free(tosupp);
}





int main(void)
{
	return 0;
}

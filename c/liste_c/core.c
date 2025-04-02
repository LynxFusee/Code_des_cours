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
    struct node *first = des->first;
    struct node *second = first;
    while (first->next != NULL){
        first = first->next;
        free(second);
        second=first;
    }
	free(des);
}








int main(void)
{
	return 0;
}

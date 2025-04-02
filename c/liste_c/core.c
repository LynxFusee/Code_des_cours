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
	if (des == NULL)
		return;
	while (des->first != NULL){
		
	}
	free(des);
}








int main(void)
{
	return 0;
}

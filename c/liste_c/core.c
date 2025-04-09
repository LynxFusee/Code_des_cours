#include <stdio.h>
#include <stdlib.h>

struct list {
	struct node *first;
	struct node *last;
	int size;
};

struct node {
	int data;
    int index;
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

void add_to_end(struct list *add, int data) {
    struct node *next = malloc(sizeof(struct node));
    next->previous = add->last;
    if (add->last != NULL) {
        add->last->next = next;
    }
    if (add->first == NULL) {
        add->first = next;
        next->index = 0;
    }
    else {
        next->index = add->last->index + 1;
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

int add_to_index(struct list *add, int pos, int data) {
    struct node *scan = add->first;
    struct node *new = malloc(sizeof(struct node));
    new->index = pos;
    new->data = data;
    if (scan != NULL)
    {
        if(pos == 0){
            new->next = add->first;
            new->previous = NULL;
            add->first->previous = new;
            add->first = new;
        }
        else {
            while (scan->index != pos-1) {
                if (scan->next == NULL) {
                    free(new);
                    return 1;
                }
                scan = scan->next;
            }
            new->next = scan->next;
            new->previous = scan;
            scan->next = new;
            new->next->previous = new;
        }
        scan = new->next;
        while (scan != NULL) {
            scan->index++;
            scan = scan->next;
        }
    }
    else {
        if (pos != 0) {
            free(new);
            return 1;
        }
        add_to_end(add,data);
        return 0;
    }
}

void print_list(struct list *p) {
    struct node *a = p->first;
    while( a != NULL) {
        printf("%d : %d\n", a->index, a->data);
        a = a->next;
    }
}




int main(void)
{
    struct list *a = create();
    add_to_index(a, 0, 3);
    add_to_index(a, 0, 1);
    add_to_index(a, 1, 2);
    add_to_end(a, 4);
    print_list(a);
    destroy(a);
	return 0;
}

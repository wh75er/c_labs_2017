#include <stdio.h>
#include <stdlib.h>

typedef struct node node_t;

struct node
{
	void *data;
	node_t *next;
};

 

void push(node_t** head, int item)
{
	node_t* tmp = (node_t*)malloc(sizeof(node_t));
        if(!tmp) {
                exit(0);
        }
		tmp->data = malloc(sizeof(int));
        *((int *)tmp->data) = item;
        tmp->next = NULL;

        if(*head) {
                node_t* tmp_next = *head;
                while(tmp_next->next) {
                        tmp_next = tmp_next->next;
                }
                tmp_next->next = tmp;
        }
        else {
                *head = tmp;
        }
}

int len(const node_t *head)
{
	node_t* tmp = (node_t*)head;
	int count = 0;

	while(tmp) {
		count++;
		tmp = tmp->next;
	}

	return count;
}

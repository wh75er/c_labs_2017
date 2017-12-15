#include "struct.h"


void push(node_t** head, int item)
{
	if(!head)
		return;
	
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

void pushNode(node_t** source, node_t **node, node_t** dest)
{
	node_t *grab = *node;

	if(*node == *source) {
		grab = *source;
		*source = (*source)->next;
		*node = *source;
	} else {
		node_t *tmp = *source;
		while(tmp->next != *node) {
			tmp = tmp->next;
		}
		grab = *node;
		tmp->next = tmp->next->next;
		*node = (*node)->next;
	}
	
	//now we have to put grab inside dest in the last position;
	if(!*dest) {
		*dest = grab;
		grab->next = NULL;
	} else {
		node_t* tmp = *dest;
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = grab;
		grab->next = NULL;
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

void freeMem(node_t **head)
{
	if(!*head)
		return;

	node_t *tmp = *head;

	while(tmp) {
		*head = tmp;
		tmp = tmp->next;
		free((*head)->data);
		free(*head);
	}
}

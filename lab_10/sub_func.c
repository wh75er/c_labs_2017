#include "sub_func.h"


void* pop_front(node_t **head)
{	
	if(!(*head->next))
		return NULL;

	void* data = *head->data;
	node_t *tmp = *head;
	*head = *head->next;
	free(tmp);

	return data;
	
}


void insert(node_t **head, node_t *elem, node_t *before)
{
	if(before == *head) {
		elem->next = *head;
		*head = elem;
	} else {
	
		node_t tmp;
		tmp.next = before->next;
		tmp.data = before->data;
		before->next = elem;
		before->data = elem->data;
	
		elem->data = tmp.data;
		elem->next = tmp.next;
	}
}

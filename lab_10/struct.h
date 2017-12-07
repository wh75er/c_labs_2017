#ifndef __STRUCT_H__
#define __STRUCT_H__


#include <stdio.h>
#include <stdlib.h>

typedef struct node node_t;

struct node
{
	void *data;
	node_t *next;
};

 

void push(node_t** head, int item);
int len(const node_t *head);
void freeMem(node_t **head);


#endif

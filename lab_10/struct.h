#include <stdio.h>
#include <stdlib.h>

typedef struct node node_t;

struct node
{
	void *data;
	node_t *next;
};

#include "struct.h"
#include "stdlib.h"
#define DEFAULT_SIZE 100

enum{
	OK = 0,
	FILE_OPEN_ERROR = 1,
	ARGS_ERROR,
	FAILED_TO_INIT,
	REVERSE_NULL_NODE_ERROR,
	NOTHING_TO_SORT,
};


int fileOpen(FILE **f, const char *name);
int initNode(node_t **head, FILE *f);
int reverse(node_t **head);
int sort(node_t **mergedHead, node_t **head);

int argsInit(int argc);
int isError(int code);



int main(int argc, char **argv)
{
	FILE* f;
	if(isError(argsInit(argc))) {
		return 1;
	}
	if(isError(fileOpen(&f, argv[1]))) {
		return 1;
	}
	node_t *head = NULL;
	if(isError(initNode(&head, f))) {
		return 1;
	}
#ifdef DEBUG
	node_t *tmp = head;
	while(tmp) {
		printf("--%d\n", *((int *)tmp->data));
		tmp = tmp->next;
	}
#endif
	if(isError(reverse(&head))) {
		return 1;
	}
#ifdef DEBUG
	tmp = head;
	while(tmp) {
		printf("%d\n", *((int *)tmp->data));
		tmp = tmp->next;
	}
#endif
	node_t *mergedHead;
	if(isError(sort(&mergedHead, &head))) {
		return 1;
	}
	return 0;
}



int cmp(const void *a, const void *b)
{
	if(*((int*)a) > *((int*)b))
		return 1;
	if(*((int*)a) == *((int*)b))
		return 0;
	if(*((int*)a) < *((int*)b))
		return -1;
}



node_t* sorted_merge(node_t **head_a, node_t **head_b, int (*cmp)(const void *a, const void *b))
{
	node_t* mergedNode = NULL;

	if(len(*head_a) < len(*head_b)) {
		node_t *tmp = *head_b;
		*head_b = *head_a;
		*head_a = tmp;
	}

	int currentVar, countBpass = 0, count = 0;
	node_t* a = *head_a, *b, *prev = *head_a;
	while(a) {
		b = *head_b;
		count = 0;
		while(b) {
			count++;
			if(cmp((int*)b->data, (int*)a->data) < 0  || !cmp((int*)b->data, (int*)a->data)) {
				if(count > countBpass) {
					push(&mergedNode, *((int*)b->data));
					countBpass++;
				}
			}
			b = b->next;
		}
		push(&mergedNode, *((int*)a->data));
		prev = a;
		a = a->next;
	}
	b = *head_b;
	while(b) {
		if(cmp((int*)b->data, (int*)prev->data) > 0) 
			push(&mergedNode, *((int*)b->data));
		b = b->next;
	}
	
	

	return mergedNode;
}



void front_back_split(node_t *head, node_t **back)
{
	node_t** adresses = (node_t **)malloc(sizeof(node_t*) * DEFAULT_SIZE);
	int count = 0;
	node_t *tmp = head;
	while(tmp) {
		if(!count && !(count + 1 % 100))
			adresses = (node_t **)realloc(adresses, sizeof(node_t*) * (count + 1 + DEFAULT_SIZE));
		adresses[count] = tmp;
		tmp = tmp->next;
		count++;
	}
	
	if(count >= 2) {
		node_t *prev = adresses[count / 2 - 1 + count % 2];
		prev->next = NULL;

		*back = adresses[count / 2 + count % 2];
	}

	free(adresses);
}



void bubbleSort(node_t **head, int (*cmp)(const void *a, const void *b))
{
	int length = len(*head);
	node_t *tmp;
	for(int i = 0; i < length; i++)
	{
		tmp = *head;
		while(tmp->next){
			if(cmp((int*)tmp->data, (int*)(tmp->next)->data) > 0) {
				int tmpSwap = *((int*)tmp->data);
				*((int*)tmp->data) = *((int*)(tmp->next)->data);
				*((int*)(tmp->next)->data) = tmpSwap;
			}
			tmp = tmp->next;
		}
	}
}



int sort(node_t **mergedHead, node_t **head)
{
	if(!*head)
		return REVERSE_NULL_NODE_ERROR;
	if(len(*head) == 1)
		return NOTHING_TO_SORT;

	node_t *back = NULL;
	front_back_split(*head, &back);

	bubbleSort(head, cmp);
	bubbleSort(&back, cmp);

	node_t *tmp = *head;
	while(tmp) {
		printf("--%d\n", *((int *)tmp->data));
		tmp = tmp->next;
	}

	tmp = back;
	while(tmp) {
		printf("%d\n", *((int *)tmp->data));
		tmp = tmp->next;
	}

	*mergedHead = sorted_merge(head, &back, cmp);

	tmp = *mergedHead;
	while(tmp) {
		printf("~%d\n", *((int *)tmp->data));
		tmp = tmp->next;
	}

	return OK;
}



int reverse(node_t **head)
{
	if(!*head)
		return REVERSE_NULL_NODE_ERROR;

	node_t *tmp = *head;
	node_t *next = *head;
	node_t *prev = *head;
	while(tmp->next) {
		next = tmp->next;
		tmp->next = prev;
		prev = tmp;
		tmp = next;
	}
	tmp->next = prev;
	(*head)->next = NULL;
	*head = tmp;
	
	return OK;
}



int initNode(node_t **head, FILE *f)
{
	*head = NULL;
	int num;
	while(!feof(f)) {
		if(fscanf(f, "%d", &num)) {
			push(head, num);
		}
		else
			return FAILED_TO_INIT;
	}
	return OK;
}



int fileOpen(FILE **f, const char *name)
{
	*f = fopen(name, "r");
	if(!*f) {
		return FILE_OPEN_ERROR;
	}
	return OK;
}

int argsInit(int argc)
{
	if(argc != 2)
		return ARGS_ERROR;

	return OK;
}

int isError(int code)
{
	if(code == FILE_OPEN_ERROR)
		printf("File open error! Check your input.\n");
	if(code == ARGS_ERROR)
		printf("Input parameter error! Check your arguments.\n");
	if(code == FAILED_TO_INIT)
		printf("Failed to init node!\n");
	if(code == REVERSE_NULL_NODE_ERROR)
		printf("You cant reverse null node!\n");
	if(code == NOTHING_TO_SORT)
		printf("There is nothing to do with node, which have only one element.\n");
	return code;
}

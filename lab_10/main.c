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

void writeToFile(int code, node_t* head, const char* name);

int argsInit(int argc);
int isError(int code, node_t **head, const char* name);



int main(int argc, char **argv)
{
	FILE* f;
	if(isError(argsInit(argc), NULL, argv[2])) {
		return 1;
	}
	if(isError(fileOpen(&f, argv[1]), NULL, argv[2])) {
		return 1;
	}
	node_t *head = NULL;
	if(isError(initNode(&head, f), &head, argv[2])) {
		fclose(f);
		return 1;
	}
	if(isError(reverse(&head), &head, argv[2])) {
		return 1;
	}
	node_t *mergedHead = NULL;
	if(isError(sort(&mergedHead, &head), &head, argv[2])) {
		freeMem(&mergedHead);
		return 1;
	}
	writeToFile(OK, mergedHead, argv[2]);

	freeMem(&head);
	freeMem(&mergedHead);
	return 0;
}



void writeToFile(int code, node_t* head, const char* name)
{
	FILE *f = fopen(name, "w");
	
	node_t* tmp = head;
	while(tmp) {
		fprintf(f, " %d", *((int*)tmp->data));
		tmp = tmp->next;
	}
	fprintf(f, "\n");
	

	fclose(f);
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
	
	freeMem(head_a);
	freeMem(head_b);

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
#ifdef DEBUG
	while(tmp) {
		printf("--%d\n", *((int *)tmp->data));
		tmp = tmp->next;
	}
#endif

#ifdef DEBUG
	tmp = back;
	while(tmp) {
		printf("%d\n", *((int *)tmp->data));
		tmp = tmp->next;
	}
#endif

	*mergedHead = sorted_merge(head, &back, cmp);

#ifdef DEBUG
	tmp = *mergedHead;
	while(tmp) {
		printf("~%d\n", *((int *)tmp->data));
		tmp = tmp->next;
	}
#endif

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

	fclose(f);
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
	if(argc != 3)
		return ARGS_ERROR;

	return OK;
}

int isError(int code, node_t **head, const char* name)
{
	if(code == FILE_OPEN_ERROR) {
		FILE *f = fopen(name, "w");
		freeMem(head);
		fprintf(f, "File open error! Check your input.\n");
		fclose(f);
	}
	if(code == ARGS_ERROR) {
		FILE *f = fopen(name, "w");
		freeMem(head);
		fprintf(f, "Input parameter error! Check your arguments.\n");
		fclose(f);
	}
	if(code == FAILED_TO_INIT) {
		FILE *f = fopen(name, "w");
		freeMem(head);
		fprintf(f, "Failed to init node!\n");
		fclose(f);
	}
	if(code == REVERSE_NULL_NODE_ERROR) {
		FILE *f = fopen(name, "w");
		freeMem(head);
		fprintf(f, "You cant reverse null node!\n");
		fclose(f);
	}
	if(code == NOTHING_TO_SORT) {
		FILE *f = fopen(name, "w");
		freeMem(head);
		fprintf(f, "There is nothing to do with node, which have only one element.\n");
		fclose(f);
	}

	return code;
}

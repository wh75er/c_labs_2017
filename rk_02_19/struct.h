#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 50


typedef struct linked_list list;

struct linked_list
{
	char name[MAX_LEN];
	char phone[MAX_LEN];
	char adress[MAX_LEN];
	list* next;
};


void push(list **head, char *n, char* p, char* a)
{
	list* tmp = (list*)malloc(sizeof(list));
	if(tmp == NULL){
		exit(0);
	}

	strcpy(tmp->name, n);
	strcpy(tmp->phone, p);
	strcpy(tmp->adress, a);
	tmp->next = NULL;


	if(!(*head)) {
		*head = tmp;
	}
	else {
		list* tmp_move = *head;
		while(tmp_move->next)
			tmp_move = tmp_move->next;
		tmp_move->next = tmp;
	}
}

void pop(list** head, list** node) //remove node with adress node;
{
	if(!*head)
		return;
	if(*head == *node) {
		*head = (*head)->next;
		free(*node);
		*node = *head;
	} else {
		list* tmp = *head;
		while(tmp->next) {
			if(tmp->next == *node) {
				tmp->next = tmp->next->next;
				free(*node);
				*node = tmp->next;
				break;
			}
			tmp = tmp->next;
		}
	}
}

void filter(list **head, const char* n)
{
	if(!*head)
		return;
	list *tmp = *head;
	int flag = 0;
	while(tmp) {
		flag = 0;
		if(strcmp(tmp->name, n)) {
			pop(head, &tmp);
			flag = 1;
		}
		if(!flag)
			tmp = tmp->next;
	}
}

list* search(list **head, char* p)
{
	if(!*head)
		return NULL;
	
	list* res = NULL;
	list* tmp = *head;
	while(!res && tmp) {
		if(!strcmp(tmp->phone, p)) {
			res = tmp;
		}
		tmp = tmp->next;
	}
	
	return res;
}

void printList(const list* head)
{
	if(!head)
		return;
	list* tmp = (list*)head;
	
	printf("\n\tNAME\t|\tPHONE\t|\tADRESS\t|\n");
	while(tmp) {
		printf("\n\t%s\t\t%s\t\t%s\n", tmp->name, tmp->phone, tmp->adress);
		tmp = tmp->next;
	}
	printf("\n");
}

void removeEOL(char **str)
{
	char *pa = *str;
	while(*pa != '\0') {
		if(*pa == '\n') {
			*pa = *(pa + 1);
			break;
		}
		pa++;
	}
}

void freeMem(list *head)
{
	if(!head)
		return;

	freeMem(head->next);
	free(head);
}

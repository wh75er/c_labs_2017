#include "struct.h"

int main()
{
	char choice = 'y';
	char *inputStr = NULL;
	size_t n;
	char na[MAX_LEN];
	char p[MAX_LEN];
	char a[MAX_LEN];
	list *head = NULL;
	while(choice == 'y'){
	printf("\nInput your data seperated with spaces(Name, phone, adress) : ");
	getline(&inputStr, &n, stdin);
	sscanf(inputStr, "%s %s %s", na, p, a);
	push(&head, na, p, a);
	printf("\nDo you want add more? y or n ");
	scanf("%c", &choice);
	getchar();
	}

	printList(head);


	return 0;
}

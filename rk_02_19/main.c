#include "struct.h"

int main()
{
	char choice = 'y';
	char *inputStr = NULL;
	size_t n = 0;
	char na[MAX_LEN];
	char p[MAX_LEN];
	char a[MAX_LEN];
	list *head = NULL;
	while(choice == 'y'){
	printf("\nInput your data seperated with spaces(Name, phone, adress) : ");
	getline(&inputStr, &n, stdin);
	removeEOL(&inputStr);
	sscanf(inputStr, "%s %s %s", na, p, a);
	push(&head, na, p, a);
	printf("\nDo you want add more? y or n ");
	scanf("%c", &choice);
	getchar();
	}

	printf("\nYour list:\n");
	printList(head);
	
	printf("\nInput phone number for research: ");
	getline(&inputStr, &n, stdin);
	removeEOL(&inputStr);

	list *nodeFound = search(&head, inputStr);

	if(nodeFound) {
		printf("Here your found data with this number(%s) : \n", inputStr);
		printf("\n\t%s\t\t%s\t\t%s\n", nodeFound->name, nodeFound->phone, nodeFound->adress);
	}

	printf("\nInput name for filter : ");
	getline(&inputStr, &n, stdin);
	removeEOL(&inputStr);

	filter(&head, inputStr);


	printf("\nYour list:\n");
	printList(head);

	


	return 0;
}

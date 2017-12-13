#include "main.h"


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

	if(head)
		freeMem(&head);
	freeMem(&mergedHead);
	return 0;
}

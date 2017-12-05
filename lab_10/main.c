#include "struct.h"

enum{
	OK = 0,
	FILE_OPEN_ERROR = 1,
	ARGS_ERROR,
	FAILED_TO_INIT,
};


int fileOpen(FILE** f, const char* name);
int initNode(node_t* head, FILE* f);

int argsInit(int argc);
int isError(int code);



int main(int argc, char** argv)
{
	FILE* f;
	if(isError(argsInit(argc))) {
		return 1;
	}
	if(isError(fileOpen(&f, argv[1]))) {
		return 1;
	}
	node_t* head;
	if(isError(initNode(head, f))) {
		return 1;
	}
//	if(isError(reverse(head))) {
//		return 1;
//	}
	return 0;
}



int initNode(node_t* head, FILE* f)
{
	head = NULL;
	int num;
	while(!feof(f)) {
		if(fscanf(f, "%d", &num)) {
			printf("%d\n", num);
			push(&head, num);
		}
		else
			return FAILED_TO_INIT;
	}
	return OK;
}



int fileOpen(FILE** f, const char* name)
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

	return code;
}

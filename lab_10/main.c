#include "struct.h"

enum{
	OK = 0,
	FILE_OPEN_ERROR = 1,
	ARGS_ERROR,
};


int fileOpen(FILE* f, const char* name);

int argsInit(int argc);
int isError(int code);



int main(int argc, char** argv)
{
	FILE* f;
	if(isError(argsInit(argc))) {
		return 1;
	}
	if(isError(fileOpen(f, argv[1]))) {
		return 1;
	}
	return 0;
}



int fileOpen(FILE* f, const char* name)
{
	f = fopen(name, "r");
	if(!f) {
		return FILE_OPEN_ERROR;
	}
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

	return code;
}

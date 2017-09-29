#include <stdio.h>

#define OK 0
#define FILE_OPEN_ERROR -1
#define ARRAY_INIT_ERROR -2
#define COMMAND_INPUT_ERROR -3

struct DoubleArray
{
	int line;
	int col;
	double **array;
}mtrx1, mtrx2;

int CommandInputLen(int argc);
int WorkingFile(char* name, FILE* f);
int ArrayInit(struct DoubleArray *mtrx1, struct DoubleArray *mtrx2, char **argv);

int ErrorOut(int code);

int main(int argc, char **argv)
{
	if ( ErrorOut( CommandInputLen(argc) ) )
		return 1;
	if ( ErrorOut( ArrayInit(&mtrx1, &mtrx2, argv) ) )
		return 1;
	printf("OKOK\n");
	return OK;
}

int CommandInputLen(int argc)
{
	if ( argc == 3 )
		return OK;
	return COMMAND_INPUT_ERROR;
}

int WorkingFile(char* name, FILE* f)
{
	if (!fopen(name, "r"))
		return FILE_OPEN_ERROR;
	f = fopen(name, "r");
	return OK;
}

int ReadingFile(FILE* f, struct DoubleArray *mtrx, int* code);

int ArrayInit(struct DoubleArray *mtrx1, struct DoubleArray *mtrx2, char **argv)
{
	int code = OK;

	FILE* f1;
	code = WorkingFile(argv[1], f1);

	FILE* f2;
	code = WorkingFile(argv[2], f2);

	return code;
}


int ErrorOut(int code)
{
	if (code == OK)
		return OK;
	else if(code == FILE_OPEN_ERROR)
		printf("File opening error!\n");
	else if(code == ARRAY_INIT_ERROR)
		printf("Array initialization error!\n");
	else if(code == COMMAND_INPUT_ERROR)
		printf("Check your input parameters!\n");
	return code;
}

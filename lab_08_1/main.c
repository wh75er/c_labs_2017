#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define FILE_OPEN_ERROR -1
#define ARRAY_INIT_ERROR -2
#define COMMAND_INPUT_ERROR -3

struct DoubleArray
{
	int lines;
	int col;
	double **data;
}mtrx1, mtrx2;

int CommandInputLen(int argc);

int DynamicInit(struct DoubleArray *mtrx);
int ReadingFile(FILE* f, struct DoubleArray *mtrx);
FILE* WorkingFile(char* name, int* code);
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

FILE* WorkingFile(char* name, int* code)
{
	if (!fopen(name, "r"))
		*code = FILE_OPEN_ERROR;
	FILE* f = fopen(name, "r");
	return f;
}

int DynamicInit(struct DoubleArray *mtrx)
{
	if (mtrx->col > 1 && mtrx->lines > 1)
		mtrx->data = (double**)malloc(mtrx->lines * sizeof(double*) + mtrx->col * mtrx->lines * sizeof(double));
	else
		return ARRAY_INIT_ERROR;
	for (int i = 0; i < mtrx->lines; i++)
		mtrx->data[i] = NULL;
	return OK;
}

int ReadingFile(FILE* f, struct DoubleArray *mtrx)
{
	int num, num1, code = OK;
	if ( fscanf(f, "%d %d\n", &num, &num1) )
	{
		mtrx->lines = num;
		mtrx->col = num1;
	}

	code = DynamicInit(mtrx);

	return code;
}
	

int ArrayInit(struct DoubleArray *mtrx1, struct DoubleArray *mtrx2, char **argv)
{
	int code = OK;
	FILE* f1 = WorkingFile(argv[1], &code);

	FILE* f2 = WorkingFile(argv[2], &code);
	
	code = ReadingFile(f1, mtrx1);

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

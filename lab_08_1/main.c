#include <stdio.h>
#include <stdlib.h>
#include <math.h>

enum{
	OK = 0,
	FILE_OPEN_ERROR,
	ARRAY_INIT_ERROR,
	COMMAND_INPUT_ERROR,
	INCORRECT_CHOICE_ERROR,
	INCORRECT_MATRIX_SIZE_WHILE_AMOUNT,
	INCORRECT_MATRIX_SIZE_WHILE_MULTIP,
	NULL_COPY_MATRIX_ERROR,
	OTHER_SIZE_COPY_MATRIX_ERROR,
	INCORRECT_MATRIX_SIZE_WHILE_GAUSSIAN
};

struct DoubleArray
{
	int lines;
	int col;
	double **data;
}mtrx1, mtrx2, mtrx3;

void MatrixPrint(struct DoubleArray *mtrx);

int CommandInputChecking(int argc, char **argv);

int DynamicInit(struct DoubleArray *mtrx);
int ReadingFile(FILE* f, struct DoubleArray *mtrx);
FILE* WorkingFile(char* name, int* code);
int ArrayInit(struct DoubleArray *mtrx1, struct DoubleArray *mtrx2, char **argv);

int MatrixAmount(struct DoubleArray *mtrx1, struct DoubleArray *mtrx2, struct DoubleArray *mtrx3);
int MatrixMulti(struct DoubleArray *mtrx1, struct DoubleArray *mtrx2, struct DoubleArray *mtrx3);
int copyMatrix(struct DoubleArray *mtrx_in, struct DoubleArray *mtrx_out);
void maxFindingMatrix(double* max, int* tmp, int indent, struct DoubleArray *mtrx, int j);
void linesSwitch(int* indent, int* tmp, struct DoubleArray *mtrx);
int MatrixGaussian(struct DoubleArray *mtrx1, struct DoubleArray *mtrx3);
int MatrixProcessing(struct DoubleArray *mtrx1, struct DoubleArray *mtrx2, struct DoubleArray *mtrx3, char **choice);

int ErrorOut(int code);

int main(int argc, char **argv)
{
	if ( ErrorOut( CommandInputChecking(argc, argv) ) )
		return 1;
	if ( ErrorOut( ArrayInit(&mtrx1, &mtrx2, argv) ) )
		return 1;
	if ( ErrorOut( MatrixProcessing(&mtrx1, &mtrx2, &mtrx3, argv) ) )
		return 1;
	MatrixPrint(&mtrx3);
	printf("\nOK\n");
	return OK;
}


void MatrixPrint(struct DoubleArray *mtrx)
{
	for ( int i = 0; i < mtrx->lines; i++ )
	{
		printf("\n");
		for ( int j = 0; j < mtrx->col; j++ )
		{
			printf("\t%.3lf", mtrx->data[i][j]);
		}
	}
}

int CommandInputChecking(int argc, char **argv)
{
	if ( argc != 4 )
		return COMMAND_INPUT_ERROR;
	if (*argv[3] != '1' && *argv[3] != '2' && *argv[3] != '3')
		return INCORRECT_CHOICE_ERROR;
	return OK;
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
		mtrx->data[i] = (double*)( (char*)mtrx->data + mtrx->lines * sizeof(double*)+ i * mtrx->col * sizeof(double) );
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
	
	int stop = 0, count = 0;
	double num_lf;
	for (double **i = mtrx->data; i < mtrx->data+mtrx->lines; i++)
	{
		count = 0;
		for(double *j = *i; j < *i + mtrx->col; j++)
		{
			if( fscanf(f, "%lf", &num_lf) )
			{
				*j = num_lf;
//				printf("%d ---> %lf\n", count, num_lf);
				count++;
			}
			else
			{
				stop = 1;
				code = ARRAY_INIT_ERROR;
				break;
			}
		}
		if (stop == 1)
			break;
	}
	fclose(f);

	return code;
}
	

int ArrayInit(struct DoubleArray *mtrx1, struct DoubleArray *mtrx2, char **argv)
{
	int code = OK;
	FILE* f1 = WorkingFile(argv[1], &code);
	code = ReadingFile(f1, mtrx1);

	FILE* f2 = WorkingFile(argv[2], &code);
	code = ReadingFile(f2, mtrx2);

	return code;
}


int MatrixAmount(struct DoubleArray *mtrx1, struct DoubleArray *mtrx2, struct DoubleArray *mtrx3)
{
	int code = OK;
	if( mtrx1->lines == mtrx2->lines && mtrx1->col == mtrx2->col )
	{
		mtrx3->lines = mtrx1->lines;
		mtrx3->col = mtrx1->col;
		code = DynamicInit(mtrx3);

		for ( int i = 0; i < mtrx1->lines; i++ )
		{
			for ( int j = 0; j < mtrx1->col; j++ )
			{
				mtrx3->data[i][j] = mtrx1->data[i][j] + mtrx2->data[i][j];
			}
		}
	}
	else
		code = INCORRECT_MATRIX_SIZE_WHILE_AMOUNT;

	return code;
}

int MatrixMulti(struct DoubleArray *mtrx1, struct DoubleArray *mtrx2, struct DoubleArray *mtrx3)
{
	int code = OK;
	if ( mtrx1->col == mtrx2->lines )
	{
		mtrx3->lines = mtrx1->lines;
		mtrx3->col = mtrx2->col;
		code = DynamicInit(mtrx3);

		double sum = 0;
		for (int i = 0; i < mtrx1->lines; i++)
		{
			for (int j = 0; j < mtrx2->col; j++)
			{
				for (int k = 0; k < mtrx2->lines; k++)
				{
					sum += mtrx1->data[i][k] * mtrx2->data[k][j];
				}
				mtrx3->data[i][j] = sum;
				sum = 0;
			}
		}
	}
	else
		code = INCORRECT_MATRIX_SIZE_WHILE_MULTIP;

	return code;
}

int copyMatrix(struct DoubleArray *mtrx_in, struct DoubleArray *mtrx_out)
{
	if ( (mtrx_in->data == NULL || mtrx_out->data == NULL) && (mtrx_in->col * mtrx_in->lines) > 1 && (mtrx_out->col * mtrx_out->lines) > 1 )
		return NULL_COPY_MATRIX_ERROR;

	if ( mtrx_in->col !=  mtrx_out->col || mtrx_in->lines != mtrx_out->lines )
		return OTHER_SIZE_COPY_MATRIX_ERROR;

	for ( int i = 0; i < mtrx_in->lines; i++ )
	{
		for ( int j = 0; j < mtrx_in->col; j++ )
		{
			mtrx_out->data[i][j] = mtrx_in->data[i][j];
		}
	}

	return OK;

}

void maxFindingMatrix(double *max, int *tmp, int indent, struct DoubleArray *mtrx, int j)
{
	for (int i = 0; i < mtrx->lines - indent; i++)			//max finding
	{
		if ( fabs(mtrx->data[i][j]) > fabs(*max) )
		{
			*max = mtrx->data[i][j];
			*tmp = i;
		}
	}
}

void linesSwitch(int *indent, int *tmp, struct DoubleArray *mtrx)
{
	/*
	double num;
	for (int i = 0; i < mtrx->col; i++)
	{
		num = mtrx->data[tmp][i];
		mtrx->data[tmp][i] = mtrx->data[ mtrx->lines-1 - indent ][i];
		mtrx->data[ mtrx->lines-1 - indent ][i] = num;
	}
	indent++;
	*/

	double* line = mtrx->data[*tmp];
	mtrx->data[*tmp] = mtrx->data[ mtrx->lines-1 - *indent ];
	mtrx->data[ mtrx->lines-1 - *indent ] = line;

	*tmp = mtrx->lines-1 - *indent;
	(*indent)++;
}

int MatrixGaussian(struct DoubleArray *mtrx1, struct DoubleArray *mtrx3)
{
	if ( mtrx1->col != mtrx1->lines )
		return INCORRECT_MATRIX_SIZE_WHILE_GAUSSIAN;

	int code = OK;

	mtrx3->lines = mtrx1->lines;
	mtrx3->col = mtrx1->col;
	code = DynamicInit(mtrx3);

	code = copyMatrix(mtrx1, mtrx3);

	double max, k;
	int tmp, indent = 0;
	for (int j = 0; j < mtrx3->col; j++)
	{
		max = mtrx3->data[0][j];
		tmp = 0;

		maxFindingMatrix(&max, &tmp, indent, mtrx3, j);

		linesSwitch(&indent, &tmp, mtrx3);

		if ( max )
		{
			for (int i = 0; i < mtrx3->lines - indent; i++)			//Koef finding
			{
				k = -(mtrx3->data[i][j]/max);
				for(int l = j; l < mtrx3->col; l++)
				{
					mtrx3->data[i][l] += mtrx3->data[tmp][l] * k;
				}
			}
		}
	}

	return code;
}

int MatrixProcessing(struct DoubleArray *mtrx1, struct DoubleArray *mtrx2, struct DoubleArray *mtrx3, char **choice)
{
	int code = OK;
	if (*choice[3] == '1')
	{
		code = MatrixAmount(mtrx1, mtrx2, mtrx3);
	}
	else if(*choice[3] == '2')
	{
		code = MatrixMulti(mtrx1, mtrx2, mtrx3);
	}
	else if(*choice[3] == '3')
	{
		code = MatrixGaussian(mtrx1, mtrx3);
	}
	else
		code = INCORRECT_CHOICE_ERROR;

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
	else if(code == INCORRECT_CHOICE_ERROR)
		printf("Check your choice parameter, you entered wrong option!\n");
	else if(code == INCORRECT_MATRIX_SIZE_WHILE_AMOUNT)
		printf("Matrices amount find error: You cant sum two different sized mamtrices!\n");
	else if(code == INCORRECT_MATRIX_SIZE_WHILE_MULTIP)
		printf("Matrices multiplicate find error: You cant multiplicate two different sized mamtrices, if columns first matrix not equal with rows second matrix!\n");
	else if(code == NULL_COPY_MATRIX_ERROR)
		printf("Cant copy nulls arrays(Function copyMatrix.\n");
	else if(code == OTHER_SIZE_COPY_MATRIX_ERROR)
		printf("Cant copy different sized matrices(Function copyMatrix.\n");
	else if(code == INCORRECT_MATRIX_SIZE_WHILE_GAUSSIAN)
		printf("Matrix gaussian find error: You cant use gaussian method on not square matrix!\n");
	return code;
}

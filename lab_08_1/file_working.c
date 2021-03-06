#include "file_working.h"

FILE* WorkingFile(const char* name, int* code)
{
	if (!fopen(name, "r"))
		*code = FILE_OPEN_ERROR;
	FILE* f = fopen(name, "r");
	return f;
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

	if (code)
		return code;

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

int fileWriteMatrix(struct DoubleArray *mtrx, const char* outFile, const char option)
{
	if( option != 'r' && option != 'n' )
		return INCORRECT_CHOICE_WRITE_FILE_ERROR;

	printf("%s\n", outFile);
	FILE* f = fopen(outFile, "w");
	if (option == 'r')
	{
		for (int i = mtrx->lines-1; i > -1; i--)
		{
			fprintf(f, "\n");
			for (int j = 0; j < mtrx->col; j++)
			{
				fprintf(f, "\t%.3lf", mtrx->data[i][j]);
			}
		}
		fprintf(f, "\n");
	}
	if (option == 'n')
	{
		for (int i = 0; i < mtrx->lines; i++)
		{
			fprintf(f, "\n");
			for (int j = 0; j < mtrx->col; j++)
			{
				fprintf(f, "\t%.3lf", mtrx->data[i][j]);
			}
		}
		fprintf(f, "\n");
	}

	matrixFree(mtrx);
	fclose(f);

	return OK;

}

int writeResult(struct DoubleArray *mtrx, struct args * args)
{
	int code = OK;
	if (*(args->choice) == '3')
		code = fileWriteMatrix(mtrx, args->out, 'r');
	else
		code = fileWriteMatrix(mtrx, args->out, 'n');

	return code;
}

#include "matrix_processing.h"

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


int ArrayInit(struct DoubleArray *mtrx1, struct DoubleArray *mtrx2, char **argv)
{
	int code = OK;
	const char* fileIn1 = argv[1];
	const char* fileIn2 = argv[2];

	FILE* f1 = WorkingFile(fileIn1, &code);
	code = ReadingFile(f1, mtrx1);

	FILE* f2 = WorkingFile(fileIn2, &code);
	code = ReadingFile(f2, mtrx2);

	return code;
}


int MatrixAmount(const struct DoubleArray *mtrx1, const struct DoubleArray *mtrx2, struct DoubleArray *mtrx3)
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

int MatrixMulti(const struct DoubleArray *mtrx1, const struct DoubleArray *mtrx2, struct DoubleArray *mtrx3)
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


int MatrixGaussian(const struct DoubleArray *mtrx1, struct DoubleArray *mtrx3)
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

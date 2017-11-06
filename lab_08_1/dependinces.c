#include "dependinces.h"

int copyMatrix(const struct DoubleArray *mtrx_in, struct DoubleArray *mtrx_out)
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

void maxFindingMatrix(double *max, int *tmp, const int indent, const struct DoubleArray *mtrx, const int j)
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
	double* line = mtrx->data[*tmp];
	mtrx->data[*tmp] = mtrx->data[ mtrx->lines-1 - *indent ];
	mtrx->data[ mtrx->lines-1 - *indent ] = line;

	*tmp = mtrx->lines-1 - *indent;
	(*indent)++;
}

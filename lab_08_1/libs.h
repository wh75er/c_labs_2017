#ifndef __LIBS_H__
#define __LIBS_H__

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
	INCORRECT_MATRIX_SIZE_WHILE_GAUSSIAN,
	INCORRECT_CHOICE_WRITE_FILE_ERROR
};

struct DoubleArray
{
	int lines;
	int col;
	double **data;
}mtrx1, mtrx2, mtrx3;

#endif

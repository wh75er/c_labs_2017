#include "errors_processing.h"

int CommandInputChecking(const int argc, char **argv)
{
	if ( argc != 5 )                                             // .main.c mtrx1_in.txt mtrx2_in.txt choice mtrx_out
		return COMMAND_INPUT_ERROR;
	if (*argv[3] != '1' && *argv[3] != '2' && *argv[3] != '3')
		return INCORRECT_CHOICE_ERROR;
	return OK;
}

int ErrorOut(const int code)
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
	else if(code == INCORRECT_CHOICE_WRITE_FILE_ERROR)
		printf("Incorrect choice ( fileWrite function )!\n");
	return code;
}

#ifndef __LIBS_H__
#define __LIBS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE_OF_BUFF 128

enum {
	POINTER_NULL = -10,
	FILE_DISSAPOINT,
	MEM_REALLOC_ERROR,
	EMPTY_BUFFER_ERROR = -7,

	OK = 0,
	ARG_INPUT_ERROR,
	FILE_READING_ERROR,
	NULL_POINTER_ERROR_WRITE,

};


typedef struct{
	char* fileIn;
	char* fileOut;
	char* replace;
	char* search;
}args;

typedef struct{
	FILE* file;
	char** str;
}string;

#endif

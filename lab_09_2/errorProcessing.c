#include "errorProcessing.h"

int isError(const int code, const char* fileOut, char** strFree, FILE* fFree)
{
		char** error;
	if(code)
		error = malloc(sizeof(char*));
	if(code == ARG_INPUT_ERROR){
		printf("Check your input parameters!\n");
		free(error);
		return code;
	}
	if(code == FILE_READING_ERROR)
		*error = "File reading error!\n";
	if(code == POINTER_NULL)
		*error = "getDelim ERROR: check your input arguments!\n";
	if(code == FILE_DISSAPOINT)
		*error = "getDelim ERROR: check your input stream. Current stream is null!\n";
	if(code == MEM_REALLOC_ERROR)
		*error = "getDelim ERROR: memory reallocation error! realloc operation failed!\n";
	if(code == EMPTY_BUFFER_ERROR)
		*error = "getDelim ERROR: failed to processing the buffer. Current buffer is null!\n";
	if(code == NULL_POINTER_ERROR_WRITE)
		*error = "File writing error! Null pointer've been added.\n";
	if(code){
		writeFile(fileOut, error, code);
		free(error);
		memFree(strFree, fFree);
	}
	return code;
}

void memFree(char** str, FILE* f)
{
	if(*str)
		free(*str);
	if(str)
		free(str);
	if(f)
		fclose(f);
}

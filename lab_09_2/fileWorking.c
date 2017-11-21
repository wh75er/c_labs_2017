#include "fileWorking.h"


int writeFile(const char* fileOut, char** str, int code)
{
	if(!str && !code || !*str && !code)
		return NULL_POINTER_ERROR_WRITE;
	if(code){
		FILE* f = fopen(fileOut, "w");
		fprintf(f, "%s", *str);
		fclose(f);
	}
	else{
		FILE* f = fopen(fileOut, "w");
		fprintf(f, "%s", *str);
		fclose(f);
	}
	return OK;
}

int readFile(FILE* f, char** str)
{
	size_t n = 0;
	char** strIn = (char**)malloc(sizeof(char*));
	*strIn = NULL;

	ssize_t code = 1;
	int size_of_array = n;
	while(code > 0){
		code = my_getdelim(strIn, &n, '\n', f);
		size_of_array+=n;
		if(code < 0)
			return code;
		*str = (char*)realloc(*str, size_of_array);
		for(int i = 0; (*strIn)[i] != '\0'; i++){
			int j;
			for(j = 0; (*str)[j] != '\0'; j++);
			(*str)[j] = (*strIn)[i];
		}
	}
	free(*strIn);
	free(strIn);

	return OK;
}

int openFile(const char* fileIn, FILE** f)
{
	*f = fopen(fileIn, "r");
	if (!*f)
		return FILE_READING_ERROR;
	return OK;
}

#include <stdio.h>
#include <stdlib.h>
#define SIZE_OF_BUFF 128

enum {
	POINTER_NULL = -10,
	FILE_DISSAPOINT,
	MEM_REALLOC_ERROR,
	EMPTY_BUFFER_ERROR = -7,

	OK = 0,
	ARG_INPUT_ERROR,
	FILE_READING_ERROR,
	
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


ssize_t my_getdelim(char **lineptr, size_t *n, int delim, FILE *stream);
char* strReplace(const char *source, const char *search, const char *replace);


int argInit(const int argc, char** argv, args *args);
int stringInit(string *text);
int openFile(const char* fileIn, FILE** f);
int readFile(FILE* f, char** str);
int stringProcessing(const char *search, const char *replace, char** str);
int writeFile(const char* fileOut, char** str);
int isError(const int code);


int main(int argc, char **argv)
{
	args args;
	string text;
	if(isError(argInit(argc, argv, &args)))
		return 1;
	if(isError(stringInit(&text)))
		return 1;
	if(isError(openFile(args.fileIn, &text.file)))
		return 1;
/*	if(isError(readFile(text.file, text.str)))
		return 1;
	if(isError(stringProcessing(args.search, args.replace, text.str)))
		return 1;
	if(isError(writeFile(args.fileOut, text.str)))
		return 1;
		*/
	free(text.str);
	fclose(text.file);
	return 0;			
}

char* strReplace(const char* source, const char* search, const char* replace)
{
	
}

int stringProcessing(const char *search, const char *replace, char** str)
{
	const char* source = *str;
	char* new_line = strReplace(source, search, replace);
	free(*str);
	*str = new_line;
	return OK;
}

int readFile(FILE* f, char** str)
{
	size_t n = 0;	
	ssize_t code = my_getdelim(str, &n, '\n', f);
	if(code < 0)
		return code;
//	while(my_getdelim(str, &n, '\n', f) > 0);

	return OK;
}

int openFile(const char* fileIn, FILE** f)
{
	*f = fopen(fileIn, "r");
	if (!*f)
		return FILE_READING_ERROR;
	return OK;
}

int stringInit(string *text)
{
	text->file = NULL;
	text->str = (char**)malloc(sizeof(char*));
	*text->str = NULL;

	return OK;
}

int argInit(const int argc, char** argv, args *args)
{
	if(argc < 4 ||  argc > 5)
		return ARG_INPUT_ERROR;
	args->fileIn = argv[1];
	args->fileOut = argv[2];
	args->search = argv[3];
	if(argc == 3){
		args->replace = NULL;
	}
	if(argc == 4){
		args->replace = argv[4];
	}

	return OK;
}



ssize_t my_getdelim(char **lineptr, size_t *n, int delim, FILE *stream)
{
	if (lineptr == NULL || n == NULL)
		return POINTER_NULL;

	if (stream == NULL)
		return FILE_DISSAPOINT;


	char* array = *lineptr;
	if(!array || *n < SIZE_OF_BUFF || !*n){
		array = (char*)realloc(*lineptr, SIZE_OF_BUFF);
		if (!array)
			return MEM_REALLOC_ERROR;
		*n = SIZE_OF_BUFF;
	}	
	else if(array && *n){
		array = (char*)realloc(*lineptr, *n + SIZE_OF_BUFF);
		if (!array)
			return MEM_REALLOC_ERROR;
		*n += SIZE_OF_BUFF;
		for(char* pa_k = array; *pa_k != '\0'; pa_k++)
			*pa_k = '\0';
	}
	*lineptr = array;


	int bytes = 0;
	char buff[SIZE_OF_BUFF], *arrayOfIn, *arrayOfBuff, *pa;
	while(fgets(buff, SIZE_OF_BUFF, stream)){
//		printf("%s-END\n", buff);
		for (pa = buff; pa < buff + SIZE_OF_BUFF && *pa != delim && *pa != '\0'; pa++);
		if (pa == buff + SIZE_OF_BUFF || *pa == '\0'){
//			printf("OK\n");
			bytes+= pa - buff;
			arrayOfIn = *lineptr;
			arrayOfBuff = buff;
			while (arrayOfBuff != buff + bytes - 1){
				if(*arrayOfIn == '\0'){
					*arrayOfIn = *arrayOfBuff;
					arrayOfBuff++;
				}
				arrayOfIn++;
			}
		}
		else{
			bytes+= pa - buff + 1;
			arrayOfIn = *lineptr;
			arrayOfBuff = buff;
			while (arrayOfBuff != buff + bytes){
				if(*arrayOfIn == '\0'){
					*arrayOfIn = *arrayOfBuff;
					arrayOfBuff++;
				}
				arrayOfIn++;
			}
			char* pa_l;
			for(pa_l = *lineptr; *pa_l != '\0'; pa_l++);
			fseek(stream, pa_l - *lineptr + *n/128 - 1, SEEK_SET);
			return bytes;
		}
	}
	if (buff == 0)
		return EMPTY_BUFFER_ERROR;
	return bytes;
}


int isError(const int code)
{
	if(code == ARG_INPUT_ERROR)
		printf("Check your input parameters!\n");
	if(code == FILE_READING_ERROR)
		printf("File reading error!\n");
	if(code == POINTER_NULL)
		printf("getDelim ERROR: check your input arguments!\n");
	if(code == FILE_DISSAPOINT)
		printf("getDelim ERROR: check your input stream. Current stream is null!\n");
	if(code == MEM_REALLOC_ERROR)
		printf("getDelim ERROR: memory reallocation error! realloc operation failed!\n");
	if(code == EMPTY_BUFFER_ERROR)
		printf("getDelim ERROR: failed to processing the buffer. Current buffer is null!\n");
	return code;
}

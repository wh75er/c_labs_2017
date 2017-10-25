#include "stringProcessing.h"


int stringProcessing(const char *search, const char *replace, char** str)
{
	const char* source = *str;
	char* new_line = strReplace(source, search, replace);
	free(*str);
	*str = new_line;

	return OK;
}

int strLen(const char* str)
{
	const char* pa;
	for(pa = str; *(char*)pa != '\0'; pa++);

	return (pa - str);
}

ssize_t my_getdelim(char **lineptr, size_t *n, int delim, FILE *stream)
{
	if (lineptr == NULL || n == NULL)
		return POINTER_NULL;

	if (stream == NULL)
		return FILE_DISSAPOINT;


	char* array = *lineptr;
	if(!array || !*n){
		array = (char*)realloc(*lineptr, SIZE_OF_BUFF);
		if (!array)
			return MEM_REALLOC_ERROR;
		*n = SIZE_OF_BUFF;
	}
	else if(array && *n){
		*n = 0;
		array = (char*)realloc(*lineptr, *n + SIZE_OF_BUFF);
		if (!array)
			return MEM_REALLOC_ERROR;
		*n += SIZE_OF_BUFF;
		for(char* pa_k = array; *pa_k != '\0'; pa_k++)
			*pa_k = '\0';
	}
	*lineptr = array;


	int bytes = 0;
	char buff[SIZE_OF_BUFF], *arrayOfIn, *arrayOfBuff, *pa, *pa_l;
	while(fgets(buff, SIZE_OF_BUFF, stream)){
		for (pa = buff; pa < buff + SIZE_OF_BUFF && *pa != delim && *pa != '\0'; pa++);
		if (pa == buff + SIZE_OF_BUFF || *pa == '\0'){
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
			array = NULL;
			array = (char*)realloc(*lineptr, SIZE_OF_BUFF);
			if (!array)
				return MEM_REALLOC_ERROR;
			*n += SIZE_OF_BUFF;
			*lineptr = array;
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

			for(pa_l = buff; *pa_l != '\0'; pa_l++);
//				printf("%d - end\n", pa_l - buff);
//			printf("offset ---> %d\n", pa - buff);
//			printf("offset ---> %d\n", pa_l - pa);
			fseek(stream, -(pa_l - pa - 1), SEEK_CUR);
			return bytes;
		}
	}
	if (buff == 0)
		return EMPTY_BUFFER_ERROR;
	return bytes;
}


char* strReplace(const char* source, const char* search, const char* replace)
{
	const char *pa = source, *pa_i;
	int count = 0;
	while(*pa != '\0'){
		if (*(char*)pa == *(char*)search){
			pa_i = search;
			while(*pa_i != '\0' && *pa != '\0'){
				if(*pa_i != *pa)
					break;
				if(*(pa_i+1) == '\0')
					count++;
				pa_i++;
				pa++;
			}
			pa--;
		}
		pa++;
	}

	#ifdef DEBUG
	printf("count ---> %d\n", count);
	#endif
	int newSubjLen = (strLen(replace) - strLen(search))*count + strLen(source);
	char* dest = malloc(newSubjLen);

	pa = source;
	const char* pa_j = source - 1;
	char* dest_pa = dest;
	while(*pa != '\0'){
		#ifdef DEBUG
		printf("%c ---------> %p\n", *pa, pa);
		#endif
		if (*(char*)pa == *(char*)search && pa > pa_j){
			#ifdef DEBUG
			printf("PASS\n");
			#endif
			pa_i = search;
			pa_j = pa;
			while(*pa_i != '\0' && *pa_j != '\0'){
				#ifdef DEBUG
				printf("%c and %c\n", *pa_i, *pa_j);
				#endif
				if(*pa_i != *pa_j)
					break;
				if(*(pa_i+1) == '\0'){
					for(const char* a = replace; *(char*)a != '\0'; a++){
						*dest_pa = *(char*)a;
						dest_pa++;
					}
				}

				pa_i++;
				pa_j++;
			}
		}
		else if(pa >= pa_j){
			*dest_pa = *pa;
			#ifdef DEBUG
			printf("%c\n", *dest_pa);
			#endif
			dest_pa++;
		}
		pa++;
	}

	return dest;
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
	if(argc != 7)
		return ARG_INPUT_ERROR;
	int flag1 = 0, flag2 = 0, index1, index2;
	for(int i = 3; i < argc; i++){
		if(!strcmp(argv[i], "-r")){
			flag2 = 1;
			index2 = i;
		}
		if(!strcmp(argv[i], "-s")){
			index1 = i;
			flag1 = 1;
		}
	}
	if(!flag1 || !flag2)
		return ARG_INPUT_ERROR;

	args->fileIn = argv[1];
	args->fileOut = argv[2];
	args->search = argv[index1+1];
	args->replace = argv[index2+1];

	return OK;
}

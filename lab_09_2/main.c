#include <stdio.h>
#include <stdlib.h>
#define SIZE_OF_BUFF 128

ssize_t my_getdelim(char **lineptr, size_t *n, int delim, FILE *stream);

int main()
{
	setbuf(stdout, NULL);
	char **str;
	size_t n = 0;
	int delim = 'f';
	FILE* f = fopen("input.txt", "r");	
	*str = (char*)malloc(0);
	
	int result = my_getdelim(str, &n, delim, f);
	printf("%s\n", *str);
	printf("%d\n", result);
	result = my_getdelim(str, &n, delim, f);
	printf("%s\n", *str);
	printf("%d\n", result);
	result = my_getdelim(str, &n, delim, f);
	printf("%s\n", *str);
	printf("%d\n", result);
}

ssize_t my_getdelim(char **lineptr, size_t *n, int delim, FILE *stream)
{
	if (lineptr == NULL || n == NULL)
		return -1;

	if (stream == NULL)
		return -1;


	char* array = *lineptr;
	if(!array || *n < SIZE_OF_BUFF || !*n){
		array = (char*)realloc(*lineptr, SIZE_OF_BUFF);
		if (!array)
			return -1;
		*n = SIZE_OF_BUFF;
	}	
	else if(array && *n){
		array = (char*)realloc(*lineptr, *n + SIZE_OF_BUFF);
		if (!array)
			return -1;
		*n += SIZE_OF_BUFF;
	}
	*lineptr = array;


	int bytes = 0;
	char buff[SIZE_OF_BUFF], *arrayOfIn, *arrayOfBuff, *pa;
	while(fgets(buff, SIZE_OF_BUFF, stream)){
		printf("%s-END\n", buff);
		for (pa = buff; pa < buff + SIZE_OF_BUFF && *pa != delim && *pa != '\0'; pa++);
		if (pa == buff + SIZE_OF_BUFF || *pa == '\0'){
			printf("OK\n");
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
			bytes+= pa - buff;
			arrayOfIn = *lineptr;
			arrayOfBuff = buff;
			while (arrayOfBuff != buff + bytes){
				if(*arrayOfIn == '\0'){
					if(*arrayOfBuff != delim)
						*arrayOfIn = *arrayOfBuff;
					arrayOfBuff++;
				}
				arrayOfIn++;
			}
			char* pa_l;
			for(pa_l = *lineptr; *pa_l != '\0'; pa_l++);
			fseek(stream, pa_l - *lineptr + *n/128, SEEK_SET);
			return bytes;
		}
	}
	if (buff == 0)
		return -1;
	return bytes;
}

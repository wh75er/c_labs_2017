#include "libs.h"

void hex2str(char **pa, int* count, const size_t size, unsigned int data)
{
	int shift = 0;
	while(data>>shift + 4)
		shift += 4;

	
	char ch = '0';
	for(int i = 0; i < shift; i+=4) {
		ch = (data>>shift & 0xF) + '0';
		if(ch > '9')
			ch += 7;
		if(*count < size) {
			*(*pa) = ch;
			(*pa)++;
		}
	}
}

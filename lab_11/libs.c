#include "libs.h"

void hex2str(char **pa, int* count, const size_t size, unsigned int data)
{
	int shift = 0;
	while(data>>shift + 4)
		shift += 4;

	
	char ch = '0';
		if(*count < size + 2) {
			*(*pa) = '0';
			(*pa)++;
			*(*pa) = 'x';
			(*pa)++;
		}
	for(int i = shift; i > -1; i-=4) {
		ch = (data>>shift & 0xF) + '0';
		if(ch > '9')
			ch += 7;
		if(*count < size) {
			*(*pa) = ch;
			(*pa)++;
		}
	}
}


void int2str(char **pa, int* count, const size_t size, int data)
{
	int cpy = data, dec = 0, shift = 1;
	
	while(cpy) {
		cpy = cpy/10;
		shift*= 10;
		dec++;
	} 

	if(dec == 1)
		if(*count < size) {
			*(*pa) = data + '0';
			(*pa)++;
		}
	for(int i = dec - 1; i > -1; i--) {
		if(*count < size) {
			shift = shift/10;
			*(*pa) = ( data/(shift) )%10 + '0';
			(*pa)++;
		}
	}
}

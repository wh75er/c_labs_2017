#include "libs.h"

int my_snprintf(char *str, size_t size, const char *format, ...) 
{
	va_list ap;
	va_start(ap, format);
	int count = 0; 

	if(!str)
		return count;

	int flag = 0;
	char *strP = str;
	for(char *pa = (char*)format; *pa != '\0'; pa++) {
		if(count + 1 >=  BUFFSIZE) {
			*strP = '\0';
			break;
		}

		if(!flag && *pa == '%') {
			flag = 1;
		}
		else if(!flag) {
			if(count < size) {
				*strP = *pa;
				strP++;
				count++;
			}
		}

		if(flag && *pa == 's') {
			char *tmp = va_arg(ap, char*);
			for(char* pb = tmp; *pb != '\0'; pb++) {
				if(count < size) {
					*strP = *pb;
					strP++;
					count++;
				}
				count++;
			}
			flag = 0;
		}
		else if(flag && *pa == 'c') {
			char tmp = (long int)va_arg(ap, int);
			if(count < size) {
				*strP = (char)tmp;
				strP++;
				count++;
			}
			flag = 0;
		}
		else if(flag && *pa == 'd') {
			long int tmp = (long int)va_arg(ap, int);
			if(count < size) {
				int2str(&strP, &count, size, tmp);
			}
			flag = 0;
		}
		else if(flag && *pa == '%') {
			if(count < size && pa > format) {
				if(*(pa-1) == '%') {
					*strP = *pa;
					strP++;
					count++;
					flag = 0;
				}
			}
		}
		else if(flag && *pa == 'x') {
			unsigned long int tmp = (unsigned long int)va_arg(ap, unsigned int);
			hex2str(&strP, &count, size, tmp);
			flag = 0;
		}
	}
	if(count + 1 < BUFFSIZE) {
		*strP = '\0';
	}
	*(str + BUFFSIZE) = '\0';
	va_end(ap);
	return count;
}

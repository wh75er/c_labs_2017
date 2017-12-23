#include "libs.h"

int my_snprintf(char *str, size_t size, const char *format, int num_args, ...) 
{
	va_list ap;
	va_start(ap, num_args);
	int count = 0; 

	if(!str)
		return count;

	int flag = 0;
	char *strP = str;
	for(char *pa = (char*)format; *pa != '\0'; pa++) {
		if(count + 1 >=  BUFFSIZE) {
			break;
		}

		if(!flag && *pa == '%') {
			flag = 1;
		}
		else if(!flag) {
			if(count < size) {
				*strP = *pa;
				strP++;
			}
		}

		if(flag && *pa == 's') {
			char *tmp = va_arg(ap, char*);
			for(char* pb = tmp; *pb != '\0'; pb++) {
				if(count < size) {
					*strP = *pb;
					strP++;
				}
				count++;
			}
			flag = 0;
		}
		else if(flag && *pa == 'c') {
			char tmp = va_arg(ap, int);
			if(count < size) {
				*strP = (char)tmp;
				strP++;
			}
			flag = 0;
		}
		else if(flag && *pa == 'd') {
			int tmp = va_arg(ap, int);
			if(count < size) {
				*strP = tmp + '0';
				strP++;
			}
			flag = 0;
		}
		else if(flag && *pa == '%') {
			if(count < size && pa > format) {
				if(*(pa-1) == '%') {
					*strP = *pa;
					strP++;
					flag = 0;
				}
			}
		}
		else if(flag && *pa == 'x') {
			unsigned int tmp = va_arg(ap, unsigned int);
			hex2str(&pa, &count, size, tmp);
			flag = 0;
		}
		
		

	}
	va_end(ap);
}

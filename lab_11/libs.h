#ifndef __LIBS_H__
#define __LIBS_H__

#define BUFFSIZE 100


#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void hex2str(char **pa, int *count, const size_t size, unsigned int data);
int my_snprintf(char *str, size_t size, const char *format, int num_args, ...);

#endif

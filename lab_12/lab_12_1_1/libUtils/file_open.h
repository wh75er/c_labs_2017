#ifndef __FILE_C__
#define __FILE_C__
#include "libs.h"
#include "counter.h"

typedef int (*count_s)(FILE *f, int* code);

int open_file(char* name, count_s len_array_int, count_s len_array_double, int *code_1, size_t *type);

#endif

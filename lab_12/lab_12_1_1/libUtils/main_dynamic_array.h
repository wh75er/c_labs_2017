#ifndef __DYNAMIC_ARRAY_MAIN_C__
#define __DYNAMIC_ARRAY_MAIN_C__
#include "libs.h"
#include "dynamic_arrays.h"

typedef double* (*double_array)(FILE* f, int len, int* code);
typedef int* (*int_array)(FILE* f, int len, int* code);


void* create_dynamic_array(char *name_of_file, int len, int *code_1, size_t type, double_array dynamic_array_double, int_array dynamic_array_int);

#endif

#ifndef __FILTER_C__
#define __FILTER_C__
#include "libs.h"
#include "swap.h"
#include "compare.h"

int* filter_int(int* a, int* len);
double* filter_double(double* a, int* len);
void bubble_sort(void *array, size_t nmemb, size_t type);

#endif

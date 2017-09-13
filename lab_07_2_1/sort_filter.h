#ifndef __FILTER_C__
#define __FILTER_C__
#include "libs.h"
#include "swap.h"
#include "compare.h"

void* filter(char *choice, void* array, int* len, size_t type);
void bubble_sort(void *array, size_t nmemb, size_t type);

#endif

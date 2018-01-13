//swap.h

#include "swap.h"

void swap(void *a1, void *b1, size_t type)
{
    char tmp;
    char* a = (char*)a1;
    char* b = (char*)b1;
    for (size_t i = 0; i < type; i++)
    {
        tmp = *b;
        *b = *a;
        *a = tmp;
        a++;
        b++;
    }
}

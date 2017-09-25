#include "compare.h"

char compare(const void *a, const void *b, size_t type)
{
    if (type == 4)
    {
        if (*(int*)a > *(int*)b)
            return '>';
        if (*(int*)a < *(int*)b)
            return '<';
    }
    if (type == 8)
    {
        if (*(double*)a > *(double*)b)
            return '>';
        if (*(double*)a < *(double*)b)
            return '<';
    }
    return '=';
}

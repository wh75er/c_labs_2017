#include "uniq_nums_counter.h"

int uniq_nums_counter(int *pa, int *pa_fin, int* a)
{
    int counter = 0;
    for (pa = a + 1; pa < pa_fin - 1; pa++)
    {
        if ( *pa != *(pa - 1) && *pa != *(pa + 1) )
            counter++;
    }
    if ( *a != *(a + 1) )
        counter++;
    if ( *(pa_fin - 1) != *(pa_fin - 2) )
        counter++;
    return counter;
}

#include "insertions_sort.h"

void insertions_sort(int* a, int* pa_fin)
{
    int* pa = a;
    for (pa = a + 1; pa < pa_fin; pa++)
    {
        for (int* pa_i= pa; pa_i > a - 1; pa_i--)
        {
            if (*(pa_i-1) > *pa_i)
            {
                swap(pa_i-1, pa_i);
            }
        }
    }
}

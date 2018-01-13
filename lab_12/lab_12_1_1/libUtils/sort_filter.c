#include "sort_filter.h"

void* filter(const char choice, void* array, int* len, size_t type, int* farray, double* dfarray)
{
	if (choice == '1')
    {
        if (type == 4)
        {
            int* a = (int*) array;
            int *min = a;
            int *max = a;
            for (int* pa = a + 1; pa < a + *len; pa++)
            {
                if (*pa > *max)
                    max = pa;
                if (*pa < *min)
                    min = pa;
            }
            if ((max - min - 1) > 0)
            {
                *len = (max - min - 1);
                int* fpa = farray;
                for (int* pa = min+1; pa < max; pa++)
                {
                    *fpa = *pa;
                    fpa++;
                }

                return farray;
            }
            else if ((min - max - 1) > 0)
            {
                *len = (min - max - 1);
                int* fpa = farray;
                for (int* pa = max+1; pa < min; pa++)
                {
                    *fpa = *pa;
                    fpa++;
                }

                return farray;
            }
            free(array);
            *len = 0;
			*farray = 0;
            return farray;
        }

        else
        {
            double* a = (double*)array;
            double *min = a;
            double *max = a;
            for (double* pa = a + 1; pa < a + *len; pa++)
            {
                if (*pa > *max)
                    max = pa;
                if (*pa < *min)
                    min = pa;
            }
            if ((max - min - 1) > 0)
            {
                *len = (max - min - 1);
                double* fpa = dfarray;
                for (double* pa = min+1; pa < max; pa++)
                {
                    *fpa = *pa;
                    fpa++;
                }
                return dfarray;
            }
          else if ((min - max - 1) > 0)
            {
                *len = (min - max - 1);
                double* fpa = dfarray;
                for (double* pa = max+1; pa < min; pa++)
                {
                    *fpa = *pa;
                    fpa++;
                }
                return dfarray;
            }

            free(array);
            *len = 0;
			*dfarray = 0;
            return dfarray;
        }
    }
    return array;
}

void bubble_sort(void *array, size_t nmemb, size_t type)
{
    if (type == 4)
    {
        int n = 0;
        while (n < nmemb + 1)
        {
            for (int* pa = (int*)array; pa < (int*)(array + (nmemb - 1 - n) * type); pa++)
            {
                if (compare((pa+1), pa, type) == '<')
                    swap((pa+1), pa, type);
            }
            n++;
        }
    }

    if (type == 8)
    {
        int n = 0;
        while (n < nmemb + 1)
        {
            for (double* pa = (double*)array; pa < (double*)(array + (nmemb - 1 - n) * type); pa++)
            {
                if (compare((pa+1), pa, type) == '<')
                    swap((pa+1), pa, type);
            }
            n++;
        }
    }
}

#include "sort_filter.h"

void* filter(const char choice, void* array, int* len, size_t type)
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
                int* farray = (int*)malloc((max - min - 1)*sizeof(int));
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
                int* farray = (int*)malloc((min - max - 1)*sizeof(int));
                int* fpa = farray;
                for (int* pa = max+1; pa < min; pa++)
                {
                    *fpa = *pa;
                    fpa++;
                }

                return farray;
            }
            free(array);
            int* farray = (int*)malloc(type);
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
                double* farray = (double*)malloc(*len*sizeof(double));
                double* fpa = farray;
                for (double* pa = min+1; pa < max; pa++)
                {
                    *fpa = *pa;
                    fpa++;
                }
                return farray;
            }
          else if ((min - max - 1) > 0)
            {
                *len = (min - max - 1);
                double* farray = (double*)malloc(*len*sizeof(double));
                double* fpa = farray;
                for (double* pa = max+1; pa < min; pa++)
                {
                    *fpa = *pa;
                    fpa++;
                }
                return farray;
            }

            free(array);
            double* farray = (double*)malloc(type);
            *len = 0;
            *farray = 0;
            return farray;
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

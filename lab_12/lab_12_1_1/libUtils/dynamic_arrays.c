#include "dynamic_arrays.h"

int* dynamic_array_int(FILE* f, int len, int* code)
{
    int* array = (int*)malloc(len*sizeof(int));
    int* pa = array;
    int stop = 0;
    int num;
    rewind(f);
    while ( !feof(f) && !stop)
    {
        if ( fscanf( f, "%d", &num ) )
        {
            *pa = num;
            pa++;
        }
        else
        {
            *code = 1;
            stop = 1;
        }
    }
    return array;
}

double* dynamic_array_double(FILE* f, int len, int* code)
{
    double* array = (double*)malloc(len*sizeof(double));
    double* pa = array;
    int stop = 0;
    double num;
    rewind(f);
    while ( !feof(f) && !stop)
    {
        if ( fscanf( f, "%lf", &num ) )
        {
            *pa = num;
            pa++;
        }
        else
        {
            *code = 1;
            stop = 1;
        }
    }
    return array;
}

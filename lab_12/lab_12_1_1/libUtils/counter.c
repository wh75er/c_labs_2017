#include "counter.h"

int len_array_int(FILE *f, int* code)
{
    int stop = 0;
    int count = 0;
    int empty;
    while ( !feof(f) && !stop)
    {
        if ( fscanf( f, "%d", &empty ) )
        {
            count++;
        }
        else
        {
            *code = 1;
            stop = 1;
        }
    }
    return count;
}

int len_array_double(FILE *f, int* code)
{
    int stop = 0;
    int count = 0;
    double empty;
    while ( !feof(f) && !stop)
    {
        if ( fscanf( f, "%lf", &empty ) )
        {
            count++;
        }
        else
        {
            *code = 1;
            stop = 1;
        }
    }
    return count;
}

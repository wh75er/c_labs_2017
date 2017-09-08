#include <stdio.h>
#include <stdlib.h>

//counters
int len_array_int(FILE *f, int* code);
int len_array_double(FILE *f, int* code);

//print and init
int* array_init(int *pa_fin, FILE *f, int* code);
void array_print_int(int *pa, int *pa_fin);
void array_print_double(double *pa, double *pa_fin);

//dynamic array creation
int* dynamic_array_int(FILE* f, int len, int* code);
double* dynamic_array_double(FILE* f, int len, int* code);

//Sort and filter



int main(int argc, char **argv)
{
    if (argc > 1)
    {
        FILE *f = fopen(argv[1], "r");

        int code = 0;
        size_t type = sizeof(int);                //Type of varAr (int)

        int len = len_array_int(f, &code);
        if (code)
        {
            type = sizeof(double);
            code = 0;
            rewind(f);
            len = len_array_double(f, &code);
        }
        if ( !code )
        {
            printf("\n%d\n", type);
            printf("\n%d\n", len);
            if (type == 4)
            {
                int* array = dynamic_array_int(f, len, &code);
                array_print_int(array, array+len);
            }
            else
            {
                double* array = dynamic_array_double(f, len, &code);
                array_print_double(array, array+len);
            }
            // Prog
        }
        else
            printf("\nFile reading error!\n");
        fclose(f);
    }
    else
        printf("\nFile name entering error.\n");
    return 0;
}

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

int* array_init(int *pa_fin, FILE *f, int* code)
{
    int stop = 0;
    while ( !feof(f) && !stop)
    {
        if ( fscanf( f, "%d", pa_fin ) )
        {
            pa_fin++;
        }
        else
        {
            *code = 1;
            stop = 1;
        }
    }
    return pa_fin;
}

void array_print_int(int *pa, int *pa_fin)
{
    for (int* pa_i = pa; pa_i < pa_fin; pa_i++)
            printf("%d ", *pa_i);
}

void array_print_double(double *pa, double *pa_fin)
{
    for (double* pa_i = pa; pa_i < pa_fin; pa_i++)
            printf("%lf ", *pa_i);
}



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

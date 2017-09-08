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
    //int
int *filter_int(int *a, int *len);
    //double
double* filter_double(double* a, int* len);


int main(int argc, char **argv)
{
    if (argc > 1)
    {
        FILE *f = fopen(argv[1], "r");

        int code = 0;
        size_t type = sizeof(int);              //Type of varAr (int)

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
            if (type == 4)                      //int branch work
            {
                int* array = dynamic_array_int(f, len, &code);
                array_print_int(array, array+len);
                array = filter_int(array, &len);

                free(array);
            }
            else                                //double branch work
            {
                double* array = dynamic_array_double(f, len, &code);
                array_print_double(array, array+len);
                array = filter_double(array, &len);

                free(array);
            }

        }
        else
            printf("\nFile reading error!\n");
        fclose(f);
    }
    else
        printf("\nFile name entering error.\n");
    return 0;
}

//counters
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

//print and init
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

//dynamic array creation
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

//Sort and filter
    //int
int* filter_int(int* a, int* len)
{
    int *min = a;
    int *max = a;
    for (int* pa = a + 1; pa < a + *len; pa++)
    {
        if (*pa > *max)
            max = pa;
        if (*pa < *min)
            min = pa;
    }
    printf("\n%d, %d, %d\n", *min, *max, (max - min - 1));
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
        array_print_int(farray, farray+(max - min - 1));

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
        array_print_int(farray, farray+(min - max - 1));

        return farray;
    }

    printf("\n%d, %d, %d\n", *min, *max, (max - min - 1));
    return a;
}

    //double
double* filter_double(double* a, int* len)
{
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
        array_print_double(farray, farray+(max - min - 1));
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
        array_print_double(farray, farray+(min - max - 1));
        return farray;
    }

    printf("\n%lf, %lf, %d\n", *min, *max, (max - min - 1));
    return a;
}

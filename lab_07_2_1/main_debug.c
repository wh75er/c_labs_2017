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
//Sort
void bubble_sort(void* array, size_t nmemb, size_t type);

//compare
char compare(const void* a1, const void* b1, size_t type);

//swap
void swap(void *a1, void *b1, size_t type);


int main(int argc, char **argv)
{
    if (argc > 3 && (*argv[3] == '1' || *argv[3] == '0'))
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
                printf("%c", argv[3]);
                if (*argv[3] == '1')
                    array = filter_int(array, &len);
                char flag = compare((array+2), (array+2), type);
                printf("\n %d %c %d\n", *(array+2), flag, *(array+2));

                bubble_sort(array, len, type);
                array_print_int(array, array+len);

                FILE *fo = fopen(argv[2], "w");
                for(int* pa = array; pa < array + len; pa++)
                    fprintf(fo, "%d ", *pa);

                free(array);
            }
            else                                //double branch work
            {
                double* array = dynamic_array_double(f, len, &code);
                array_print_double(array, array+len);
                if (*argv[3] == '1')
                    array = filter_double(array, &len);
                char flag = compare((array+1), array, type);
                printf("\n %lf %c %lf\n", *(array+1), flag, *array);

                bubble_sort(array, len, type);
                array_print_double(array, array+len);

                FILE *fo = fopen(argv[2], "w");
                for(double* pa = array; pa < array + len; pa++)
                    fprintf(fo, "%lf ", *pa);

                free(array);
            }

        }
        else
            printf("\nFile reading error!\n");
        fclose(f);
    }
    else
        printf("\nProgram parametrs entering error!\n");
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

//Sort
void bubble_sort(void *array, size_t nmemb, size_t type)
{
    if (type == 4)
    {
        int n = 0;
        while (n < nmemb + 1)
        {
            for (int* pa = (int*)array; pa < (int*)(array + (nmemb - 1 - n) * type); pa++)
            {
                printf("%d\n", *pa);
                if (*(pa + 1) < *pa)
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
                printf("%lf\n", *pa);
                if (*(pa + 1) < *pa)
                    swap((pa+1), pa, type);
            }
            n++;
        }
    }
}

//compare
char compare(const void *a1, const void *b1, size_t type)
{
    char* a = (char*)(a1+type-1);
    char* b = (char*)(b1+type-1);
    for(int i = 0; i < type; i++)
    {
        if (*a > *b)
            return '>';
        if (*a < *b)
            return '<';
        a--;
        b--;
    }
    return '=';
}

//swap
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

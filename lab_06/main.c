#include "swap.h"
#include <stdio.h>

#define size_of_array 100

#define size_of_string 10

void insertions_sort(int *pa, int* pa_fin);

int* array_init(int *pa, FILE *f, int* code);

int uniq_nums_counter(int* pa, int* pa_fin, int* a);

int main()
{
    printf("Input name of file: ");
    char string_array[size_of_string] = "";
    char *file_name = gets(string_array);
    FILE *f = fopen(file_name, "r");
    int a[size_of_array];
    int *pa = a;
    int code = 0;

    int* pa_fin = array_init(pa, f, &code);
    if ( !code )
    {
        insertions_sort(a, pa_fin);
        int counter = uniq_nums_counter(pa, pa_fin, a);
        printf("Result: %d", counter);
    }
    else
        printf("Error!");
    fclose(f);
    return 0;
}

int* array_init(int *pa_fin, FILE *f, int* code)
{
    int num;
    int stop = 0;
    while ( !feof(f) && !stop)
    {
        if ( fscanf( f, "%d", &num ) )
        {
            *pa_fin = num;
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

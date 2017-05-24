#include "swap.h"
#include "insertions_sort.h"
#include "uniq_nums_counter.h"
#include "array_init.h"
#include <stdio.h>

#define size_of_array 100

#define size_of_string 10

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


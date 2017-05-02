#include <stdio.h>

void swap(int* a, int* b);

void insertions_sort(int *pa, int* pa_fin);

int* array_init(int *pa, FILE *f, int* code);

int main()
{
    printf("Input name of file: ");
    char string_array[10] = "";
    char *file_name = gets(string_array);
    FILE *f = fopen(file_name, "r");
    int a[100];
    int *pa = a;
    int code = 0;

    int* pa_fin = array_init(pa, f, &code);
    if ( !code )
    {
        insertions_sort(a, pa_fin);
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

void swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void insertions_sort(int* a, int* pa_fin)
{
    int* pa = a;
    for (pa = a + 1; pa < pa_fin; pa++)
    {
        for (int* i= pa; i > a - 1; i--)
        {
            if (*(i-1) > *i)
            {
                swap(i-1, i);
            }
        }
    }
}

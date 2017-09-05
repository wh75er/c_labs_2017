#include <stdio.h>

#define start_size 100
#define size_of_string 10

int* array_init(int *pa_fin, FILE *f, int* code);
void array_print(int *pa, int *pa_fin);

int main()
{
    printf("Input name of file: ");
    char string_array[size_of_string] = "";
    char *file_name = gets(string_array);
    FILE *f = fopen(file_name, "r");

    int a[start_size];
    int* pa = a;
    int code = 0;

    printf("\n\n+\n\n");
    int* pa_fin = array_init(pa, f, &code);
    printf("\n\n+\n\n");
    if ( !code )
    {
        array_print(pa, pa_fin);
        printf("Result: +");
    }
    else
        printf("Error!");
    fclose(f);
    return 0;
}

int* array_init(int *pa_fin, FILE *f, int* code)
{
    int stop = 0;
    printf("\n\n+\n\n");
    while ( !feof(f) && !stop)
    {
        if ( fscanf( f, "%d", &(*pa_fin) ) )
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

void array_print(int *pa, int *pa_fin)
{
    for (int* pa_i = pa; pa_i < pa_fin; pa_i++)
            printf("%d ", *pa_i);
}

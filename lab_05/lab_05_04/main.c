#include <stdio.h>

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
        for (pa = a; pa < pa_fin - 1; pa++)
        {
            printf("+++");
            printf("%d\n", *pa);
        }
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
    return ++pa_fin;
}

void insertions_sort(int* pa, int* pa_fin)
{

}

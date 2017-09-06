#include <stdio.h>

#define start_size 100
#define size_of_string 10

int* array_init(int *pa_fin, FILE *f, int* code);
void array_print(int *pa, int *pa_fin);

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        printf("%c", argv[1]);
        FILE *f = fopen(argv[1], "r");

        int a[start_size];
        int* pa = a;
        int code = 0;

        printf("\n\n+\n\n");
        int* pa_fin = array_init(pa, f, &code);
        printf("\n\n+\n\n");
        if ( !code )
        {
            array_print(pa, pa_fin);
            printf("\nResult: +\n\n");
        }
        else
            printf("\nError!\n");
        fclose(f);
    }
    else
        printf("\nFile name entering error.\n");
    return 0;
}

int* array_init(int *pa_fin, FILE *f, int* code)
{
    int stop = 0;
    int count = 0;
    while ( !feof(f) && !stop)
    {
        if ( fscanf( f, "%d", &(*pa_fin) ) )
        {
            count++;
            printf("\n%d\n", count);
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
            printf("%d+ ", *pa_i);
}

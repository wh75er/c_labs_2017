#include <stdio.h>
#include <stdlib.h>


int len_array_int(FILE *f, int* code);
int len_array_double(FILE *f, int* code);

int* array_init(int *pa_fin, FILE *f, int* code);
void array_print(int *pa, int *pa_fin);


int main(int argc, char **argv)
{
    if (argc > 1)
    {
        FILE *f = fopen(argv[1], "r");

        int code = 0;
        int type = 0;                //Type of varAr (int)

        int len = len_array_int(f, &code);
        if (code)
        {
            type = 1;
            code = 0;
            rewind(f);
            len = len_array_double(f, &code);
        }
        if ( !code )
        {
            printf("%d", len);
            // Ввести здесь расширение на динамическиймиссив
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

void array_print(int *pa, int *pa_fin)
{
    for (int* pa_i = pa; pa_i < pa_fin; pa_i++)
            printf("%d ", *pa_i);
}

#include <stdio.h>

#define OK 0
#define Input_error 1

int* array_init(int *pa_fin, FILE *f);
int *array_copy(int* a, int* a_copy, int *pa_fin);

int amount_and_multiplication();
int array_amount_even();
int array_multiplication_uneven();

int* average();

int* array_without_negative_nums();

int* array_with_user_input();

int* array_switch_max_even_min_uneven();
int array_max_even();
int array_min_uneven();

int* array_3_switch();
int array_sum_3();

int* array_sequence();
int array_max();
int array_min();




int main()
{
    printf("Input name of file: ");
    char string_array[10] = "";
    char *file_name = gets(string_array);
    FILE *f = fopen(file_name, "r");
    int a[20];
    int a_copy[20];
    int *pa = a;
    int code = OK;

    int* pa_fin = array_init( pa, f);
    if (pa == pa_fin)
        code = Input_error;
    if ( !code )
    {
        int* pa_fin_copy = array_copy(a, a_copy, pa_fin);
        for (int* pa_i = a_copy; pa_i < pa_fin_copy; pa_i++)
            printf("%d ", *pa_i);
    }

    return 0;
}

int* array_init(int *pa_fin, FILE *f)
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
            stop = 1;
        }
    }
    return pa_fin;
}

int* array_copy(int *a, int *a_copy, int* pa_fin)
{
    for (int* pa_i = a; pa_i < pa_fin; pa_i++)
    {
        *a_copy = *pa_i;
        a_copy++;
    }
    return a_copy;
}

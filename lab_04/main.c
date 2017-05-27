#include <stdio.h>

#define OK 0
#define Input_error 1
#define file_name "in_0.txt"
#define sizeof_string 10
#define sizeof_array 20

int* array_init(int *pa_fin, FILE *f);
int *array_copy(int* a, int* a_copy, int *pa_fin);
void array_print(int* pa, int* pa_fin);

void amount_and_multiplication(int* pa, int* pa_fin);
int array_amount_even(int* pa, int* pa_fin);
int array_multiplication_uneven(int* pa, int* pa_fin);

void array_new_with_average(int* pa, int* pa_fin);
float average(int* pa, int* pa_fin);

void array_without_negative_nums(int* pa, int* pa_fin);

void array_with_user_input(int* pa, int* pa_fin);
int sum_of_array_nums(int* pa, int* pa_fin);
int *array_shift(int* pa, int* pa_fin);

void array_switch_max_even_min_uneven(int* pa, int* pa_fin);
int* array_max_even(int* pa, int* pa_fin);
int* array_min_uneven(int* pa, int* pa_fin);

void array_3_switch(int* pa, int* pa_fin);
int* array_max_3(int* pa, int* pa_fin);
int array_sum_3(int* pa, int* pa_fin);

void array_sequence(int* pa, int* pa_fin);
int* array_max(int* pa, int* pa_fin);
int* array_min(int* pa, int* pa_fin);
void insertions_sort(int* a, int* pa_fin);
void swap(int* a, int* b);



int main()
{
//    printf("Input name of file: ");
//    char string_array[sizeof_string] = "";
//    char *file_name = gets(string_array);
    FILE *f = fopen(file_name, "r");
    int a[sizeof_array];
    int *pa = a;

    int* pa_fin = array_init( pa, f);
    int code = OK;
    if (pa == pa_fin)
        code = Input_error;
    if ( !code )
    {
        int a_copy[sizeof_array];
        int* pa_copy = a_copy;
        int* pa_fin_copy = array_copy(pa, pa_copy, pa_fin);

        amount_and_multiplication( pa_copy, pa_fin_copy );

        pa_fin_copy = array_copy(pa, pa_copy, pa_fin);
        array_new_with_average( pa_copy, pa_fin_copy );

        pa_fin_copy = array_copy(pa, pa_copy, pa_fin);
        array_without_negative_nums(pa_copy, pa_fin_copy);

        pa_fin_copy = array_copy(pa, pa_copy, pa_fin);
        array_with_user_input(pa, pa_fin);

        pa_fin_copy = array_copy(pa, pa_copy, pa_fin);
        array_switch_max_even_min_uneven(pa_copy, pa_fin_copy);

        pa_fin_copy = array_copy(pa, pa_copy, pa_fin);
        array_3_switch(pa_copy, pa_fin_copy);

        pa_fin_copy = array_copy(pa, pa_copy, pa_fin);
        array_sequence(pa_copy, pa_fin_copy);
    }

    return 0;
}

//------------------------------- init --------------------------------------------------
int* array_init(int *pa_fin, FILE *f)
{
    int stop = 0;
    while ( !feof(f) && !stop)
    {
        if ( fscanf( f, "%d", &(*pa_fin) ) )
        {
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

void array_print(int *pa, int *pa_fin)
{
    for (int* pa_i = pa; pa_i < pa_fin; pa_i++)
            printf("%d ", *pa_i);
}

//------------------------------- 1 ex --------------------------------------------------
int array_amount_even(int *pa, int *pa_fin)
{
    int s = 0;
    for (int* pa_i = pa; pa_i < pa_fin; pa_i++)
        if ( !(*pa_i % 2) )
            s += *pa_i;
    return s;
}

int array_multiplication_uneven(int *pa, int *pa_fin)
{
    int mult = 1;
    for (int* pa_i = pa; pa_i < pa_fin; pa_i++)
        if ( *pa_i % 2 )
        {
            mult *= *pa_i;
        }
    return mult;
}

void amount_and_multiplication(int *pa, int *pa_fin)
{
    int amount = array_amount_even(pa, pa_fin);
    int mult = array_multiplication_uneven(pa, pa_fin);
    printf("Amount and multiplication:\n");
    printf("%d\n%d\n\n", amount, mult);
}

//------------------------------- 2 ex --------------------------------------------------
void array_new_with_average(int *pa, int *pa_fin)
{
    float average_num = average( pa, pa_fin );
    int* pa_new = pa;
    printf("New array (n > %.2f):\n", average_num);
    for (int* pa_i = pa; pa_i < pa_fin; pa_i++)
        if ( *pa_i > average_num )
        {
            *pa_new = *pa_i;
            pa_new++;
        }
    array_print(pa, pa_new);
}

float average(int *pa, int *pa_fin)
{
    float s = 0;
    float counter = 0;
    for (int* pa_i = pa; pa_i < pa_fin; pa_i++)
    {
            s += *pa_i;
            counter++;
    }
    return s/counter;
}

//------------------------------- 3 ex --------------------------------------------------
void array_without_negative_nums(int *pa, int *pa_fin)
{
    int* pa_new = pa;
    printf("\n\nNew array without negative nums:\n");
    for (int* pa_i = pa; pa_i < pa_fin; pa_i++)
        if ( *pa_i >= 0 )
        {
            *pa_new = *pa_i;
            pa_new++;
        }
    array_print(pa, pa_new);
}

//------------------------------- 4 ex --------------------------------------------------

void array_with_user_input(int *pa, int *pa_fin)
{
    int num;
    printf("\n\nInput your value: ");
    if ( scanf("%d", &num) )
    {
        for (int* pa_i = pa + 1; pa_i < pa_fin; pa_i++)
        {
            printf("%d", *pa_i);
            if  (*(pa_i) == num)
            {
                pa_fin = array_shift( pa, pa_i - 1 );
                *pa_i = sum_of_array_nums(pa, pa_i - 1);
            }
        }
        printf("\n\nNew array with user input:\n");
        array_print(pa, pa_fin);
    }
}

int sum_of_array_nums(int *pa, int *pa_fin)
{
    int s = 0;
    for (int* pa_i = pa; pa_i < pa_fin; pa_i++)
        s += *pa_i;
    return s;

}

int* array_shift(int *pa, int *pa_fin)
{
    for (int* pa_i = pa_fin+1; pa_fin > pa-1; pa_i--)
        *pa_i = *(pa_i - 1);
    pa_fin++;
    return pa_fin;
}

//------------------------------- 5 ex --------------------------------------------------
int* array_max_even(int* pa, int* pa_fin)
{
    int* max = pa;
    for (int* pa_i = pa; pa_i < pa_fin; pa_i++)
    {
        if ( (*pa_i > *max) && ( !(*pa_i % 2) ) )
        {
            max = pa_i;
        }
    }
    return max;
}

int* array_min_uneven(int *pa, int *pa_fin)
{
    int* min = pa;
    for (int* pa_i = pa; pa_i < pa_fin; pa_i++)
    {
        if ( (*pa_i < *min) && ( (*pa_i % 2) ) )
        {
            min = pa_i;
        }
    }
    return min;
}

void array_switch_max_even_min_uneven(int* pa, int* pa_fin)
{
    int* p_max_even = array_max_even(pa, pa_fin);
    int* p_min_uneven = array_min_uneven(pa, pa_fin);
    int c = *p_max_even;
    *p_max_even = *p_min_uneven;
    *p_min_uneven = c;
    printf("\n\nArray after switching even max and uneven min:\n");
    array_print(pa, pa_fin);
}

//------------------------------- 6 ex --------------------------------------------------
void array_3_switch(int* pa, int* pa_fin)
{
    int* num = array_max_3(pa, pa_fin);
    *num = array_sum_3(pa, pa_fin);
    printf("\n\nArray with 3-nums:\n");
    array_print(pa, pa_fin);
}

int* array_max_3(int* pa, int* pa_fin)
{
    int* max = pa;
    for (int* pa_i = pa; pa_i < pa_fin; pa_i++)
        if ( !(*max % 3) && !(*pa_i % 3) && *max < *pa_i )
            max = pa_i;
        else if ( *max % 3 && !(*pa_i % 3) )
            max = pa_i;
    return max;
}

int array_sum_3(int* pa, int* pa_fin)
{
    int s = 0;
    for (int* pa_i = pa; pa_i < pa_fin; pa_i++)
        if ( *pa_i % 10 == 3 )
            s += *pa_i;
    return s;
}

//------------------------------- 6 ex --------------------------------------------------
void array_sequence(int* pa, int* pa_fin)
{
    int* p_max = array_max(pa, pa_fin);
    int* p_min = array_min(pa, pa_fin);
    if  ( p_max < p_min )
        insertions_sort( p_max, p_min );
    else if ( p_min < p_max )
        insertions_sort( p_min, p_max );
    printf("\n\nCorrect sequence between min and max nums:\n");
    array_print(pa, pa_fin);

}

int* array_max(int* pa, int* pa_fin)
{
    int* max = pa;
    for (int* pa_i = pa; pa_i < pa_fin; pa_i++)
        if ( *max < *pa_i )
            max = pa_i;
    return max;
}

int* array_min(int* pa, int* pa_fin)
{
    int* min = pa;
    for (int* pa_i = pa; pa_i < pa_fin; pa_i++)
        if ( *min > *pa_i )
            min = pa_i;
    return min;
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

void swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

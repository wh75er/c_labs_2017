#include <stdio.h>

void insertions_sort(int *a, int n);

int size_of_array(FILE *f);

void array_init(int *pa, FILE *f, int size);

int main()
{
    printf("Input name of file: ");
    char string_array[10] = "";
    char *file_name = gets(string_array);
    FILE *f = fopen(file_name, "r");
    int size = size_of_array(f);
    int a[size];
    int *pa = a;
    array_init(pa, f, size);
    for (int i = 1; i < size; i++)
    {
        printf("%d\n", a[i]);
    }
    fclose(f);
    return 0;
}

int size_of_array(FILE *f)
{
    int counter = 0;
    int num;
    while ( !feof(f) )
    {
        if ( fscanf( f, "%d", &num ) )
            counter += 1;
    }
    return counter;
}

void array_init(int *pa, FILE *f, int size)
{
    fseek(f, 0, SEEK_SET);
    int num;
    int i = 0;
    while ( (!feof(f)) && (i != size) )
    {
        if ( fscanf( f, "%d", &num ) )
        {
            *pa = num;                                      //Dont work!
            i++;
        }
    }
}

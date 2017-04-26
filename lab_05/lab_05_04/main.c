#include <stdio.h>

void insertions_sort(int *a, int n);

void array_init(FILE *f);

int main()
{
    printf("Input name of file: ");
    char string_array[10] = "";
    char *file_name = gets(string_array);
    FILE *f = fopen(file_name, "r");
    array_init(f);
    return 0;
}

array_init(FILE *f)
{

}

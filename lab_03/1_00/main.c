#include <stdio.h>
#define file_with_in "in_4.txt"
#define good 0
#define bad -1

int process(FILE *f, int *code);
void output(int code, int result);

int main()
{
    printf("Program working with %s", file_with_in);
    FILE *f = fopen(file_with_in, "r");
    int code = 0;
    int result;
    result = process(f, &code);
    fclose(f);
    if (code)
        output(code, result);
    else
        output(code, 0);
}

int process(FILE *f, int *code)
{
    int num, max;
    *code = 1;
    max = 0;
    while (!feof (f) && *code)
    {
        if (fscanf(f, "%d", &num))
        {
            if (*code)
                if (max < num)
                    max = num;
            if (num < 0)
                *code = 1;
        }
        else
        {
            *code = 0;
        }
    }
    return max;
}

void output(int code, int result)
{
    if (code)
    {
        printf("\n\nError code: %d\n", 0);
        printf("Maximum number: %d", result);
    }
    else
    {
        printf("\n\nError code: %d\n", -1);
        printf("Maximum number: %s", "Error!");
    }
}

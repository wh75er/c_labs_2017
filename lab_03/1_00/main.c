#include <stdio.h>
#define file_with_in "in_1.txt"
#define good 0
#define bad -1

int process(FILE *f, int *code);
void output(code, result);

int main()
{
    printf("Program working with %s", file_with_in);
    FILE *f = fopen(file_with_in, "r");
    int code = 0;
    int result;
    result = process(f, &code);
    fclose(f);
    output(code, result);
}

int process(FILE *f, int *code)
{
    int num, max;
    *code = 0;
    max = 0;
    while (!feof (f))
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
            return 0;
        }
    }
    if (*code)
        return max;
    return 0;
}

void output(code, result)
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

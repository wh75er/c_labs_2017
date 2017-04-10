#include <stdio.h>
#define file_with_out "out_0.txt"
#define good 0
#define bad -1

int process(FILE *f, int result);

int main()
{
    printf("Input whole nums: ");
    int num, max, flag;
    flag = 0;
    max = 0;
    while (scanf("%d", &num) != 0)
    {
        if (flag != 0)
            if (max < num)
                max = num;
        if (num < 0)
            flag = 1;
    }
    if (flag != 0)
    {
        FILE *f = fopen(file_with_out, "r");
        printf("\nError code: %d\n", process(f, max));
        fclose(f);
        printf("Maximum number: %d", max);
    }
    else
    {
        printf("\nError code: -1\n");
        printf("Input error!");
    }
}

int process(FILE *f, int result)
{
    int check;
    if (fscanf(f, "%d", &check) != 0)
    {
        if (check == result)
            return good;
        else
            return bad;
    }
    return bad;
}

#include <stdio.h>

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
    printf("Maximum number: %d", max);
}

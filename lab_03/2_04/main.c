#include <stdio.h>
#define file_name "in_3.txt"

float mid(float sum, int count);
void max_min(FILE *f, float *max, float *min);
int file_proc(FILE *f, int *code, float *sum, float max, float min);

int main()
{
    printf("Working with %s\n", file_name);
    FILE *f = fopen(file_name, "r");
    float max, min;
    max_min(f, &max, &min);
    int code = 1;
    float sum = 0;
    int count = file_proc(f, &code, &sum, max, min);
    fclose(f);
    if ((!code) && (count))
        printf("Mid: %.4f", mid(sum, count));
    else
        printf("Error!");
}

float mid(float sum, int count)
{
    if (sum)
        return sum/count;
    return 0;
}

int file_proc(FILE *f, int *code, float *sum, float max, float min)
{
    fseek(f, 0, SEEK_SET);
    float num;
    int count, flag;
    count = 0;
    flag = 0;
    int stop = 0;
    while ((!feof(f)) && (!stop))
    {
        if (fscanf(f, "%f", &num))
        {
            if (num == min)
            {
                flag = 1;
            }
            if ((flag) && (num != min) && (num != max))
            {
                *sum += num;
                count += 1;
            }
            if ((flag) && (num == max))
            {
                *code = 0;
                stop = 1;
            }
        }
        else
            *code = 1;
    }
    return count;
}

void max_min(FILE *f, float *max, float *min)
{
    float num;
    fscanf(f, "%f", &num);
    *max = num;
    *min = num;
    while (!feof(f))
    {
        fscanf(f, "%f", &num);
        if (num > *max)
            *max = num;
        if (num < *min)
            *min = num;
    }
}

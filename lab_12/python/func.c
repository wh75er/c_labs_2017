#include <math.h>
#include <stdio.h>

void bycyclic(float* array, int len, int k)
{
    float tmp1, tmp2;
    int index;

    for (int i = 0; i < k; i++)
    {
        tmp1 = array[0];

        for (int j = 0; j < len; j++)
        {
            index = (j + 1) % len;
            tmp2 = array[index];
            array[index] = tmp1;
            tmp1 = tmp2;
        }
    }
}

void squares(float* in, int len, float* out)
{
    int j = 0;
    for (int i = 0; i < len; ++i)
    {
        float root = sqrt(in[i]);
        if (root / floor(root) == 1)
        {
            out[j] = in[i];
            j++;
        }
    }
}
#include <stdio.h>
#include <math.h>

float f(float x);

int main()
{
    printf("input x and eps(separated with space): ");
    float x, eps;
    scanf("%f%f", &x, &eps);

    float s = x;
    int index = 3;
    while ( fabs(s > eps) )
    {
        s -= pow(x, index)/index;
        index += 2;
    }
    printf("S(x) result: %.3f\n", s);
    printf("f(x) result: %.3f\n\n", f(x));
    printf("Absolute error: %.3f\n", fabs( f(x) - s) );
    printf("Relative error: %.3f", fabs( (f(x) - s) / f(x)) );
}

float f(float x)
{
    return atan(x);
}

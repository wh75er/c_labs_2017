#include <stdio.h>
#include <math.h>


float f(float x);
float amount(float x, float eps);

int main()
{
    printf("input x and eps(separated with space): ");
    float x, eps;
    if (scanf("%f%f", &x, &eps) && eps < 1.0 && fabs(x) <= 1)
	{
        float s = amount(x, eps);
		printf("S(x) result: %.3f\n", s);
		printf("f(x) result: %.3f\n\n", f(x));
		printf("Absolute error: %.3f\n", fabs( f(x) - s) );
		printf("Relative error: %.3f", fabs( (f(x) - s) / f(x)) );
	}
	else
		printf("Error!Check your input.");
}

float f(float x)
{
    return atan(x);
}

float amount(float x, float eps)
{
    float s = x;
    float t = x;
    int index = 3;
    int flag = 1;
    while ( fabs(t) > eps )
    {
        t = (pow(x, index)/index) * flag;
        s -= t;
        flag = flag * (-1);
        index += 2;
    }
    return s;
}

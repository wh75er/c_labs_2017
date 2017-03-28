#include <stdio.h>
#include <math.h>
#define index 3

float f(float x);

int main()
{
    printf("input x and eps(separated with space): ");
    float x, eps;
    if (scanf("%f%f", &x, &eps) && eps < 1.0)
	{
		float s = x;
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
	else
		printf("Error!Check your input.");
}

float f(float x)
{
    return atan(x);
}

#define TWO 2

#include <stdio.h>
#include <math.h>

int main()
{
	float a1, a2, h;
	
	
	printf("input base1, base2 and height: \n");
	scanf("%f", &a1);
	scanf("%f", &a2);
	scanf("%f", &h);
	
	float a3;
	a3 = ((a2 - a1)/TWO);
	a3 = sqrt(a3*a3 + h*h) * TWO + a1 + a2;
	
	
	printf("Perimeter: \n%.4f", a3);
	return 0;
}
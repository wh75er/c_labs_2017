#define TWO 2

#include <stdio.h>
#include <math.h>

int main()
{
	int a1, a2, h, a3;
	
	
	printf("input base1, base2 and height: \n");
	scanf("%d", &a1);
	scanf("%d", &a2);
	scanf("%d", &h);
	
	
	a3 = ((a2 - a1)/TWO);
	a3 = sqrt(a3*a3 + h*h) * TWO + a1 + a2;
	
	
	printf("Perimeter: \n%d", a3);
	return 0;
}
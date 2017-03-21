#define TWO 2

#include <stdio.h>
#include <math.h>

int main()
{
	printf("input base1, base2 and height: \n");
	int a1;
	scanf("%d", &a1);
	int a2;
	scanf("%d", &a2);
	int h;
	scanf("%d", &h);
	
	int a3;
	a3 = ((a2 - a1)/TWO);
	a3 = sqrt(a3*a3 + h*h) * TWO + a1 + a2;
	
	
	printf("Perimeter: \n%d", a3);
	return 0;
}
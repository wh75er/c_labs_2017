#include <stdio.h>

int main()
{
	printf("Input your height in meters: \n");
	float h;
	scanf("%f", &h);
	
	printf("Input weight in kilograms:\n");
	float m;
	scanf("%f", &m);
	
	printf("Input your r of rib cage cm:\n");
	float t;
	scanf("%f", &t);
	
	float f1, f2;
	f1 = h * 100 * t / 240; //cm
	f2 = m / h * h;    //m
	
	printf("Result#1 (cm): %.4f\nResult#2 (m): %.4f", f1, f2);
	return 0;
}
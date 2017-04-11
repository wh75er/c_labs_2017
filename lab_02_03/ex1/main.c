//Алгоритм Евклида для нахождения НОД.

#include <stdio.h>


int NOD(int a, int b);

int main()
{
	printf("Input a, b nums, separated with space: ");
	int a, b;
	if (scanf("%d%d", &a, &b) != 0)
	{
		printf("Result %d", NOD(a, b));
	}
	else
		printf("Error!Check your input.");
	return 0;
}


int NOD(int a, int b)
{
while (a * b != 0)
    {
		if (a > b)
			a = a % b;
		else
			b = b % a;
    }

    if (a != 0)
		return a;
    else
		return b;
}

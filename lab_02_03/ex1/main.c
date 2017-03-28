//Алгоритм Евклида для нахождения НОД.

#include <stdio.h>

int main()
{
    printf("Input a, b nums, separated with space: ");
    int a, b;
    if (scanf("%d%d", &a, &b) != 0)
	{
		while (a * b != 0)
		{
			if (a > b)
				a = a % b;
			else
				b = b % a;
		}

		if (a != 0)
			printf("NOD result: %d", a);
		else
			printf("Nod result: %d", b);
	}
	else
		printf("Error!Check your input.");
    return 0;
}

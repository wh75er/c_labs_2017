#include <stdio.h>

int main(void)
{
	float s;
	printf("Input s kopeck: ");
	scanf("%f", &s);
	
	int count, bottle;
	count = 0;
	bottle = 0;
	if (s > 45)
		while (s > 20)
		{
			bottle = s / 45;
			count += bottle;
			s = (bottle * 20) + (s - count * 45);
		}

	
	printf("\nResult: %d", count);
	return 0;
}
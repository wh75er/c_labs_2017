#include <stdio.h>

int main(void)
{
	int s;
	printf("Input s kopeck: ");
	scanf("%d", &s);
	
	s = (s - 20) / 25;

	printf("\nResult: %d", s);
	return 0;
}
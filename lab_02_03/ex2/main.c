//Программа определяет положение точки относительно прямой

#include <stdio.h>
#include <math.h>

int main()
{
    printf("Input coordinates of line(P1(x, y) P2(x, y)) and dot(M(x, y))(separated wtih space): ");
    float x1, y1, x2, y2, m1, m2;
    if (scanf("%f%f%f%f%f%f", &x1, &y1, &x2, &y2, &m1, &m2) != 0)
	{
		m1 = m1 - x1;
		m2 = m2 - y1;
		x1 = x2 - x1;
		y1 = y2 - y1;

		float res = x1 * m2 - m1 * y1;
		if (res == 0)
			printf("Dot on the line.");
		if (res > 0)
			printf("Dot above the line.");
		if (res < 0)
			printf("Dot under the line.");
	}
	else
		printf("Error!Check your input.");
	return 0;
}

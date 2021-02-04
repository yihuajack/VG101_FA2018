#include <stdio.h>

int main()
{
	double x;

	printf("Input x: ");
	scanf("%lf", &x);
	if (x < 0) x = -x;
	printf("|x| = %g\n", x);

	return 0;
}

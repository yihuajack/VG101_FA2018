#include <stdio.h>

int main()
{
	int C, F;

	printf("  oC\t  oF\n");
	for (C = -20; C <= 40; C += 10)
	{
		F = 32 + C * 9 / 5;
		printf("%4d\t%4d\n", C, F);
	}

	return 0;
}

/* digitsum.c */
#include <stdio.h>
int main()
{
	int n, dsum = 0;
	printf("This program sums the digits in an integer.\n");
	printf("Enter a positive integer:");
	scanf("%d", &n);
	while (n>0)
	{
		dsum += n % 10;
		n /= 10;
	}
	printf("The sum of the digits is %d\n", dsum);
	return 0;
}

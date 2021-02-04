#include <stdio.h>

main()
{
	double d1, d2;

	printf("This program add two numbers\n");
	printf("1st number? ");
	scanf("%lf", &d1);
	printf("2nd number? ");
	scanf("%lf", &d2);
	printf("The sum is %g.\n", d1 + d2);
}

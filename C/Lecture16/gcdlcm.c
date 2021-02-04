#include <stdio.h>
#include "arithmetic.h"

main()
{
	int x = 10, y = 25;

	if (isprime(x)) printf("x is a prime!\n");
	else printf("x is not a prime!\n");

	printf("The gcd = %d\n", gcd(x,y));
	printf("The lcm = %d\n", lcm(x,y));
}


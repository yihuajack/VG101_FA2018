#include <math.h>
#include "arithmetic.h"

/* return 1 if n is prime, otherwise return 0 */
int isprime(int n)
{
	int i;
	double limit = sqrt(n)+1;

	if (n==1) return 0;
	for (i=2; i<limit; i++)
		if (n%i == 0) return 0;
	return 1;
}

/* return the greatest common divisor of x and y */
int gcd(int x, int y)
{
	int r;
	while (1)
	{
		r = x % y;
		if (r == 0) break;
		x = y;
		y = r;
	}
	return y;
}

/* return the least common multiplier of x and y */
int lcm(int x, int y)
{
	return x * y / gcd(x, y);
}


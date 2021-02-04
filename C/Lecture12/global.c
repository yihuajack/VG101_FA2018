#include <stdio.h>

int times_global(int x);
int global = 2;

main()
{
	int local = 3;

	printf("global = %d, local = %d\n", global, local);
	local = times_global(local);
	printf("global = %d, local = %d\n", global, local);
}

int times_global(int x)
{
	global = 5;
	return x * global;
}

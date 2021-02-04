#include <stdio.h>
#include <stdlib.h>
#define N 10000000
int RollDie(void)
{
    int temp = rand();
	if (temp < RAND_MAX / 6) return 1;
	else if (temp < RAND_MAX / 6 * 2) return 2;
	else if (temp < RAND_MAX / 6 * 3) return 3;
	else if (temp < RAND_MAX / 6 * 4) return 4;
	else if (temp < RAND_MAX / 6 * 5) return 5;
	else return 6;
}

int main()
{
    int i, n;
    for (i=n=0; i<N; i++)
        if (RollDie() == 6) n++;
    printf("1/6 = %g, n/N = %g\n", 1.0/6, (double)n/N);
    return 0;
}

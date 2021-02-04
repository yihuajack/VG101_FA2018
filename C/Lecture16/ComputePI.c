#include <stdio.h>
#include <stdlib.h>
#define N 100000
int main()
{
    int i, sum;
    double x, y;
    for (i=sum=0; i<N; i++)
    {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;
        if (x*x + y*y < 1) sum++;
    }
    printf("PI = %g\n", 4.0 * sum / N);
    return 0;
}

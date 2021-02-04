#include <stdio.h>
main()
{
    int i, j;
    for (i=1; i<=19; i++)
    {
        for (j=1; j<=19; j++) printf("%4d", i*j);
        printf("\n");
    }
}
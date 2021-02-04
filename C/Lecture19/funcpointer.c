#include <stdio.h>

double plus(double a, double b)
{return a+b;}

double minus(double a, double b)
{return a-b;}

double operation(double a, double b, double (*op)(double, double))
{return (*op)(a, b);}

main()
{
    double a = 1, b = 2;
    printf("a = %g, b = %g\n", a, b);
    printf("a + b = %g\n", operation(a, b, plus));
    printf("a - b = %g\n", operation(a, b, minus));
}


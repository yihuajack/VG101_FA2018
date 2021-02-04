#include <stdio.h>
#include <math.h>
int main()
{
    double a,b,c,d,x1,x2,x,y;
    printf("Please enter the coefficients: ");
    scanf("%lf, %lf, %lf",&a,&b,&c);
    x=-b/(2*a);d=b*b-4*a*c;
    if (x==-0) x=0;
    if (d==0) printf("Solution: %g\n",x);
    else if (d>0)
    {
        x1=(-b+sqrt(d))/(2*a);x2=(-b-sqrt(d))/(2*a);
        printf("Solutions: %g, %g\n",x1,x2);
    }
    else
    {
        y=sqrt(-d)/(2*a);
        printf("Solutions: %g + %gi, %g - %gi\n",x,y,x,y);
    }
    return 0;
}
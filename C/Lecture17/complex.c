#include <stdio.h>
#include <math.h>

typedef struct
{
    double re, im;
}COMPLEX;

void InitComplex(COMPLEX *pc, double re, double im)
{
    pc->re = re; pc->im = im;
}

void CopyComplex(COMPLEX *pcDst, const COMPLEX *pcSrc)
{
    pcDst->re = pcSrc->re;
    pcDst->im = pcSrc->im;
}

double ComplexModulus(const COMPLEX *pc)
{
    return sqrt(pc->re * pc->re + pc->im * pc->im);
}

void AddComplex(COMPLEX *result, COMPLEX *c1, COMPLEX *c2)
{
    result->re = c1->re + c2->re;
    result->im = c1->im + c2->im;
}

char* DisplayComplex(const COMPLEX *pc)
{
    static char str[256];
    sprintf(str, "%g + %gi", pc->re, pc->im);
    return str;
}

int main()
{
    COMPLEX c1, c2, c3, c4;
    
    InitComplex(&c1, 1, 2);
    InitComplex(&c2, 2, 3);
    CopyComplex(&c3, &c2);
    printf("|c1| = %g\n", ComplexModulus(&c1));
    AddComplex(&c4, &c1, &c2);
    printf("c4 = %s\n", DisplayComplex(&c4));
    return 0;
}

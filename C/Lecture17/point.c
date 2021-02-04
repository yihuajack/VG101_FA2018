#include <stdio.h>
#include <math.h>

typedef struct
{
    double x, y;
}POINT;

void InitPoint(POINT *ppt, double x, double y)
{
    ppt->x = x;
    ppt->y = y;
}

void CopyPoint(POINT *ptDst, POINT ptSrc)
{
    ptDst->x = ptSrc.x;
    ptDst->y = ptSrc.y;
}

void DisplayPoint(POINT *ppt)
{
    printf("(%g, %g)", ppt->x, ppt->y);
}

double Distance(POINT pt1, POINT pt2)
{
    double temp;
    temp = (pt1.x-pt2.x)*(pt1.x-pt2.x)
                + (pt1.y-pt2.y)*(pt1.y-pt2.y);
    return(sqrt(temp));
}

int main()
{
    POINT pt1, pt2, pt3, *ppt;
    int *p;

    InitPoint(&pt1, 0, 0);
    InitPoint(&pt2, 3, 4);
    CopyPoint(&pt3, pt2);
    printf("pt1 = "); DisplayPoint(&pt1); printf("\n");
    printf("pt2 = "); DisplayPoint(&pt2); printf("\n");
    printf("pt3 = "); DisplayPoint(&pt3); printf("\n");
    printf("distance = %lf\n", Distance(pt1, pt3));
    return 0;
}

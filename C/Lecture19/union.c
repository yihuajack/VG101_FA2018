#include <stdio.h>
union MyUnion
{
    int n;
    unsigned char ch[4];
};

int main()
{
    union MyUnion u;
    int i;

    printf("Input u.n: ");
    scanf("%d", &u.n);
    for (i=0; i<4; i++)
        printf("ch[%d] = %x\n", i, u.ch[i]);
    return 0;
}

#include <stdio.h>
void t1(void);
main()
{
	t1();
	t1();
}
void t1(void)
{
	static int x=1;
	int y=1;
	x++;
	y++;
	printf("x=%d,y=%d\n",x,y)
}
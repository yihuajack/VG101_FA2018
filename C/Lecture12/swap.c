#include <stdio.h>

void swap(int x, int y)
{
	int t;

	printf("swap: x = %d, y = %d\n", x, y);
	t = x;
        x = y;
	y = t;
	printf("swap: x = %d, y = %d\n", x, y);
}

int main()
{
	int x = 2, y = 3;
	printf("main: x = %d, y = %d\n", x, y);
	swap(x, y);
	printf("main: x = %d, y = %d\n", x, y);
	return 0;
}

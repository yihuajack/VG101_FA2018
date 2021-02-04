#include <stdio.h>

void swap(int *px, int *py)
{
	int temp;
	temp = *px;
	*px = *py;
	*py = temp;
}

int main()
{
	int x = 1, y = 2;
	printf("x = %d, y = %d\n", x, y);
	swap(&x, &y);
	printf("x = %d, y = %d\n", x, y);
	return 0;
}

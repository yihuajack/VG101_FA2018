#include <stdio.h>
void printhex(int n)
{
	if (n < 10) printf("%d", n);
	else if (n == 10) printf("A");
	else if (n == 11) printf("B");
	else if (n == 12) printf("C"); 
	else if (n == 13) printf("D");
	else if (n == 14) printf("E"); 
	else if (n == 15) printf("F");
	else {printhex(n/16); printhex(n%16);}
}

int main()
{
	int n;
	printf("Input n: "); scanf("%d", &n);
	printhex(n); printf("\n");
	return 0;
}

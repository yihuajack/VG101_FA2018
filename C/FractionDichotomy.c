#include<stdio.h>
int main () {
	int i,j,k;
	scanf("%d", &k);
	double count = 1.0 / k;
	double x;
	for(i = 1; i <= 2 * k; i ++){
		double temp = (count - 1.0 / i);
		if(temp == 0)
			continue;
		x = 1 / temp;
		if(x >= 2 * k)
			printf("1/%d=1/%.0lf+1/%d\n", k, x, i);
	}  	
	return 0;
}
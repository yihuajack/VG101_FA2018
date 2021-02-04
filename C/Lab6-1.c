#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    int i,j,n,X,a,b,xbar,x=0,y=0,*xt,*yt,click=0,quit=0,t=0;
    scanf("%d %d",&n,&X);
	xt = (int*)malloc(sizeof(int)*250584); yt = (int*)malloc(sizeof(int) * 250584);
    for (i=0;i<n;i++){
        scanf("%d %d %d",&xbar,&a,&b);
		while (xt<xbar) {xt[t]++;yt[t]++;}
        while (y>a-xbar+x+2) {x++;y--;}
		while (x < xbar) { x++; y++; click++; xt[t] = x; yt[t] = y; t++; }
		if (y<=a||y>=b) {
			for (j=t-1;j>=9*(t-1)/10;j--) {
				if (yt[j] + xbar - xt[j]<b&&yt[j] + xbar - xt[j]>a) { y = yt; click=click-(t-j)+xbar-xt[j]+1; quit = 0; break; }
				else quit=1;
			}
		}
    }
	if (quit==0) printf("%d\n",click);
	else printf("NIE\n");
	free(xt); free(yt);system("pause"); 
    return 0;
}
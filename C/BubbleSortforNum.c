#include <stdio.h>
int main(){
	int i,j,t,n=2;
	int a[2]={2,1};
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				t=a[j+1];
				a[j+1]=a[j];
				a[j]=t;
			}
		}
	}
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
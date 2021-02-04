#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void quick_sort(int s[],int l,int r){
    if(l < r) {
        int i=l,j=r,x=s[l];
        while(i<j){
            while(i<j && s[j]>=x) j--;
            if(i<j)  s[i++]=s[j];
            while(i<j && s[i]<=x)  i++;
            if(i<j) s[j--]=s[i]; 
        }
        s[i]=x;
        quick_sort(s,l,i-1);quick_sort(s,i+1,r);        
    }
}
int main(){
    clock_t start,finish;
    double totaltime;
    start=clock();
    int a[] = {1,8,44,77,35,65,78,12,25,455,20,15,45};
    int length = sizeof(a)/sizeof(int);
    printf("原序列为： ");
    for(int i=0;i<length;i++) printf("%d ",a[i]);
    quick_sort(a,0,length);
    printf("\n排序后的序列为：");
    for(int i=0;i<length;i++) printf("%d ",a[i]);
    finish=clock();
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    printf("\n程序运行的时间为: %.5f 秒\n",totaltime);
}
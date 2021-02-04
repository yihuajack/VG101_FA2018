#include<stdio.h>
#include<math.h>
/*输入的图形的顶点数量,一定要输入正确的顶点数量,修改这个值可以得到不同的点情况下的
正方形数量*/
#define N  13
 
#define B  ((N*(N-1)*(N-2)*(N-3))/(4*3*2))
typedef struct{
  int x;
  int y;
}Point;
typedef struct{
  Point a[4];
}Squre;

 
Point dian[N];
Point queue[4];   /*存放矩形坐标*/
Squre tmp;
int k=0;
int  top=0;
void  comb(int s,int n,int m);
int  function(Squre s);

int main(void){
  int i=0;
   
  int num=(int)B;
  printf("%d",num);
  for(i=0;i<N;i++){
      printf("\nplease input the %d zuo biao :",i+1);
      scanf("%d %d",&dian[i].x,&dian[i].y);
  }

  comb(0,N,4);

  printf("the sum of sibianxing are %d\n",k);
  getch();
  return 0;
}
/*判断是不是正方形，若是返回1，否则返回0*/
int function(Squre s){
    int e,b,c,d,k;
    e=pow((s.a[0].x-s.a[1].x),2)+pow((s.a[0].y-s.a[1].y),2);
    b=pow((s.a[0].x-s.a[2].x),2)+pow((s.a[0].y-s.a[2].y),2);
    if(e>b){ /*e作为对角线存在*/
         c=pow((s.a[2].x-s.a[1].x),2)+pow((s.a[1].y-s.a[2].y),2);
         d=pow((s.a[3].x-s.a[1].x),2)+pow((s.a[3].y-s.a[1].y),2);
         k=pow((s.a[0].x-s.a[3].x),2)+pow((s.a[0].y-s.a[3].y),2);
         if((b==c)&&(c==d)&&(d==k)&&(k==b)&&(e==(b+c)))
             return 1;
    }else if(e==b){
         c=pow((s.a[1].x-s.a[3].x),2)+pow((s.a[1].y-s.a[3].y),2);
         d=pow((s.a[2].x-s.a[3].x),2)+pow((s.a[2].y-s.a[3].y),2);
         k=pow((s.a[1].x-s.a[2].x),2)+pow((s.a[1].y-s.a[2].y),2);
         if((e==c)&&(c==d)&&((e+b)==k))
             return 1;
    }else {    /*b作为对角线存在*/
         c=pow((s.a[2].x-s.a[1].x),2)+pow((s.a[1].y-s.a[2].y),2);
         d=pow((s.a[3].x-s.a[2].x),2)+pow((s.a[3].y-s.a[2].y),2);
         k=pow((s.a[0].x-s.a[3].x),2)+pow((s.a[0].y-s.a[3].y),2);
         if((e==c)&&(c==d)&&(d==k)&&(k==e)&&(b==(e+c)))
             return 1;
    }
    return 0;
}
/*组合算法：用于得到可能构成正方形的矩形集合
 m代表选取的个数就是组合数C(m,n),从n中选取m个点
 并返回正方形数量*/
void   comb(int s,int n,int m)
{
    int i,j=0;
    if(s>n) return  ;
    if(top==m) {
       for(i=0;i<m;i++){
           tmp.a[i]=queue[i];
    }
     j=function(tmp);
     if(j==1){
       k++;
     }
       return  ;
    }
    queue[top++]=dian[s];
    comb(s+1,n,m);
    top--;
    comb(s+1,n,m);
}
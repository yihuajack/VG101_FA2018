#include<stdio.h>
#include<string.h>
void Encode(char *str){
	int i,len=strlen(str);
	for (i=0;i<len;i++){
		if ((str[i]>=65&&str[i]<=89)||(str[i]>=97&&str[i]<=121)) str[i]+=1;
		if (str[i]==90||str[i]==122) str[i]-=25;
	}
}
void vg101_gets(char *str, int count){
    int i = 0;
    char ch = getchar();
    while (ch != '\n' && i < count-1){
		str[i++] = ch;
    		ch = getchar();
	}
    str[i] = '\0';
}
int main(){
    char str[256];
    printf("Please input a string: ");
    vg101_gets(str, 256);
	Encode(str);
	printf("str = %s\n", str);
	return 0;
}
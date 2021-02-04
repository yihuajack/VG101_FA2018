#include<stdio.h>
#include<string.h>
char* strshift(char *str, int shift){
	int i,j,len=strlen(str);char t;
 	if (shift>0){
		while (shift>len) shift-=len;
		for (i=0;i<shift;i++){
			t=str[len-shift+i];
			for (j=len-shift+i-1;j>=i;j--){
				str[j+1]=str[j];
			}
			str[i]=t;
		}
	}
	else if (shift<0){
		while (-shift>len) shift+=len;
		for (i=-shift-1;i>=0;i--){
			t=str[i];
			for (j=i+1;j<=len+shift+i;j++){
				str[j-1]=str[j];
			}
			str[len+shift+i]=t;
		}
	}
    return str;
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
    int shift;
    char str[256];
    char *pstr;
    printf("Please input a string: ");
    vg101_gets(str, 256);
    printf("Please input the shift: ");
    scanf("%d", &shift);
    pstr = strshift(str, shift);
    printf("str = %s\n", str);
    printf("*pstr = %s\n", pstr);
    return 0;
}
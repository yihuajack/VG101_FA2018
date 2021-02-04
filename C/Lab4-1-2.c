#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int i = 0, j = 1, p = 0;
	char infix[100], postfix[100],stack[100],c;
	while (infix[i] != '\n') { i++; scanf("%c", &infix[i]); }
	i = 1; c = infix[i]; i++;
	while (c != '\n') {
		switch (c) {
		case '(':p++; stack[p] = c; break;
		case ')':
			while (stack[p] != '(') { postfix[j] = stack[p]; p--; j++; postfix[j] = ','; j++; }
			p--; break;
		case '+':
		case '-':
			while (p != 0 && stack[p] != '(') { postfix[j] = stack[p]; p--; j++; postfix[j] = ','; j++;}
			p++; stack[p] = c;break;
		case '*':
		case '/':
			while (stack[p] == '*' || stack[p] == '/') { postfix[j] = stack[p]; p--; j++; postfix[j] = ','; j++;}
			p++; stack[p] = c;break;
		default:
			while (c >= '0'&&c <= '9') {postfix[j] = c;j++;c = infix[i];i++;}
			i--;postfix[j] = ','; j++; break;
		}
		c = infix[i]; i++;
	}
	while (p != 0) { postfix[j] = stack[p]; j++; p--; postfix[j] = ','; j++;}
	postfix[j-1] = '\n';
	for (i = 1; i <= j; i++) printf("%c", postfix[i]);
	system("pause");
	return 0;
	
}
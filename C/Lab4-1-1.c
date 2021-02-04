#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() {
	int i = 0;int j = 1;
	double stack[100];
	char post[100]; char c;
	scanf("%c", &c);
	while (c != '\n') {
		while (isdigit(c)) {
			post[i] = c; i++;
			scanf("%c", &c);
			if (c == ',') {
				stack[j] = atof(post);
				i = 0; j++;
			}
		}
		memset(post, 0, sizeof(post));
		switch (c) {
		case '+':stack[j - 2] = stack[j - 2] + stack[j - 1]; j--; break;
		case '-':stack[j - 2] = stack[j - 2] - stack[j - 1]; j--; break;
		case '*':stack[j - 2] = stack[j - 2] * stack[j - 1]; j--; break;
		case '/':stack[j - 2] = stack[j - 2] / stack[j - 1]; j--; break;
		}
		scanf("%c", &c);
	}
	printf("%g\n", stack[1]);
	return 0;
}
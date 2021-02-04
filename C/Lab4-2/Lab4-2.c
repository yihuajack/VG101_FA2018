#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h> 
#include<time.h>
#include<string.h>
#include <windows.h>
#include"wordbank.h"
int dordiv(char word[10], char uset[26], int len);
int main() {
	int i, j, k = 0, n = 0,r,ritem, rmult, len,sign = 0, note = 0, score = 10;
	char word[10], pass[10], c, item[5] = { '*','/','#','@','$' }, wans[30] = { '\0' },uset[26],subitem[4] = { '*','/','#','@'};
	srand((unsigned)time(NULL));
	r = rand() % nWords - 1;
	r = 0;
	for (j = 0; words[r][j] != '\0'; j++) word[j] = words[r][j];
	len = j;
	char a = 'a';
	for (j = 0; j < 26; j++) uset[j] = a + j;
	for (j = 0; j <len; j++) pass[j] = '_';
	for (j = 0; j < len; j++) {
		while (pass[j] == '_'&&score != 0) {
			printf("Score: "); printf("%d\n", score);
			printf("Item: ");
			for (i = 0; i < 5; i++) printf("%c ", item[i]); printf("\n");
			for (i = 0; i < len; i++) printf("%c", pass[i]); printf("\n");
			printf("Already known wrong answers: ");
			i = 0;
			while (wans[i] != '\0') {
				if (note == 1) wans[n-1] = '\0';
				for (i = 0; i < n-1; i++) {
					printf("%c", wans[i]); printf(",");
				}
				printf("%c", wans[n - 1]); i++;
			}
			printf("\n");note = 0;
			printf("Please enter a letter (a-z): "); char space;
			scanf("%c", &c); scanf("%c", &space); printf("\n");
				for (i = 0; i < len; i++) {
					if (word[i] == c) { pass[i] = word[i]; note = 1; }
					else if (c == '*') {
						rmult = rand() % len;
						pass[rmult] = word[rmult]; break;
					}
					else if (c == '/') {
						while (sign == 0) sign = dordiv(word, uset, len);
						wans[n] = uset[sign]; n++;
						while (sign == 0) sign = dordiv(word, uset, len);
						wans[n] = uset[sign]; n++; break;
					}
					else if (c == '@') {
						for (k = 0; k < len; k++) {
							if (word[k] == 'a' || word[k] == 'e' || word[k] == 'i' || word[k] == 'o' || word[k] == 'u') pass[k] = '@';
						}break;
					}
					else if (c == '$') {
						ritem = rand() %4; c= subitem[ritem]; break;
						if (c == '*') {
							rmult = rand() % len;
							pass[rmult] = word[rmult]; break;
						}
						else if (c == '/') {
							while (sign == 0) sign = dordiv(word, uset, len);
							wans[n] = uset[sign]; n++;
							while (sign == 0) sign = dordiv(word, uset, len);
							wans[n] = uset[sign]; n++; break;
						}
						else if (c == '@') {
							for (k = 0; k < len; k++) {
								if (word[k] == 'a' || word[k] == 'e' || word[k] == 'i' || word[k] == 'o' || word[k] == 'u') pass[k] = '@';
							}break;
						}
						else{ score = 0; break; }
					}
					else if (c == '#') { score = 0; break; }
				}
			if (c!='*'&&c!='/'&&c!='@'&&c!='$'&&c!='#') {
				score--; wans[n] = c; n++; 
			}
			if (note == 1) score++;
			for (k =4; k >= 0; k--) {
				if (item[k] == c) {
					for (i =k+1; i<=4; i++) {
						item[i - 1] = item[i];
					}
					item[i-1] = '\0';
				}
			}
		}
	}
	printf("Score: "); printf("%d\n", score);
	printf("Item: ");
	for (i = 0; i < 5; i++) printf("%c ", item[i]); printf("\n");
	for (i = 0; i < len; i++) printf("%c", pass[i]); printf("\n");
	printf("Already known wrong answers: ");
	i = 0;
	while (wans[i] != '\0') {
		if (note == 1) wans[n - 1] = '\0';
		for (i = 0; i < n - 1; i++) {
			printf("%c", wans[i]); printf(",");
		}
		printf("%c", wans[n - 1]); i++;
	}
	printf("\n"); note = 0;
	if (score == 0) printf("You lose.");
	else printf("You win.");
	return 0;
}
int dordiv(char word[10],char uset[26],int len) {
	int rdiv,k,sign;
	rdiv = rand() % 25;
	for (k = 0; k < len; k++) {
		if (word[k] == uset[rdiv]) { sign = 0; break; }
		else sign = 1;
	}
	sign = sign * rdiv;

	return sign;
}
#include <stdio.h>
#include <string.h>
int main() {
	int digit1[256], digit2[256], sum[256],i,len1,len2,max;
	char str1[256],str2[256];
	printf("1st integer? ");
	scanf("%[^\n]", str1);
	len1 = strlen(str1);
	for (i = 0; i < len1; i++) digit1[i] = str1[i] - '0';
	printf("2nd integer? ");
	scanf(" %[^\n]", str2);
	len2 = strlen(str2);
	for (i = 0; i < len2; i++) digit2[i] = str2[i] - '0';
	for (i = 0; i < len1; i++) {
		digit1[256-len1+i] = digit1[i];
	}
	for (i = 0; i < 256 - len1; i++) digit1[i] = 0;
	for (i = 0; i < len2; i++) {
		digit2[256-len2+i] = digit2[i];
	}
	for (i = 0; i < 256 - len2; i++) digit2[i] = 0;
	for (i = 0; i < 256; i++) sum[i] = 0;
	for (i = 255; i > 0; i--) {
		sum[i] = sum[i] + digit1[i] + digit2[i];
		if (sum[i] > 9) {
			sum[i - 1]++; sum[i] = sum[i] - 10;
		}
	}
	printf("Their sum is ");
	if (len1 > len2) max = len1;
	else max = len2;
	if (sum[256 - max] > 0)
		for (i = 0; i < 256 - max; i++) sum[i] = -1;
	else
		for (i = 0; i < 255 - max; i++) sum[i] = -1;
	if (str1[0] == '0'&&str2[0] == '0')
		for (i = 0; i < 255; i++) sum[i] = -1;
	for (i = 0; i < 256; i++) {
		if (sum[i] >= 0) printf("%d", sum[i]);
	}
	return 0;
}
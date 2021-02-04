#include<string.h>
#include<stdio.h>
int main(void)
{
	char string[17];
	char*ptr,c='r';
	strcpy(string,"This is a string");
	ptr=strchr(string,c);
	if(ptr)
		printf("The character %c is at position: %ld\n",c,ptr-string);
	else
		printf("The character was not found\n");
	return 0;
}
#include <stdio.h>
#include <string.h>

void convert(char arr[], int sz)
{
	int i;

	for (i=0; i<sz; i++)
	{
		/* convert lower case into upper case */
		if (arr[i] >='a' && arr[i] <='z')
			arr[i] = arr[i] - 'a' + 'A';
		if (arr[i] >='A' && arr[i] <='Z')
		{
			if (arr[i] == 'S') arr[i] = '7';
			else if (arr[i] == 'V') arr[i] = '8';
			else if (arr[i] == 'Y' || arr[i] == 'Z') arr[i] = '9';
			else arr[i] = (arr[i]-'A') / 3 + '2';
		}
	}
}

main()
{
	char phoneNumber[30];
	printf("Please enter a phone number: ");
	scanf("%s", phoneNumber);
	printf("Phone number = %s\n", phoneNumber);
	convert(phoneNumber, strlen(phoneNumber));
	printf("Phone number = %s\n", phoneNumber);
}
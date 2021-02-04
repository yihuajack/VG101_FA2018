#include <stdio.h>
#include "wordbank.h"

// A sample .c file visiting words in wordbank.h

int main()
{
	for (int i=0; i<nWords; i++)
	{
		for (int j=0; words[i][j] != '\0'; j++)
			printf("%c ", words[i][j]);
		printf("\n");
	}
	return 0;
}
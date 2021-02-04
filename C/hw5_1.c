#include <stdio.h>
#include <string.h>
#define LENGTH 1000 /* max input characters */
#define N 100 /* max number of elements in the array */
/* finish this function */
int SecondSmallest(int array[], int n)
{ /* find the second smallest number in the array, where n is the number of elements */
	int ind, smallest,start = 0, temp;
	while (start < n)
	{
		smallest = start;
		for (ind = start + 1; ind < n; ind++)
			if (array[ind] < array[smallest]) smallest = ind;
		temp = array[start];
		array[start] = array[smallest];
		array[smallest] = temp;
		start++;
	}
	return array[1];
}
int main()
{
	char str[LENGTH]; /* max input characters */ int arr[N]; /* less than N numbers */
	int i, n, start, end, len;
	for (i = 0; i < LENGTH; i++) str[i] = 0; /* initialize */
	printf("Input numbers: ");
	scanf("%[^\n]", str);
	len = strlen(str); /* length of str */ start = n = 0; /* initialize */
	while (start < len)
	{
		/* skip spaces */
		while (start < len && str[start] == ' ') start++;
		if (start == len) break; /* end of string */
		/* find end of the number */ end = start;
		while (end < len && str[end] != ' ') end++;
		/* convert str[start..end] to number */ arr[n] = 0;
		for (i = start; i < end; i++) arr[n] = arr[n] * 10 + str[i] - '0';
		n++; /* number of elements */
		start = end + 1;
	}
	/* call the function SecondSmallest */
	printf("The second smallest number is %d\n", SecondSmallest(arr, n));
	return 0;
}
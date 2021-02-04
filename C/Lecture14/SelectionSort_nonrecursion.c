#include <stdio.h>

void SelectionSort(int arr[], int sz)
{
	int ind, smallest;
	int start = 0, temp;

	while (start < sz)
	{
		/* 1: find the smallest number in arr[start...end] */
		smallest = start;
		for (ind = start + 1; ind < sz; ind++)
			if (arr[ind] < arr[smallest]) smallest = ind;
		/* 2: swap the number with the arr[start] */
		temp = arr[start];
		arr[start] = arr[smallest];
		arr[smallest] = temp;
		/* 3: start++ */
		start++;
	}
}

void main()
{
	int i, arr[] = {11, 7, 2, 13, 23, 5};
	for (i=0; i<6; i++) printf("%d  ", arr[i]);
	printf("\n");
	SelectionSort(arr, 6);
	for (i=0; i<6; i++) printf("%d  ", arr[i]);
	printf("\n");
}
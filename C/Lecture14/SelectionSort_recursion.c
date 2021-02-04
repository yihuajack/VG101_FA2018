#include <stdio.h>

void SelectionSort(int arr[], int sz)
{
	int ind, smallest = 0;
	int temp;

	if (sz == 1) return;
	/* 1: find the smallest number in arr[] */
	
	for (ind = 1; ind < sz; ind++)
		if (arr[ind] < arr[smallest]) smallest = ind;
	/* 2: swap the number with the arr[0] */
	temp = arr[0];
	arr[0] = arr[smallest];
	arr[smallest] = temp;
	/* 3: do the same thing for arr[1...end] */
	SelectionSort(&arr[1], sz-1);
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
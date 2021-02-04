#include <stdio.h>

int BinarySearch(int arr[], int sz, int x)
{
	int start = 0, end = sz-1, mid;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (arr[mid] == x) return mid;
		else if (arr[mid] < x) start = mid + 1;
		else end = mid -1;
	}
	return -1;
}

void main()
{
	int arr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
	int ind = BinarySearch(arr, 10, 13);
	printf("ind = %d\n", ind);
}
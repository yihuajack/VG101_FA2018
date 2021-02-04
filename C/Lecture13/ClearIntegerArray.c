#include <stdio.h>
#define N_VALUES 5

void ClearIntegerArray(int arr[], int size)
{
	int i;
	for(i=0; i<size; i++) arr[i] = 0;
}

int main()
{
	int i, values[N_VALUES];

	ClearIntegerArray(values, N_VALUES);
	for (i=0; i<N_VALUES; i++)
	      printf("values[%d] = %d\n", i, values[i]);
	return 0;
}

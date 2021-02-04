#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int input = 0; int num = 0; int cap = 1; char space; int s = 1;
	int *arr1 = (int *)malloc(s * sizeof(int)); int number; int i = 0; int* arr2 = (int *)malloc(s * sizeof(int)); int o = 0;
	while (input != 8)
	{
		printf("Please choose function: (1. num_elements, 2. available_capacity, 3. push_back, 4. pop_back(),5. is_empty, 6. sum, 7. reserve, 8. quit)");
		scanf("%d", &input); scanf("%c", &space);
		if (input==1)
		{
			printf("The array contains %d element(s).\n", i);
		}
		if (input == 2)
		{
			printf("The available camapcity is %d.\n", (s-i));
		}
		if (input == 3)
		{
			printf("Please input a number:");
			scanf("%d", &number);
			if (i == s)
			{
				arr2 = (int *)malloc(s * sizeof(int));
				for (int p = 0; p < i; p++)
				{
					arr2[p]= arr1[p];
				}
				s = 2 * s;
				arr1 = (int *)malloc(s * sizeof(int));
				for (int p = 0; p < i; p++)
				{
					arr1[p] = arr2[p];
				}				
			}
			arr1[i++] = number;
		}
		if (input == 4)
		{
			if (i != 0)
			{
				printf("Number %d deleted.\n", arr1[i - 1]);
				i = i - 1;
			}
			else
			{
				printf("Error: array already empty.\n");
			}
		}
		if (input == 5)
		{
			if (i != 0)
			{
				printf("The array is not empty.\n");
			}
			if (i == 0)
			{
				printf("The array is empty.\n");
			}
		}
		if (input == 6)
		{
			int sum = 0;
			for (int p = 0; p < i; p++)
			{
				sum = sum + arr1[p];
			}
			printf("The sum is %d\n", sum);
		}
		if (input == 7)
		{
			printf("How large should the array be?");
			scanf("%d", &o);
			arr2 = (int *)malloc(s * sizeof(int));
			for (int p = 0; p < i; p++)
			{
					arr2[p] = arr1[p];
			}
			s = o;
			arr1 = (int *)malloc(s * sizeof(int));
			for (int p = 0; p < i; p++)
			{
				arr1[p] = arr2[p];
			}
		}
	}
	free(arr1); free(arr2);
	printf("Goodbye!");
	return 0;
}
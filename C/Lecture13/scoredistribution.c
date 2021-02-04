#include <stdio.h>

void DistributeScore(int scores[], int n, int counts[])
{
	int i, range;

	for (i = 0; i < n; i++)
	{
		range = scores[i] / 10;
		counts[range]++;
	}
}

void DisplayHistogram(int counts[])
{
	int i, j;
	for (i = 9; i >= 0; i--)
	{
		printf("%d: ", i * 10);
		for (j = 0; j < counts[i]; j++)
			printf("*");
		printf("\n");
	}
}
void Histogram(int scores[], int n)
{
	int counts[10], i;

	for (i = 0; i < 10; i++) counts[i] = 0;
	DistributeScore(scores, n, counts);
	DisplayHistogram(counts);
}

main()
{
	/* Read in all scores */
	int scores[] = { 99, 83, 45, 32, 55, 87, 98, 32, 88, 84 };
	Histogram(scores, 10);
}
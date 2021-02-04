#include <stdio.h>
#include <stdlib.h>
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

int main()
{
    int i, N, *p;
    
    printf("Please enter the total number of integers for sorting: ");
    scanf("%d", &N);
    p = (int*)malloc(sizeof(int)*N);
    for (i=0; i<N; i++)
    {
        printf("Please enter p[%d]:", i);
        scanf("%d", p+i);
    }
    SelectionSort(p, N);
    printf("The sorted array is: ");
    for (i=0; i<N; i++) printf("%d  ", p[i]);
    printf("\n");
    free(p);
    return 0;
}

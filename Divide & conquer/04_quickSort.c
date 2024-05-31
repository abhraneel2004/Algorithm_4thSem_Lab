#include <stdio.h>

int partition(int arr[], int si, int ei)
{
    int pivot = arr[si];
    int i, j = si;
    for (i = si + 1; i <= ei; i++)
    {
        if (arr[i] < pivot)
        {
            j++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

        }
    }

    int temp = arr[j];
    arr[j] = arr[si];
    arr[si] = temp;

    return j;
}

void quickSort(int arr[], int si, int ei)
{
    if (ei > si)
    {
        int part = partition(arr, si, ei);
        quickSort(arr, si, part - 1); // Corrected the second parameter
        quickSort(arr, part + 1, ei); // Passed ei as ending index
    }
}

int main(void)
{
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter the element %d : ", i);
        scanf("%d", &arr[i]);
    }
    printf("\n");
    printf("Array Before Sorting: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    quickSort(arr, 0, n - 1);
    printf("\n");
    printf("Array After Sorting: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    return 0;
}
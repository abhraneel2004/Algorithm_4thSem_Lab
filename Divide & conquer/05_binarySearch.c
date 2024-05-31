#include <stdio.h>

int binarySearch(int arr[], int n, int key){
    int i, si = 0, ei = n - 1;
    while (ei>si){
        int mid = si + (ei-si)/2;
        if (arr[mid] == key){
            return mid;
        }
        else if (arr[mid]> key){
            ei = mid-1;
        }
        else{
            si = mid+1;
        }
    }
    return -1;
}

int main(void){
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n], key;
    for (i = 0; i < n; i++)
    {
        printf("Enter the element %d : ", i);
        scanf("%d", &arr[i]);
    }
    printf("\n");
    printf("Enter the element to search: ");
    scanf("%d", &key);

    int a = binarySearch(arr, n, key);
    if(a==-1){
        printf("No element found\n");
    }
    else{
        printf("Element found at index %d\n", a);
    }
    return 0;
}
#include<stdio.h>

void insertionSort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(void){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];

    for(int i=0; i<n; i++){
        printf("Enter element %d: ", i);
        scanf("%d",&arr[i]);
    }

    printf("Array before Sorting: \n");
    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
    insertionSort(arr, n);
    printf("\nArray after Sorting: \n");
    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }

    return 0;
}
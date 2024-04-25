#include<stdio.h>

void bubbleSort(int arr[], int n){
    for(int i =0; i < n-1; i++){
        int c = 0;
        for(int j =0; j<n-i-1; j++){
            if (arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                c++;
            }
        }
        if (c==0) break;
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
    bubbleSort(arr, n);
    printf("\nArray after Sorting: \n");
    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }

    return 0;
}
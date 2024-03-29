#include<stdio.h>

void merge(int arr[], int si, int mid, int ei){
    int merged[ei-si+1];
    int i1=si,i2=mid+1,x=0;
    while(i1<=mid && i2<=ei){
        if (arr[i1]>arr[i2]){
            merged[x] = arr[i2];
            x++;
            i2++;
        }
        else{
            merged[x] = arr[i1];
            x++;
            i1++;
        }
    }
    while(i1<=mid){
        merged[x++] = arr[i1++];
    }
    while(i2<=ei){
        merged[x++] = arr[i2++];
    }

    for(int i = 0; i<ei-si+1; i++){
        arr[si+i] = merged[i];
    }
}

void mergeSort(int arr[], int si, int ei){
    if (ei>si){ //base case of recursion
        int mid = si + (ei-si)/2; // (si+ei)
        mergeSort(arr, si, mid);
        mergeSort(arr, mid+1, ei);
        merge(arr, si, mid, ei);
    }
}

int main(void){
    int n,i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    for (i = 0; i < n; i++){
        printf("Enter the element %d : ", i);
        scanf("%d", &arr[i]);
    }
    printf("\n");
    printf("Array Before Sorting: \n");
    for(i = 0; i<n; i++){
        printf("%d\t", arr[i]);
    }
    mergeSort(arr,0, n-1);
    printf("Array After Sorting: \n");
    for(i = 0; i<n;i++){
        printf("%d\t", arr[i]);
    }
    return 0;
}
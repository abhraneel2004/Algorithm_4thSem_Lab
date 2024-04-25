#include <stdio.h>
#include <stdlib.h>

int find(int* arr, int i){
    while (arr[i]>=0){
        i = arr[i];
    }
    return i;
}

void Union(int* arr, int k, int j){
    // int l = find(arr, k);
    // int m = find(arr, j);
    // if (l!=m)
    //     arr[m] = l;
    arr[j] = k;
}

int main(void){
    int arr[] ={0,1,2,3,4,5,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int arr2[n];
    for (int i = 0; i < n; i++)
        arr2[i] = -1;
    
    Union(arr2, 1,2);
    Union(arr2, 3,4);
    Union(arr2, 5,6);
    Union(arr2, 7,8);
    Union(arr2, 1,3);
    Union(arr2, 1,3);
    Union(arr2, 5,7);
    Union(arr2, 1,5);

    for (int i = 0; i < n; i++)
        printf("%3d", arr2[i]);
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%3d", i);
    return 0;
    
}
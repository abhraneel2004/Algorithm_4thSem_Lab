#include <stdio.h>
#include <stdlib.h>


void weightedUnion(int* arr, int i, int j){
    int count = arr[i]+arr[j];
    if (arr[i]>arr[j]){
        arr[i] = j;
        arr[j] = count;
    }
    else{
        arr[j] = i;
        arr[i] = count;
    }
}

int collapsingfind(int parent[], int i){
    int r = i;
    while (parent[r]>0){
        r = parent[r];
    }
    while(i!=r){
        int s = parent[i];
        parent[i] = r;
        i = s; 
    }
    return r;
}

int main(void){
    int arr[] ={0,1,2,3,4,5,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int p[n];
    for (int i = 0; i < n; i++)
        p[i] = -1;
    
    weightedUnion(p, 1,2);
    weightedUnion(p, 3,4);
    weightedUnion(p, 5,6);
    weightedUnion(p, 7,8);
    weightedUnion(p, 1,3);
    weightedUnion(p, 1,3);
    weightedUnion(p, 5,7);
    weightedUnion(p, 1,5);

    printf("Before Collapsing Find:\n");
    printf("Parent: ");
    for (int i = 1; i < n; i++)
        printf("%3d", p[i]);
    printf("\nNodes:  ");
    for (int i = 1; i < n; i++)
        printf("%3d", i);
    
    for (int i = 1; i < n; i++)
        collapsingfind(p,i);

    printf("\n\nAfter Collapsing Find:\n");
    printf("Parent: ");
    for (int i = 1; i < n; i++)
        printf("%3d", p[i]);
    printf("\nNodes:  ");
    for (int i = 1; i < n; i++)
        printf("%3d", i);

    return 0;

    
}
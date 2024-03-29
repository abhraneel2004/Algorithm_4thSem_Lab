#include<stdio.h>

void MaxHeap(int arr[], int i, int n){
	int l = 2*i+1;
	int r = 2*i+2;
	int largest=i;
	if (l<n && arr[l]>arr[i]){
		largest = l;
	}
	if (r<n && arr[r]>arr[largest]){
		largest = r;
	}
	if (largest!=i){
		int temp = arr[largest];
		arr[largest] = arr[i];
		arr[i] = temp;
		MaxHeap(arr, largest, n);
	}
}

void heapify(int arr[], int n){
	int i;
	for(i=n/2-1; i>=0; i--){
		MaxHeap(arr, i, n);
	}
}

void heapSort(int arr[], int n){
	heapify(arr, n);
	for(int i = n-1; i>0; i--){
		int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		MaxHeap(arr, 0,i);
	}
	
}

int main(void){
	int n;
	printf("Enter the elements: ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter the elements: \n");
	for(int i = 0; i<n; i++){
		printf("Enter the element %d: ",i);
		scanf("%d", &arr[i]);
	}
	
	printf("Array Before Sorting: \n");
	for(int i = 0; i<n; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
	heapSort(arr, n);
	printf("Array After Sorting: \n");
	for(int i=0; i<n; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
	return 0;
}

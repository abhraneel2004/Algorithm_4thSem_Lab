#include <stdio.h>

void maxMin(int a[], int i, int j, int *max, int *min){
	if(i==j){
		*max = a[i];
		*min = a[i];
	}
	else if (i==j-1){
		if (a[i]>a[j]){
			*max = a[i];
			*min = a[j];
		}
		else{
			*max = a[j];
			*min = a[i];
		}
	}
	
	else{
		int mid = (i+j)/2;
		maxMin(a, i, mid, max, min);
		int max1, min1;
		maxMin(a, mid+1, j, &max1, &min1);
		if (*max<max1){
			*max = max1;
		}
		if (*min>min1){
			*min = min1;
		}
	}
}


int main(void){
	int n, i, max, min;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter the elements of the array: \n");
	for(i = 0; i<n; i++){
		printf("Enter the element %d : " ,i);
		scanf("%d", &arr[i]);
	}
	
	maxMin(arr, 0, n-1, &max, &min);
	
	printf("Max = %d\n", max);
	printf("Min = %d\n", min);
	
	return 0;
}

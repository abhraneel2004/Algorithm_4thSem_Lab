#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define size 10


void minHeap(int arr[], int i, int n);
int getMin(int arr[], int n);
int extractMin(int arr[], int *n);
void decreaseKey(int arr[], int n, int i, int newVal);
int parent(int i);
void insertKey(int arr[], int *n, int key);
void deleteKey(int arr[], int *n, int i);
void showHeap(int arr[], int n);


void minHeap(int arr[], int i, int n) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int smallest = i;
    if (l < n && arr[l] < arr[i]) {
        smallest = l;
    }
    if (r < n && arr[r] < arr[smallest]) {
        smallest = r;
    }
    if (smallest != i) {
        int temp = arr[smallest];
        arr[smallest] = arr[i];
        arr[i] = temp;
        minHeap(arr, smallest, n);
    }
}


int getMin(int arr[], int n) {
    if (n <= 0) return INT_MAX;
    return arr[0];
}


int extractMin(int arr[], int *n) {
    if (*n == 0) {
        return INT_MAX;
    }
    int min_ = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    minHeap(arr, 0, *n);
    return min_;
}


void decreaseKey(int arr[], int n, int i, int newVal) {
    if (i < 0 || i >= n) {
        printf("Index out of range\n");
        return;
    }
    arr[i] = newVal;
    while (i > 0 && arr[i] < arr[parent(i)]) {
        int temp = arr[i];
        arr[i] = arr[parent(i)];
        arr[parent(i)] = temp;
        i = parent(i);
    }
}


int parent(int i) {
    return (i - 1) / 2;
}


void insertKey(int arr[], int *n, int key) {
    if (*n == size) {
        printf("Overflow\n");
        return;
    }
    int i = (*n)++;
    arr[i] = key;
    while (i > 0 && arr[i] < arr[parent(i)]) {
        int temp = arr[i];
        arr[i] = arr[parent(i)];
        arr[parent(i)] = temp;
        i = parent(i);
    }
}


void deleteKey(int arr[], int *n, int i) {
    if (i < 0 || i >= *n) {
        printf("Index invalid\n");
        return;
    }
    decreaseKey(arr, *n, i, INT_MIN);
    extractMin(arr, n);
}


void showHeap(int arr[], int n) {
    if (n == 0) {
        printf("Heap is empty\n");
        return;
    }
    printf("\n\nThe heap is: \n");
    for (int i = 0; i < n; i++) {
        printf("%4d", arr[i]);
    }
    printf("\n\n");
}


int main(void) {
    int heap[size];
    int n = 0, c, key;
    while (1) {
        printf("1. Insert Key\n2. Delete Key\n3. Show Heap\n4. Extract Min\n5. Decrease Key\n6. Exit\nEnter your Choice: ");
        scanf("%d", &c);
        if (c == 1) {
            printf("Enter the value: ");
            scanf("%d", &key);
            insertKey(heap, &n, key);
            showHeap(heap, n);
        }
        else if (c == 2) {
            printf("Enter the index i (0-%d): ", n-1);
            int i;
            scanf("%d", &i);
            deleteKey(heap, &n, i);
            showHeap(heap, n);
        }
        else if (c == 3) {
            showHeap(heap, n);
        }
        else if (c == 4) {
            printf("Minimum element: %d\n", extractMin(heap, &n));
        }
        else if (c == 5) {
            showHeap(heap, n);
            int i;
            printf("Enter the index (0-%d): ", n-1);
            scanf("%d", &i);
            printf("Enter the newvalue at index %d: ", i);
            scanf("%d", &key);
            decreaseKey(heap, n, i, key);
            showHeap(heap, n);
        }
        else if (c==6){
            printf("Exiting the program\n");
            break;
        }
        else {
            printf("Invalid Choice\n");
        }
    }

    return 0;
}

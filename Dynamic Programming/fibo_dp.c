#include<stdio.h>
#include<stdlib.h>

void fibo(int* x, int n){
    *(x+0) = 0;
    *(x+1) = 1;
    for(int i = 2; i<n; i++){
        *(x+i) = (*(x+(i-1)) + *(x+(i-2)))%1000000007;
    }
}

int main(void){
    int n;
    printf("Enter the nth term: ");
    scanf("%d",&n);
    if (n<0){
        printf("Negative number given\n");
        exit(1);
    }
    int *x = (int*)malloc(n*sizeof(int));
    fibo(x,n);
    for(int i = 0; i < n; i++){
        printf("%d\t", *(x+i));
    }
    printf("\n");
    free(x);
    return 0;
}
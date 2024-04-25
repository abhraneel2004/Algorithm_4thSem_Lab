#include<stdio.h>
#define max 10

int lookup[max][max];
int profit[] = {40,60,27};
int weight[] = {4,5,3};
void init(int n, int W){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < W; j++){
            lookup[i][j] = -1;
        }
    }
}
int max_(int a, int b){
    if (a>b) return a;
    return b;
}
int zeroOneKnap(int n, int W){
    if (lookup[n][W]==-1){
        if (n==0 || W==0){
            lookup[n][W] =0;
        }
        else if (weight[n]>W){
            lookup[n][W] = zeroOneKnap(n-1, W);
        }
        else{
            lookup[n][W] = max_(profit[n]+zeroOneKnap(n-1, W-weight[n]), zeroOneKnap(n-1, W));
        }
    }
    return lookup[n][W];
}

int main(void){
    int W;
    printf("Enter the Weight: ");
    scanf("%d",&W);
    int n = sizeof(profit)/sizeof(profit[0]);
    printf("Zero-One Knapsack Profit: %d", zeroOneKnap(n,W));

    return 0;
}
#include<stdio.h>
#include<stdbool.h>

#define n 7

struct jobs {
    int profit, deadline;
};

struct jobs arr[n];



void initialize(int pi[], int di[]) {
    for(int i = 0; i < n; i++) {
        arr[i].profit = pi[i];
        arr[i].deadline = di[i];
    }
}
int min_(struct jobs arr[]);
int min_(struct jobs arr[]) {
    int minIndex = 0;
    for(int i = 1; i < n; i++) {
        if(arr[i].deadline < arr[minIndex].deadline) {
            minIndex = i;
        }
    }
    return minIndex;
}

void jobSequence() {
    bool slot[n];
    int x[n];
    for (int i = 0; i < n; i++) {
        slot[i] = false;
        x[i] = 0;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j].profit <= arr[j + 1].profit) {
                struct jobs temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = min_(arr); j >= 0; j--) {
            if (slot[j] == false) {
                slot[j] = true;
                x[j] = i;
                break;
            }
        }
    }
    printf("\n====profits======\n");
    for (int i = 0; i < n; i++)
        printf("%5d", arr[i].profit);
    printf("\n====deadline======\n");
    for (int i = 0; i < n; i++)
        printf("%5d", arr[i].deadline);
    printf("\n====Slot======\n");
    for (int i = 0; i < n; i++)
        printf("%5d", slot[i]);
    printf("\n====x[i]======\n");
    for (int i = 0; i < n; i++)
        printf("%5d", x[i]);
}

int main(void) {
    int pi[] = {200, 100, 500, 600, 300, 800, 400};
    int di[] = {4, 3, 2, 1, 3, 1, 2};  
    initialize(pi, di);
    jobSequence();
    return 0;
}

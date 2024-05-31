#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

int graph[MAX][MAX];
int V, m;
int *x;

bool readGraph() {
    int i, j;
    FILE *fp = fopen(".././graphs/graph_unweighted.txt", "r");
    if (!fp) {
        printf("Error opening file\n");
        return false;
    }
    fscanf(fp, "%d", &V);
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            fscanf(fp, "%d", &graph[i][j]);
        }
    }
    fclose(fp);
    return true;
}

void showGraph() {
    int i, j;
    printf("\n------- Graph --------\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }
    printf("----------------------\n");
}

void printArray() {
    for (int i = 0; i < V; i++) {
        printf("%3d ", x[i]);
    }
    printf("\n");
}

void nextValue(int k) {
    int j;
    do {
        x[k] = (x[k] + 1) % (m + 1);
        if (x[k] == 0)
            return;
        for (j = 0; j < V; j++) {
            if (graph[k][j] != 0 && x[k] == x[j]) {
                break;
            }
        }
        if (j == V)
            return;
    } while (1);
}

void mcoloring(int k) {
    do {
        nextValue(k);
        if (x[k] == 0)
            return;
        if (k == V - 1)
            printArray();
        else
            mcoloring(k + 1);
    } while (1);
}

int main(void) {
    if (readGraph()) {
        showGraph();
        printf("Enter the number of colors: ");
        scanf("%d", &m);
        if (m < V) {
            printf("Graph coloring not possible\n");
            exit(1);
        }
        x = (int *)malloc(V * sizeof(int));
        if (!x) {
            printf("Memory allocation failure\n");
            exit(1);
        }
        for (int i = 0; i < V; i++) {
            x[i] = 0;
        }
        mcoloring(0);
        free(x);
    } else {
        printf("Graph reading failed\n");
    }
    return 0;
}

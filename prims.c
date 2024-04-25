#include<stdio.h>
#include<stdlib.h>

#define max 100
#define inf 999

int graph[max][max];
int V;

void display(int x[]) {
    for(int i = 0; i < V; i++)
        printf("%8d", x[i]);
    printf("\n");
}

int minKey(int key[], int mstSet[]) {
    int min = inf, min_idx = -1;
    for(int v = 0; v < V; v++) {
        if(mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_idx = v;
        }
    }
    return min_idx;
}

void printMST(int parent[], int key[]) {
    printf("Edge \tWeight\n");
    for(int i = 1; i < V; i++) {
        printf("%c - %c \t%d \n", parent[i] + 'A', i + 'A', key[i]);
    }
}

void primMST() {
    int parent[V];
    int key[V];
    int mstSet[V];

    for(int i = 0; i < V; i++) {
        key[i] = inf;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for(int c = 0; c < V-1; c++) {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;
        for(int v = 0; v < V; v++) {
            if (graph[u][v] != 0 && graph[u][v] != inf && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    
    printMST(parent, key);
}

int main(void) {
    FILE *fp;
    fp = fopen("aw.txt", "r");
    if(fp == NULL) {
        printf("File open failed\n");
        return -1;
    }

    fscanf(fp, "%d", &V);
    for(int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            fscanf(fp, "%d", &graph[i][j]);
        }
    }

    fclose(fp);

    primMST();
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define INF 999

int graph[MAX][MAX];
int V, c = 0;

typedef struct {
    int u, v, cost;
} Edge;

Edge* E;

void display(int x[]) {
    for (int i = 0; i < V; i++)
        printf("%8d", x[i]);
    printf("\n");
}

void printGraph() {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%8d", graph[i][j]);
        }
        printf("\n");
    }
}

int readGraph() {
    FILE * fp = fopen(".././graphs/aw.txt", "r"); // Correct the file path as needed
    if (fp == NULL) {
        printf("File Opening Failed\n");
        return 0;
    }

    fscanf(fp, "%d", &V);
    printf("V = %d\n", V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            fscanf(fp, "%d", &graph[i][j]);
        }
    }
    fclose(fp);
    return 1;
}

void makeEdge() {
    c = 0; // Reset edge count
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < i; j++) {
            if (graph[i][j] != 0 && graph[i][j] != INF)
                c++;
        }
    }

    E = (Edge *)malloc(c * sizeof(Edge));

    int x = 0;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < i; j++) {
            if (graph[i][j] != 0 && graph[i][j] != INF) {
                E[x].u = i;
                E[x].v = j;
                E[x].cost = graph[i][j];
                x++;
            }
        }
    }
}

int printEdges(Edge* temp, int range) {
    
    int cost = 0;
    printf("\nu\t| v\t| Cost\n-------------------------\n");
    for (int i = 0; i < range; i++) {
        printf("%c\t| %c\t| %d\n", temp[i].u + 'A', temp[i].v + 'A', temp[i].cost);
        cost+= temp[i].cost;
    }
    return cost;
}

// void printRes(Edge *temp) {
//     printf("\nu\t| v\t| Cost\n-------------------------\n");
//     for (int i = 0; i < V - 1; i++) {
//         printf("%c\t| %c\t| %d\n", temp[i].u + 'A', temp[i].v + 'A', temp[i].cost);
//     }
// }

void merge(int si, int mid, int ei) {
    Edge *temp = (Edge *)malloc((ei - si + 1) * sizeof(Edge));
    int x = 0, idx1 = si, idx2 = mid + 1;
    while (idx1 <= mid && idx2 <= ei) {
        if (E[idx1].cost < E[idx2].cost) {
            temp[x++] = E[idx1++];
        } else {
            temp[x++] = E[idx2++];
        }
    }
    while (idx1 <= mid) {
        temp[x++] = E[idx1++];
    }
    while (idx2 <= ei) {
        temp[x++] = E[idx2++];
    }
    for (int i = 0; i <= ei - si; i++) {
        E[si + i] = temp[i];
    }
    free(temp);
}

void sort(int si, int ei) {
    if (si < ei) {
        int mid = (si + ei) / 2;
        sort(si, mid);
        sort(mid + 1, ei);
        merge(si, mid, ei);
    }
}

int Find(int parent[], int i) {
    while(parent[i]>0){
        i=parent[i];
    }
    return i;
}


void Union(int parent[], int i, int j){
    parent[i] = j;
}

void Kruskals() {
    makeEdge();
    printEdges(E, c);
    sort(0, c - 1);
    printEdges(E, c);

    int parent[V];
    for (int i = 0; i < V; i++) {
        parent[i] = -1;
    }

    Edge *res = (Edge *)malloc((V - 1) * sizeof(Edge));
    if (!res) {
        printf("Memory allocation failure\n");
        exit(1);
    }

    int y = 0;
    
    for (int i = 0; i < c; i++) {
        int u = Find(parent, E[i].u);
        int v = Find(parent, E[i].v);
        if (u != v) {
            res[y++] = E[i];
            Union(parent, u, v);
        }
    }

    printf("y = %d\n", y);
    int mincost = printEdges(res, y-1);
    printf("Minimum Cost: %d\n", mincost);
    free(res); 
}

int main(void) {
    if (readGraph()) {
        printGraph();
        Kruskals();
        free(E); 
    } else {
        printf("Graph could not be read.\nExiting the program\n");
    }
    return 0;
}

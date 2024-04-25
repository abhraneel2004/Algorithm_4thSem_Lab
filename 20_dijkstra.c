#include<stdio.h>
#include<stdlib.h>
#define max 100
#define inf 999

int graph[max][max];
int V;

void display(int x[]){
    int i;
    for(i = 0; i<V; i++)
        printf("%8d", x[i]);
    printf("\n");
}

int minKey(int key[], int mstSet[]){
    int min = inf, min_idx = -1;
    for(int v = 0; v<V; v++){
        if(mstSet[v]==0 && key[v]<min){
            min = key[v];
            min_idx = v;
        }
    }
    return min_idx;
}

void printDijkstra(int parent[V], int key[V]){
    printf("Edge  \t Weight\n");
    for(int i = 0; i < V; i++){
        printf("%c\t-\t%c\t:\t%d\n", parent[i]+'A', i+'A', key[i]);
    }
}

void path(int arr[], int source, int des){
    if (source== des){
        printf("%c\t", source+'A');
        return;
    }
    printf("%c\t", des+'A');
    des = arr[des];
    path(arr, source, des);
}

void dijkstra(int source){
    int parent[V];
    int key[V];
    int mstSet[V];
    int cost;

    for(int i = 0; i < V; i++){
        key[i] = inf;
        mstSet[i] = 0;
        parent[i] = -1;
    }

    key[source] = 0;

    for(int c = 0; c<V; c++){
        int u = minKey(key, mstSet);
        mstSet[u] = 1;
        for(int v=0; v<V; v++){
            if (graph[u][v]!=0 && graph[u][v]!=inf){ // there is an edge between u and v
                if(graph[u][v]<key[v]){ 
                    parent[v] = u;
                    key[v] = graph[u][v];
                }
            }
        }

    }

    
    printf("Cost |    Path(Edge<- Parent)\n---------------------\n");
    for(int i = 0; i<V; i++){
        printf("%4d | ", key[i]);
        path(parent, source, i);
        printf("\n");
    }
    // printf("\nMinimum Cost is: %d\n", cost);
}


void printGraph(){
    for(int i = 0; i<V; i++){
        for(int j = 0; j<V; j++){
            printf("%8d", graph[i][j]);
        }
        printf("\n");
    }
}

int main(void){
    FILE *fp;
    fp = fopen("graph2.txt", "r");
    if(fp==NULL){
        printf("File open failed\n");
        return -1;
    }

    fscanf(fp, "%d", &V);
    // printf("V = %d\n", V);
    for(int i = 0; i < V; i++){
        for (int j = 0; j<V; j++){
            fscanf(fp, "%d", &graph[i][j]);
        }
    }

    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            printf("%8d", graph[i][j]);
        }
        printf("\n");
    }
    int s;
    printf("Enter the source:   ");
    scanf("%d", &s);
    dijkstra(s);
    return 0;
}
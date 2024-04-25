#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
#define max 10
#define inf 999

int graph[max][max];
int V;

void display(int x[]){
    int i;
    for(i = 0; i<V; i++)
        printf("%8d", x[i]);
    printf("\n");
}

void printGraph(){
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            printf("%8d", graph[i][j]);
        }
        printf("\n");
    }
}

int readGraph(){
    FILE * fp;
    fp = fopen("graphs/matrix.txt", "r");
    if (fp==NULL){
        printf("File Opening Failed\n");
        return 0;
    }

    fscanf(fp,"%d",&V);
    printf("V = %d\n", V);
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            fscanf(fp,"%d", &graph[i][j]);
        }
    }

    return 1;
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

void relax(int u, int v, int w, int d[], int parent[]){
    if(w!=0 && d[v]>d[u]+w){
		d[v]=d[u]+w;
        parent[v] = u;
	}
}

bool bellMan(int source){
    int d[V];
    int parent[V];
    for(int i = 0; i < V; i++){
        d[i] = inf;
        parent[i] = -1;
    }
    d[source] = 0;

    for(int i = 0; i<V; i++){
        for (int u = 0; u <V; u++){
            for(int v = 0; v < V; v++){
                relax(u,v, graph[u][v], d, parent);
            }
        }

    }
    for (int u = 0; u <V; u++){
        for(int v = 0; v < V; v++){
            if (graph[u][v]!=0 && d[u]+ graph[u][v] < d[v]){
                return false;
            }
        }
    }



    printf("Cost |    Path(Edge<- Parent)\n---------------------\n");
    for(int i = 0; i<V; i++){
        printf("%4d | ", d[i]);
        path(parent, source, i);
        printf("\n");
    }

    return true;
}

int main(void){
    int source;

    readGraph();
    printGraph();
    while(true){
        printf("\n\nEnter the source vertex (0-%d): ", V-1);
        scanf("%d", &source);
        if (source<V && source>=0){
            if (bellMan(source))
                printf("Bellman Ford Succesful.\n");
            else{
                printf("Bellman Ford Unsucessful.\n");
            }
        }
        else{
            printf("Wrong Edge entered\nExiting the program\n");
            return -1;
        }
        
    }
    
    return 0;
}
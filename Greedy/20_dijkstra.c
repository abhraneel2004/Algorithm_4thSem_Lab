#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#define MAX 10
#define inf 999

int graph[MAX][MAX];
int V;

bool readGraph(){
	FILE * fp;
	fp = fopen(".././graphs/graph_weighted.txt", "r");
	if(!fp){
		printf("File Reading Failed\n");
		return false;
	}
	fscanf(fp, "%d", &V);
	for(int i = 0; i<V; i++){
		for(int j = 0; j<V; j++){
			fscanf(fp, "%d", &graph[i][j]);
		}
	}
	return true;
}

void showGraph(){
    printf("\n------- Graph -------\n");
	for(int i = 0; i<V; i++){
		for(int j = 0; j<V; j++){
			printf("%d\t", graph[i][j]);
		}
		printf("\n");
	}
    printf("-----------------------\n");
}

int minKey(int key[], int visited[]){
	int min_=inf, min_idx = -1;
	for (int i = 0; i<V; i++){
		if (visited[i]==0 && key[i]<min_){
			min_ = key[i];
			min_idx = i;
		}
	}
	return min_idx;
}

void path(int parent[], int source, int destination){
    if (source==destination){
        printf("%c", source+'A');
        return;
    }
    printf("%c<-", destination+'A');
    path(parent, source, parent[destination]);
}

void Dijkstra(int source){
	int key[V];
	int parent[V];
	int visited[V];
	for(int i = 0; i<V; i++){
		key[i] = inf;
		parent[i] = -1;
		visited[i] = 0;
	}
	key[source] = 0;

	for (int i = 0; i<V-1; i++){
		int u = minKey(key, visited);
		visited[u] = 1;
		for(int v = 0; v<V; v++){
			if(graph[u][v]!=0 && visited[v]==0 && key[u]+graph[u][v]<key[v]){
				parent[v] = u;
				key[v] = key[u]+graph[u][v];
			}
		}
	}
	

    printf("\n=======================\n");
    printf("Cost\t|     Path     ");
    printf("\n-----------------------\n");
    for (int i = 0; i<V; i++){
        printf("%d\t| ", key[i]);
        path(parent, source, i);
        printf("\n");
    }
    printf("-----------------------\n");

}

int main(void){
	bool b = readGraph();
	if(!b){
		printf("Graph Read Failed\n");
		exit(1);
	}
	else{
		showGraph();
        int s;
        printf("Enter the source (0-%d): ", V-1);
        scanf("%d",&s);
        if (s>=0 && s<V)
		    Dijkstra(s);
        else
            printf("Invalid source given\n");
	}
	return 0;
}
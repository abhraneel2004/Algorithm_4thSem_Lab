#include <stdio.h>
#include <limits.h>

#define INF INT_MAX
#define V 4  // Number of vertices in the graph

int graph[V][V];

int readGraph(){
	FILE *fp;
	fp = fopen("graphs/aw.txt", "r");
	
	if (fp==NULL){
		printf("\nfile open failed.\n");
		return -1;
	}
	int n;
	fscanf(fp,"%d",&n);
	// printf("n=%d\n",n);
	
	for(int i = 0; i<n;i++){
		for (int j = 0; j<n; j++){
			fscanf(fp,"%d", &graph[i][j]);
		}
	}
	fclose(fp);
	return n;
}

// Function to print the distance matrix
void printSolution(int dist[][V]) {
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}

// Implementation of the Floyd-Warshall algorithm
void floydWarshall(int graph[][V]) {
    int dist[V][V];  // Output matrix that will have the shortest distances between every pair of vertices

    // Initialize the distance matrix with the given graph
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Apply the Floyd-Warshall algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distances
    printSolution(dist);
}

int main() {
    int c;
    c = readGraph();
    if (c == 1){
        // Apply the Floyd-Warshall algorithm on the graph
        floydWarshall(graph);
    }
    

    return 0;
}

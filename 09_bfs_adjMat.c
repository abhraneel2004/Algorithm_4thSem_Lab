#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int graph[10][10];

int visited[10] = {0};

int queue[10];
int front = -1;
int rear = -1;

bool isEmpty(){
	return front ==rear;
}

bool isFull(){
	return rear == 10;
}

void enqueue(int data){
	queue[++rear] = data;
}

int dequeue(){
	int x = queue[++front];
	return x;
}

void BFS(int v, int n){
	visited[v]= 1;
	enqueue(v);
	while(!isEmpty()){
		int x = dequeue();
		printf("%c\t", 65+x);
		for(int i = 0; i<n; i++){
			if (graph[x][i]==1 && visited[i]==0){
				enqueue(i);
				visited[i] = 1;
			}
		}
	}
}

int readGraph(){
	FILE *fp;
	fp = fopen("abc.txt", "r");
	
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

void showGraph(int n){
	for(int i = 0; i<n;i++){
		printf("%c: ",65+i);
		for (int j = 0; j<n; j++){
			if(graph[i][j]==1) printf(" %c,", 65+j);
			//printf("%3d", graph[i][j]);
		}
		printf("\n");
	}
}

int main(void){
	int n = readGraph();
	if (n==-1){
		printf("Failed to read Graph\nExiting the program\n");
		return 1;
	}
	showGraph(n);
	int v;
	printf("n = %d\n", n);
	printf("Enter the source point (0 to %d): ", n-1);
	scanf("%d", &v);
	if(v>=0 && v<n){
		BFS(v,n);
		printf("\n");
	}
	else{
		printf("Wrong source entered\n");
	}
	return 0;
}

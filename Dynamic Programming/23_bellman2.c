#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
#define inf 999
int V;


void printSolution(int d[]){
	int i;
	printf("\n Vertex             Distance from Source\n");
	for(i=0;i<V;i++){
		printf("%d\t\t  %d\n",i,d[i]);
	}
}
void relax(int u,int v,int w, int d[]){
    // printf("\n~~~~~~~~\nu = %d\nv = %d\nd[u] =%d\nd[v]= %d\nw= %d\n",u,v,d[u], d[v],w);
	if(w!=0 && d[v]>d[u]+w){
		d[v]=d[u]+w;
        // printf("\nnew d[v] = %d\n", d[v]);
        // printf("\n");
        // printSolution(d);
        // printf("\n");
	}
}
void initializeSingleSource(int G[][V],int s, int d[]){
	int i;	
	for(i=0;i<V;i++){
		d[i]=inf;
	}
	d[s]=0;
}
bool bellmanFord(int G[][V],int s){
	int i,u,v;
    int d[V];
	initializeSingleSource(G,s,d);
    // printf("Initial: \n");
    // printSolution(d);
    // printf("\n");
	for(i=1;i<=V-1;i++){
		for(u=0;u<V;u++){
			for(v=0;v<V;v++){
                // printf("\nw = %d", G[u][v]);
				relax(u,v,G[u][v], d);
			}
		}
        // printf("\n(i = %d )----------\n",i);
        // printSolution(d);
        // printf("\n");
	}
	for(u=0;u<V;u++){
        for(v=0;v<V;v++){
            if(G[u][v]!=0 && d[v]>d[u]+G[u][v]){
                return false;
            }
		}
	}
	printSolution(d);
	return true;
}
int main(void){
	FILE *file=fopen(".././graphs/matrix.txt","r");  
	int i,j,s;
	
	if(file==NULL){
		printf("Error in opening file !!!");
		exit(0);
	}
	// Read the dimensions of the matrix
    fscanf(file, "%d", &V);
    
   // printf("V=%d\n",V);
    
	int G[V][V];
	
	for(i=0;i<V;i++){
		for(j=0;j<V;j++){
			if(fscanf(file,"%d",&G[i][j])!=1){
				return 1;
			}
		}
	}
	for(i=0;i<V;i++){
		for(j=0;j<V;j++){
			printf("%d\t",G[i][j]);
		}
	printf("\n");
	}
	printf("Enter the source vertex (0-%d): ", V-1);
	scanf("%d",&s);
	bellmanFord(G,s);		
	return 0;
}
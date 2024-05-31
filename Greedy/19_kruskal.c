#include <stdio.h>
#include <stdlib.h>
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
    fp = fopen(".././graphs/aw.txt", "r");
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

int main(void){
    int t= readGraph();
    if (t==1){
        printGraph();
    }
    else{
        printf("Graph could not be read.\nExiting the program\n");
    }
    return 0;

}
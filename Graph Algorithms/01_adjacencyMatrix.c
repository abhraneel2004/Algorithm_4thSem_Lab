#include<stdio.h>
#include<stdlib.h>


int main(void){
    FILE *fp;
    fp = fopen(".././graphs/abc.txt", "r");
    if(fp==NULL){
        printf("Error in Opening File\n");
        exit(1);
    }

    else{
        int n,i,j;
        fscanf(fp, "%d", &n);

        // creating adjacency matrix for graph
        int graph[10][10];

        // Reading adjacency matrix from file
        for (i = 0; i<n; i++){
            for(j = 0; j<n; j++){
                fscanf(fp, "%d", &graph[i][j]);
            }
        }

        int count = 0;
        printf("Adjacency Matrix: \n");
        // Displaying adjacency matrix
        for (i = 0; i<n; i++){
            for(j = 0; j<n; j++){
                if (graph[i][j]==1) count++;
                printf("%3d", graph[i][j]);
            }
            printf("\n");
        }

        printf("Total Edges: %d\n", count/2);
        printf("Total Degree: %d\n", count);


    }
    return 0;
}
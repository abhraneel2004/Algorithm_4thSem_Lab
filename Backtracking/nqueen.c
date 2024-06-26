#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<stdlib.h>

int *x;

bool place(int k,int i){ 
	// Return true  if a queen can be palced in kth row ith column 
	//  Otherwise return false
	int j;
	for(j=0;j<k;j++){      
          if(x[j]==i||abs(x[j]-i)==abs(j-k)){
           // Two in same column or in same diagonal
            return false;
    	}
      }
      return true;	
}

void printl(int n){
	printf("\n");
	for(int i = 0; i<4*n; i++){
		printf("_");
	}
	printf("\n");
}

void  Nqueens(int k,int n){   
	int i,j,p;
	
	for(i=0;i<n;i++){   
        if(place(k,i)){  
            x[k]=i;   
			if(k==n-1){
				printl(n);
				
				for(j = 0; j < n; j++){
					
					printf(" %d |",x[j]+1);
				}
				printl(n);

               	for(j=0;j<n;j++){
					
					for(p=0;p<n;p++){
						if(x[j]==p)
							printf(" Q ");
						else
							printf("   ");
						printf("|");
					}
					printl(n);
               		
			   } 
			   printf("\n\n");
			}else{
		   		Nqueens(k+1,n);       
            }
        } 
	}
}
int main(void){
	int n;
	printf("Enter no of Queen:");
	scanf("%d",&n);
	x=(int *)malloc(n*sizeof(int));
	Nqueens(0,n);
	free(x);
	return 0;
}
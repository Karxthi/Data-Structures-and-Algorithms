#include<stdio.h>
#include<conio.h>
#include <limits.h>
//#define INFINITY 9999
#define MAX 15 // a macro because function defenitions with 2x2 matrices needs be initialized with 2 macros first

void dijkstra(int A[MAX][MAX],int n,int src);


// _______________MAIN FUNCTION_______________________
void dijkstra(int A[MAX][MAX],int n,int src)
{

	int cost[MAX][MAX],distance[MAX],pred[MAX];
	int visited[MAX],count,mindistance,nextnode,i,j;
	
	//pred[] stores the predecessor of each node
	//count:number of nodes seen so far
	//_______cost matrix_________________
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(A[i][j]==0){
				cost[i][j]=INT_MAX;
                }// set 0 as infinity
			else{
                cost[i][j] = A[i][j];
                
            } 
				//cost[i][j]=A[i][j];}
                // retain other values
        }
    }
	
	
    
    //important part, 
	for(i=0;i<n;i++)
	{
		distance[i]=cost[src][i]; 
        // printf("distance");//distance : [.........]
		// printf("\t\t\t%d", distance[i]);
        pred[i]=src;
		visited[i]=0;
	}
	
	distance[src]=0;// a:0
	visited[src]=1;// a 1
	count=1;// 1 node visited
	
	while(count<n-1)
	{
		mindistance=INT_MAX;
		
		//nextnode gives the node at minimum distance
		for(i=0;i<n;i++)
			if(distance[i]<mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}
			
			//check if a better path exists through nextnode			
			visited[nextnode]=1;
			for(i=0;i<n;i++)
				if(!visited[i])
					if(mindistance+cost[nextnode][i]<distance[i])
					{
						distance[i]=mindistance+cost[nextnode][i];
						pred[i]=nextnode;
					}
		count++;
    }
        
	

	//pdispl
	for(i=0;i<n;i++)
		if(i!=src)
		{
			printf("\nDistance of node%d=%d",i,distance[i]);
			printf("\nPath=%d",i);
			
			j=i;
			do
			{
				j=pred[j];
				printf("<-%d",j);
			}while(j!=src);
	}
}

int main()
{
	int A[MAX][MAX],i,j,n,source;// A is an adjacency matrix
	printf("Enter no. of vertices:");
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix:\n");
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&A[i][j]);
        }
    }
             //get the adjacency matrix variables

    // for(i=0;i<n;i++){
	// 	for(j=0;j<n;j++){
	// 		printf("%d",A[i][j]);
    //     }
    //     printf("\n");
    // }
	
	printf("\nEnter the starting node:");
	scanf("%d",&source); //get the starting node);
	dijkstra(A,n,source);
	
	return 0;
}

#include<stdio.h>
#include<limits.h>
#define MAX 10
void djkistra(int A[MAX][MAX],int n,int src){
    int cost[MAX][MAX],distance[MAX],pred[MAX],visited[MAX],count,nextnode,mindistances;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(A[i][j]==0){
                cost[i][j]=INT_MAX;
            }
            else{
                cost[i][j]=A[i][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        distance[i]=cost[src][i];
        visited[i]=0;
        pred[i]=src;
    }
    distance[src]=0;
    visited[src]=1;
    count=1;
    while(count<n-1){
        mindistances=INT_MAX;
        for(int i=0;i<n;i++){
            if(distance[i]<mindistances&&!visited[i]){
                mindistances=distance[i];
                nextnode=i;
            }
            visited[nextnode]=1;
            for(int i=0;i<n;i++){
                if(mindistances+cost[nextnode][i]>distance[i]){
                    distance[i]=mindistances+cost[nextnode][i];
                    pred[i]=nextnode;
                }
            }
        }
            //printf
            for(int i=0;i<n;i++){
                if(i!=src){
                    int j;
                    printf("Distnce for %d is %d",i,distance[i]);
                    printf("path : %d",i);
                    do{
                        j=pred[j];
                        printf("%d",j);


                    }while(j!=src);
                }
            }
            
       count++ ;
    }


}

int main()
{
	int i,j,n,u;
	printf("Enter no. of vertices:");
	scanf("%d",&n);
        int A[MAX][MAX] = {{0, 0, 3, 0, 0},    
                                {0, 0, 10, 4, 0},    
                                {3, 10, 0, 2, 6},    
                                {0, 4, 2, 0, 1},    
                                {0, 0, 6, 1, 0},    
                                };   
	// printf("\nEnter the adjacency matrix:\n");
	
	// for(i=0;i<n;i++)
	// 	for(j=0;j<n;j++)
	// 		scanf("%d",&A[i][j]);
	
	printf("\nEnter the starting node:");
	scanf("%d",&u);
	djkistra(A,n,u);
	
	return 0;
}
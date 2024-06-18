#include<stdio.h>
#include<limits.h>
#define MAX 10
void djikstra(int A[MAX][MAX],int n,int src){
    int cost[MAX][MAX],distance[MAX],pred[MAX],visited[MAX],mindistance,count,nextnode;
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
    visited[src]=1;
    distance[src]=0;//a-a is 0
    count=1;
    while(count<n-1){
        mindistance=INT_MAX;
        for(int i=0;i<n;i++){
            if(distance[i]<mindistance && !visited[i]){
                mindistance=distance[i];
                nextnode=i;
            }
        
        
        
            visited[nextnode]=1;
            for(int i=0;i<n;i++){
                if(mindistance+cost[nextnode][i]<distance[i] && !visited[i]){
                    distance[i]=mindistance+cost[nextnode][i];
                    pred[i]=nextnode;
                }
            }
        }
    }
        
        count++;
    }
for(int i=0;i<n;i++){
    printf("\nDistance of %d:%d",i,distance[i]);

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
	djikstra(A,n,u);
	
	return 0;
}
    

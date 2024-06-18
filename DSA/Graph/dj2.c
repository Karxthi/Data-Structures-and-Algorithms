#include<stdio.h>
#include<conio.h>
#define INFINITY 9999
#define MAX 10

void dijkstra(int G[MAX][MAX],int n,int startnode);

int main()
{
	int G[MAX][MAX],i,j,n,u;
	printf("Enter no. of vertices:");
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix:\n");
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&G[i][j]);
	
	printf("\nEnter the starting node:");
	scanf("%d",&u);
	dijkstra(G,n,u);
	
	return 0;
}

void dijkstra(int G[MAX][MAX],int n,int startnode)
{

	int cost[MAX][MAX],distance[MAX],pred[MAX];
	int visited[MAX],count,mindistance,nextnode,i,j;
	
	//pred[] stores the predecessor of each node
	//count gives the number of nodes seen so far
	//create the cost matrix
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(G[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=G[i][j];
	
	//initialize pred[],distance[] and visited[]
	for(i=0;i<n;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
		// Each iteration is setting the distance of node i from the start node to the cost (weight) of the edge between the start node and node i.
		// The predecessor of node i is the start node.
		// The visited array is used to keep track of the nodes that have been visited. 
		// This is stored in the distance array.
	}
	
	distance[startnode]=0;//because the distance of the start node from itself is 0
	visited[startnode]=1;// starnode is visited
	count=1;//1 node visited 
	
	while(count<n-1)
	{
		mindistance=INFINITY;
		
		//NOW WE FIND NEXT SMALLEST NODE FROM DISTANCE ARRAY
		for(i=0;i<n;i++)
			if(distance[i]<mindistance&&!visited[i])
			{
				mindistance=distance[i];// store its distance
				nextnode=i//set it as nextnode
			}
			
						
			visited[nextnode]=1;//MARK IT AS VISITED
			for(i=0;i<n;i++)//NOW FROM THIS NEWNODE FIND ALL NEW COMBINATIONS TILL ALL OTHER NODES 
				if(!visited[i])
					if(mindistance+cost[nextnode][i]<distance[i])//IF THIS NEW DISTANCE(mindist+distance from new node to 'i'th node is less than distance[i]) 
					{
						distance[i]=mindistance+cost[nextnode][i];//SET IT AS  DISTANCE
						pred[i]=nextnode;//SET PREDECESSOR OF 'i'th NODE AS NEWNODE
					}
		count++;
	}

	//print the path and distance of each node
	for(i=0;i<n;i++)
		if(i!=startnode)
		{
			printf("\nDistance of node%d=%d",i,distance[i]);
			printf("\nPath=%d",i);
			
			j=i;
			do
			{
				j=pred[j];
				printf("<-%d",j);
			}while(j!=startnode);
	}
}
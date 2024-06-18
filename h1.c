#include<stdio.h>
#include <stdlib.h>
int main()
{
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    int *arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=(int*)malloc(m*sizeof(int));
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("\n");
            scanf("%d",(arr+i+j));
            printf("       %d",*(arr+i+j));
            
        }
    }
    printf("\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d ",*(arr+i*(n*m)+j)); 
        }
    }
}
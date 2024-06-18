#include <stdio.h>
#include <stdlib.h>
int count = 0;
int countt(int **arr,int a);
int main()
{
    int i,j,n,m;
    
    scanf("%d",&n);
    scanf("%d",&m);
    //int arr[n];
    int **ptr=(int**)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        ptr[i]=(int*)malloc(m*sizeof(int));
    }
    //entering
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",(ptr+i*m+j));
        }
    }
    //displaying
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<m;j++)
        {
            printf("%d ",*(ptr+i*(n)+j));
        }
    }
    //checking
    countt(ptr,n*m);
    printf("\n");
    printf("Total count: %d",count);
   


}
int countt(int **arr,int a)
{
    for(int i=0;i<a;i++)
    {
        if(**(arr+i)%2==0)
        {
            count++;
        }
    }
}
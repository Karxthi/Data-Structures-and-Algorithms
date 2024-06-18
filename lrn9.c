#include <stdio.h>
#include <stdlib.h>
int countt(int *arr,int a,int b);
int find(int *arr,int a,int b,int e);
int count=0;
int main()
{
    int i,j,m,n,ele;
    scanf("%d",&m);
    scanf("%d",&n);
    int *ptr=(int *)malloc(n*m*sizeof(int));
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",(ptr+i*m+j));

        }

    }
    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<m;j++)
        {
            printf("%d ",*(ptr+i*m+j));

        }

    }
    printf("\n");
    countt(ptr,m,n);
    printf("Total Count %d",count);
    printf("\nEnter elemnt");
    scanf("%d",&ele);
    find(ptr,n,m,ele);

}
int countt(int *arr,int a,int b)
{
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            if(*(arr+i*b+j)%2==0)
            {
                count++;
            }
        }
    }
}
int find(int *arr,int a,int b,int e)
{
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            if(*(arr+i*b+j)==e)
            {
                printf("Found at %d.%d",i+1,j+1);
            }
        }
    }
}
#include <stdio.h>
#include <stdlib.h>
int countt(int *arr,int n);
int count=0;
int main()
{
    int i,j,n,m,c;
    scanf("%d",&n);
    scanf("%d",&m);
    int *ptr=(int*)malloc(n*m*sizeof(int));
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&c);
            *((ptr+i)+j)=c;
        }
    }
    //displaying
    for(int i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<m;j++)
        {
            printf("%d ",*((ptr+i+j)));
        }
    }
    countt(ptr,n*m);
    printf("\n");
    printf("Total Count is %d",count);
}
int countt(int *arr,int a)
{
    for(int i=0;i<a;i++)

    {
        if(*(arr+i)%2==0)
        {
            count++;
        }
    }
}
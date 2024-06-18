#include <stdio.h>
#include <stdlib.h>
int order(int *arr,int a,int b);
int main()
{
    int i,j,n,m;
    scanf("%d",&m);
    scanf("%d",&n);
    int *ptr = (int*)malloc(n*m*sizeof(int));
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
    order(ptr,m,n);
}
int order(int *arr,int a,int b)
{
    int temp;
    for(int i=0;i<a*b;i++)
    {
        for(int j=i+1;j<a*b;j++)
        {
            if(*(arr+j)>*(arr+i))
            {
                temp=*(arr+j);
                *(arr+j)=*(arr+i);
                *(arr+i)=temp;
            }
        }
    }
    printf("\n");
    for(int i=0;i<a;i++)
    {
        printf("\n");
        for(int j=0;j<b;j++)
        {
            printf("%d",*(arr+i*b+j));
        }
    }

}
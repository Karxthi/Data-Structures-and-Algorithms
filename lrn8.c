#include <stdio.h>
#include <stdlib.h>
int countt(int **arr,int a,int b);
int count=0;
int find(int **arr,int a,int b,int e);
int main()
{
    int i,j,n,m,ele;
    scanf("%d",&n);
    scanf("%d",&m);
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
    //display
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<m;j++)
        {
            printf("%d ",*(ptr+i*m+j));
        }
    }
    printf("\n");
    //countt(ptr,n,m);
    printf("Enter element \n");
    scanf("%d",&ele);
    find(ptr,n,m,ele);
    printf("\n");
    printf("Count is %d\n",count);

}
/*int countt(int **arr,int a,int b)
{
    for(int i=0;i<a;i++)
    {
        printf("Keri");
        for(int j=0;j<b;j++)
        {
            printf("Keri2");
            printf("%d",*(arr+i*b+j+1));

            if(*(arr+i*b+j)%2==0)
            {
                printf("Keri3");
                count++;
            }
        }
    }
}*/
int find(int **arr,int a,int b,int e)
{
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            if(**(arr+i*b+j)==e)
            {
                printf("Found at %d,%d ",i+1,j+1);
            }
        }
    }
}
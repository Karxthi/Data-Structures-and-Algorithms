#include <stdio.h>
#include <stdlib.h>
int max,minc,maxc;
int sort(int *arr,int row,int col);
int main()
{
    int i,j,n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    int *ptr;
    ptr=(int*)malloc(n*m*sizeof(int));
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("\nEnter element row %d col %d  ",i+1,j+1);
            scanf("%d",(ptr+i+j));

        }
        
    }
     sort(ptr,n,m);
     for(i=0;i<n;i++)
     {
    
        for(j=0;j<m;j++)
        {
            printf("  %d",*((ptr+i)+j));
        }
     }


}
int sort(int *arr,int row,int col)
{
    int temp;
    for(int i=0;i<row*col;i++)
    {
        for(int j=i+1;j<row*col;j++)
        {
            if(*(arr+j)>*(arr+i))
            {
                temp=*(arr+j);
                *(arr+j)=*(arr+i);
                *(arr+i)=temp;
            }
        }
    }
}
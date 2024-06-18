#include <stdio.h>
#include <stdlib.h>
int max,maxr,maxc=0;
void find(int *arr,int n,int c,int *max,int *maxr,int *maxc);
int main()
{
    int i,j,row,col;
    scanf("%d",&row);
    scanf("%d",&col);
    int *ptr;
    ptr=(int*)malloc(row*col*sizeof(int));
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("\nEnter element row %d col %d  ",i+1,j+1);
            scanf("%d",(ptr+i+j));

        }
    }
    find(ptr,row,col,&max,&maxr,&maxc);
    printf("Mximum is %d at row %d at col %d",max,maxc,maxr);
}
void find(int *arr,int n,int c,int *max,int *maxr,int *maxc)
{
    *max=*arr;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(*(arr+i+j)>*max)
            {
                *max=*(arr+i+j);
                *maxc=j+1;
                *maxr=i+1;
            }
        }
        
    }
}
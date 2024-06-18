#include <stdio.h>
#include <stdlib.h>
int findm(int *arr,int a,int b, int *max,int *maxr,int *maxc);
int max,maxr,maxc=0;
int main()
{
    int i,j,n,m,max;
    scanf("%d",&n);
    scanf("%d",&m);
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
        for(j=0;j<m;j++)
        {
            printf("%d",*(ptr+i*m+j));
        }
    }
    findm(ptr,n,m,&max,&maxr,&maxc);
    printf("Max is %d, maxr is %d, maxc is %d",max,maxr,maxc);

}
int findm(int *arr,int a,int b, int *max,int *maxr,int *maxc)
{
    *max=*arr;
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            if(*(arr+i*b+j)>*max)
            {
                *max=*(arr+i*b+j);
                *maxr=i+1;
                *maxc=j+1;
            }
        }
    }
}
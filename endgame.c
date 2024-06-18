#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i,j,temp;
    scanf("%d",&n);
    int *ptr;
    ptr=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf("%d",(ptr+i));

    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(*(ptr+j)>*(ptr+i)){
                temp=*(ptr+j);
                *(ptr+j)=*(ptr+i);
                *(ptr+i)=temp;
            }
        }
    }
    for(i=0;i<n;i++){
        printf("%d\t",*(ptr+i));
    }
}
#include<stdio.h>
#include<stdlib.h>
int max=0;
void count(int **data,int rw,int col,int maxx);
int main()
{
    int n,r,c;
    scanf("%d",&r);
    scanf("%d",&c);
    int **arr=(int **)malloc(r*sizeof(int));
    for(int i=0;i<r;i++)
    {
        arr[i]=(int *)malloc(c*sizeof(int));
        printf("done\n");
    }
    //input array
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",(arr+i+j));
            printf("Donee inuting\n\n");
        }
    }
    printf("umbi\n\n");
    count(arr,r,c,max);
//findin big
    /*for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {



        }
    }*/

    
    }
void count(int **data,int rw,int col,int maxx)
{
    printf("keri");
    int temp;
    printf("%d inna\n",*data);
    maxx=**data;
    printf("\nok");
    for(int i=0;i<rw;i++){
        for(int j=i+1;j<col;j++)
        {
            if(**(data+j)>**(data+i))
            {
                temp=**(data+j);
                maxx=**(data+j);
                **(data+j)=**(data+i);
                **(data+i)=temp;
                
                
            }
        }
    }
    for(int i=0;i<rw;i++)
    {
        for(int j=i+1;j<col;j++)
        {
            printf("\n %d\n",max);
            printf("\t %d",*(data+i+j));
        }
    }

}
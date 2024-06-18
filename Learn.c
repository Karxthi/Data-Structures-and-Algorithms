#include<stdio.h>
#include<stdlib.h>
int max,maxc,maxr=0;
void fm(int *data,int rows,int cols,int *max,int *maxc,int *maxr);
int main(){
    int i,j,rows,cols;
    scanf("%d",&rows);
    scanf("%d",&cols);
    int *ptr;
    ptr=(int*)malloc(rows*cols*sizeof(int));
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            scanf("%d",(ptr+i+j));
        }


    }
    fm(ptr,rows,cols,&max,&maxc,&maxr);
    printf("%d max\n %d maxc\n %d maxr",max,maxc,maxr);
    

}
void fm(int *data,int rows,int cols,int *max,int *maxc,int *maxr)
{
    *max=*data;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(*(data+i+j)>*max){
                *max=*(data+i+j);
                *maxr=i+1;
                *maxc=j+1;
            }
        }
    }
}
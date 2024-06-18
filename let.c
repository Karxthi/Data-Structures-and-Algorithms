#include<stdio.h>
#include<stdlib.h>
int main()
{
    int r=3,c=3;
    int **arr=(int**)malloc(r*sizeof(int));
    for(int i=0; i<3; i++){
        arr[i]=(int*)malloc(c*sizeof(int));

    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3;j++){
            scanf("%d",*(arr+i+j));
        }
    }
    for(int i=0; i<3; i++){
        printf("\n");
        for(int j=0; j<3; j++){
            printf("\t%d",*(arr+i+j));
        }
    }
}
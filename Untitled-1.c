#include<stdio.h>
int main ()
{
    int a[2][3],i,j,k;
    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++){
            printf("%d",&a[i][j]);
        }
    }
    for(i=0;i<3;i++)
    {
        printf("\n");
        for(j=0;j<2;j++){
            printf("%d\t",a[i][j]);
        }
    }
}
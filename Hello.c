#include<stdio.h>
int main ()
{
    int a,i,j,k;
    scanf("%d",&a);
    for(i=0;i<=a;i++)
    {
        printf("\n");
        for(j=a-i;j>0;j--)
        {
            printf(" ");
        }
        for(k=0;k<i;k++)
        {
            printf("*");
        
        }
    }
}
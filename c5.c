#include <stdio.h>
int main()
{
    int n,i,j;
    int a=0;
    scanf("%d",&n);
    /*for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<=i;j++)
        {
            printf("*");
        }

    }
    //bottom
    for(i=0;i<n-1;i++)
    {
        printf("\n");
        for(j=0;j<n-i-1;j++)
        {
            printf("*");
        }
    }*/

    for(int i=1;i<=n;i++)
    {
        printf("\n");
        for(j=1;j<=n-i+1;j++)
        {
            printf("%c",64+j);
         
        }
    }
}
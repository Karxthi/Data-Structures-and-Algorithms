#include <stdio.h>
int main()
{
    int n,a=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        printf("\n");
        for(int j=0;j<i;j++)
        {
            printf("%c",64+i);
           
        }

    }
    /*for(int i=0;i<n;i++)
    {
        printf("\n");
        for(int j=0;j<n-i;j++)
        {
            printf("*");
        }
    }*/
}
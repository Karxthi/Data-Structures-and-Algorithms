#include <stdio.h>
int main()
{
    int m,n;
    int i,j,a=1;
    int sumr=0;
    int sumc=0;
    scanf("%d",&m);
    scanf("%d",&n);
    int arr[m][n];
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("\n Enter element Row %d, Column %d :",i+1,j+1);
            scanf("%d",&arr[i][j]);
        }
    }
    //display
    for(i=0;i<m;i++)
    {
        printf("/n");
        for(j=0;j<n;j++)
        {
            printf("%d ",arr[i][j]);
        }
    }
    //
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            sumr+=arr[i][j];
            sumc+=arr[j][i];
        }
        printf("\n sum row of row %d= %d",i+1,sumr);
        printf("\n sum column 0f column %d = %d",a,sumc);
        sumr=0;
        sumc=0;
        a++;
    }
    // transpose9

printf("\n\n");
    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<m;j++)
        {
            printf("%d ",arr[j][i]);
        }
    }

    //
}
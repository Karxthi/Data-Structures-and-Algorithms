//array pooram
#include <stdio.h>
int main()
{
   int n,m,i,j;
   int sumr=0;
   int sumc = 0;
   printf("Enter the number of rows");
   scanf("%d",&n);
   printf("Enter the number of columns");
   scanf("%d",&m);
   int arr[n][m];
   for( i=0;i<n;i++)
   {
    for(j=0;j<m;j++)
    {
        printf("Enter Row %d column %d\n",i+1,j+1);
        scanf("%d",&arr[i][j]);
    }
   }
   //displau
    for( i=0;i<n;i++)
   {
    printf("\n");
    sumr=0;
    sumc=0;
    for( j=0;j<m;j++)
    {
        
        //printf("%d  ",arr[i][j]);
        //sum += arr[i][j];
        sumr=sumr+arr[i][j];
        sumc=sumc+arr[j][i];
    }
        
    printf("\n sum of row %d is %d , col %d is %d",i+1,sumr,j+1,sumc);
   
   }
   //printf("\n%d  ",sum);

   /*printf("\n printing transpose");
   for(int i=0;i<m;i++)
   {
    printf("\n");
    for(int j=0;j<n;j++)
    {
        printf("%d  ",arr[j][i]);
    }
   }*/
 

}

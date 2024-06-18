#include <stdio.h>
int main()
{
    int n,m,p,q,i,j,sum,k;
    int tempr,tempc;
    printf("Enter row of matrix 1: ");
    scanf("%d",&n);
    printf("Enter column of matrix 1: ");
    scanf("%d",&m);
    printf("Enter row of matrix 2: ");
    scanf("%d",&p);
    printf("Enter column of matrix 2: ");
    scanf("%d",&q);
    int a[n][m];
    int b[p][q];
    
        int c[n][q];
    //m1
    for(i=0;i<n;i++)
    {
        
        for(j=0;j<m;j++)
        {
            printf("Enter row %d and column %d: ",i+1,j+1);
            scanf("%d",&a[i][j]);
            
        }
    }
    for(int i=0;i<m;i++)
   {
    printf("\n");
    for(int j=0;j<n;j++)
    {
        printf("%d  ",a[j][i]);
    }
   }
    //m2
    printf("\n matrix 2");
    for(i=0;i<p;i++)
    {
        
        for(j=0;j<q;j++)
        {
            printf("Enter row %d and column %d: ",i+1,j+1);
            scanf("%d",&b[i][j]);
            
        }
    }
    for(i=0;i<p;i++)
   {
    printf("\n");
    for( j=0;j<q;j++)
    {
        printf("%d  ",b[i][j]);
    }
   }
   if(m==p)
   {
    for(i=0;i<n;i++)
    {
        for(j=0;j<q;j++)
        {
            sum=0;
            for(k=0;k<m;k++)
            {
                sum+=a[i][k]*b[k][j];
            }
            c[i][j]=sum;
        }
    }
    //priting
    for(i=0;i<m;i++)
   {
    printf("\n");
    for( j=0;j<q;j++)
    {
        printf("%d  ",c[i][j]);
    }
   }
   }
   else{
    printf("\n invalid");

      }
}
    
   
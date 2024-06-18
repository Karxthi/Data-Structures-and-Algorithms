#include <stdio.h>
int main()
{
    int i,j,m,n,p,q;
    int sum=0;
    printf("For first Matrix\n");
    scanf("%d",&m);
    scanf("%d",&n);
    printf("For second Matrix\n");
    scanf("%d",&p);
    scanf("%d",&q);
    int A[m][n];
    int B[p][q];
    int M[m][q];
    //M1
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("Matrix 1 Element Row %d Column %d: \n",i+1,j+1);
            scanf("%d",&A[i][j]);
        }
    }
    //M2
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        {
            printf("Matrix 2 Element Row %d Column %d: \n",i+1,j+1);
            scanf("%d",&B[i][j]);
        }
    }
    // Display each Matrix
printf("\n First Matrix");
    for(i=0;i<m;i++)
    {
        printf("\n");
        for(j=0;j<n;j++)
        {
            printf("%d ",A[i][j]);
        }
    }
printf("\nSecond Matrix");
    for(i=0;i<p;i++)
    {
        printf("\n");
        for(j=0;j<q;j++)
        {
            printf("%d ",B[i][j]);
        }
    }

    //Addition;
    int C[p][q];
    for(i=0;i<m;i++)
    {
        
        for(j=0;j<n;j++)
        {
            C[i][j]=A[i][j]+B[i][j];
        }
    }
printf("\n Addition Matrix : ");
    // Displaying sum Matrix
    for(i=0;i<p;i++)
    {
        printf("\n");
        for(j=0;j<q;j++)
        {
            printf("%d ",C[i][j]);
        }
    }

    //Multiplication
    if(n==p)
    {
        //int M[m][q];
        for(i=0;i<m;i++)
    {
        
        for(j=0;j<q;j++)
        {
            for(int k=0;k<p;k++)
            {
                sum+=A[i][k]*B[k][j];
            }
            M[i][j]=sum;
            sum=0;
        }
    }
    }
printf("\nMultiplication Matrix : ");
    //Display Multiplication Matrix 
    for(i=0;i<m;i++)
    {
        printf("\n");
        for(j=0;j<q;j++)
        {
            printf("%d ",M[i][j]);
        }
    }


}
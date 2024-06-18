#include <stdio.h>
int main()
{
    int n;
    int j;
    int a=1;
    scanf("%d", &n);
    for(int i=0; i<=n; i++)
    {
        printf("\n");
        for(int j=0; j<n-i+1; j++)
        {
            printf(" ");
        }
        for(int j=1; j<=2*i-1; j++){

        
        printf("*");
    }
    }

/*   for(int i=0; i<n; i++)
    {
        printf("\n");
        for(int j=0; j<=i; j++)
        {
            printf(" %d",a);
            a++;
        }
    }
}*/
// centra line
printf("\n");
for(int i=0; i<2*n+1; i++)
{
    printf("*");
}
//last part 
for(int i=0; i<n; i++)
{
    printf("\n");
    for(int j=0; j<=i; j++)
    {
        printf(" ");
    }
    for(int j=0;j<2*(n-i)-1;j++)
    {
        printf("*");
    }
    
}
}
#include <stdio.h>
int main()
{

    int i,j,n;
    int k=0;
    scanf("%d",&n);
    for(i=0;i<=n;i++){
        printf("\n");
        for(j=0;j<=i;j++){
            printf("%c",65+i); 
            k++; 
        }
        

    }

}
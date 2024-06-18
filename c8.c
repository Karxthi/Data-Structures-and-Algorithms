#include <stdio.h>
int sum(int,int);
int main()
{
    int a,b,c;
    scanf("%d",&a);
    scanf("%d",&b);
    c=sum(a,b);
    printf("sum %d",c);
}
int sum(int x,int y)
{
    int sum;
    sum=x+y;
    return sum;
}
#include <stdio.h>
int prod(int *a, int *b);
int sum(int ,int );
int ar(int *arr, int a);
int even,odd;
int main()
{
    int i,j,c,d;
    int n;
    
    scanf("%d",&n);
    int a[n];
    scanf("%d",&i);
    scanf("%d",&j);
    c=prod(&i,&j);
    d=sum(i,j);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int *p;
    p=a;
    ar(p,n);
    printf("Product is %d\n",c);
    printf("Sum is %d\n",d);
    printf("\nOdd is %d",odd);
    printf("\neven is %d",even);
    
}
int prod(int *a, int *b)
{
    return *a*(*b);
}
int sum(int a,int b)
{
    return a+b;
}
int ar(int *arr,int a)
{
    for(int i=0;i<a;i++)
    {
        if(*arr%2==0)
        {
            even++;
            //printf("\n %d ",arr[i]);
        }
        else{
            odd++;
            //printf("\n %d ",arr[i]);
        }
        arr++;
    }
    
}
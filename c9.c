#include <stdio.h>
#include <stdlib.h>
int c;
void count(int *pt,int no);
int main()
{
    int n;
    scanf("%d", &n);
   
    int *ptr;
    ptr=(int*)malloc(n*sizeof(int));

    for(int i=0;i<n;i++)
    {
        printf("enter element %d\n",i+1);
        scanf("%d",(ptr+i));//VVIPP DONT USE " * " WHILE ASSIGNING
    }
    for(int i=0;i<n;i++)
    {
        printf("%d\n",*(ptr+i));

    }
    count(ptr,n);
}
void count(int *pt,int no)
{
    for(int i=0;i<no;i++)
    {
        if(*(pt+i)%2==0)
        {
            c++;
        }
    }
    printf(" even  is %d",c);

}
#include <stdio.h>
#include <stdlib.h>
int count=0;
struct node
{
    int value;
    struct node *next;
};
int countt(struct node *ptr,int n,int e)
{
    for(int i = 0; i < n; i++)
    {
        if((ptr+i)->value==e)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    int n,ele,s;
    scanf("%d",&n);
    struct node *head;
   
 
    for(int i = 0; i <n;i++)
    {
        scanf("%d",&s);
        printf("umbi");
        head->value=s;
        printf("umbi");
        (head+i)->next =NULL;
    }
    scanf("%d",&ele);
    count=countt(head,n,ele);
    printf("count is %d",count);
}
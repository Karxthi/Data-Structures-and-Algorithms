#include <stdio.h>
#include <stdlib.h>
//int find(struct *ptr,char name[],int a);

struct student
{
    int rollno;
    char name[20];
    int mark;
};
void find(struct student *s,int ele,int n);
int main()
{
    typedef struct student c;
    int n;
    int nm;
    scanf("%d",&n);
    
    c *ptr;
    ptr=(struct student*)malloc(n*sizeof(struct student));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&(ptr+i)->rollno);
        scanf("%s",(ptr+i)->name);
        scanf("%d",&(ptr+i)->mark);
    }
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\n",(ptr+i)->rollno);
        printf("%s\n",(ptr+i)->name);
        printf("%d\n",(ptr+i)->mark);
        printf("\n  ");
    }
    scanf("%d",&nm);
    find(ptr,nm,n);
    //find(ptr,nm[20],n);
}
void find(struct student *s,int ele,int n)
{
    for(int i=0;i<n;i++)
    {
        if((s+i)->rollno==ele)
        {
            printf("found at %d",i+1);
            printf("%d\n",(s+i)->rollno);
        printf("%s\n",(s+i)->name);
        printf("%d\n",(s+i)->mark);
        }
    }
}
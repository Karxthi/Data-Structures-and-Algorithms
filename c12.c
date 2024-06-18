#include <stdio.h>
#include <stdlib.h>
int find(struct employee *a,int e,int n);
struct employee
{
    int id;
    char name[100];
    int salary;

};
int main()
{
    typedef struct employee emp;
    int n;
    printf("Enter number of employees:");
    scanf("%d", &n);    
    emp *ptr;
    ptr=(struct employee*)malloc(n*sizeof(struct employee));
    for(int i=0; i<n; i++)
    {
        printf("\n employee id :");
        scanf("%d",&(ptr+i)->id);
        printf("\n employee name :");
        scanf("%s",(ptr+i)->name);
        
        printf("\n employee salary :");
        scanf("%d",&(ptr+i)->salary);
    }
    //display
    for(int i=0; i<n; i++)
    {
        printf("\n");
        printf("\n employee id %d ",(ptr+i)->id);
        
        printf("\n employee name %s",(ptr+i)->name);
        
        printf("\n employee salary %d",(ptr+i)->salary);
        
    }

}
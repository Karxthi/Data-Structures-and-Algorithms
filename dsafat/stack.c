#include<stdio.h>
#include<stdbool.h>
#define N 10
int n;
int top=-1;
int stack[N];
bool isempty(){
    return top==-1?true:false;
}
bool isfull(){
    return top==n-1?true:false;

}
void push(){
    if(isfull()){
        printf("\nfull stack");
    }
    else{
        int val;
        printf("\nenter value:");
        scanf("%d",&val);
        top+=1;
        stack[top]=val;
    }
}
void pop(){
    if(isempty()){
        printf("\nempty stack");
    }
    else{
        int val=stack[top];
        printf("\n value to be popped: %d",val);
        top--;
    }
}
void display(){
    if(isempty()){
        printf("\nempty stack");
    }
    else{
        for(int i=top;i>=0;i--){
            printf(" %d",stack[i]);
        }
    }
}

int main ()  
{  
      
    printf("Enter the number of elements in the stack ");   
    scanf("%d",&n); //            number of elements for the stack
    printf("*********Stack operations using array*********");  
    int choice;
printf("\n----------------------------------------------\n");  
    while(choice != 5)  
    {  
        printf("\n\t\t\tChose one from the below options...\n");  
        printf("\n\t\t\t1.Push\n\t\t\t2.Pop\n\t\t\t3.Display\nn\t\t\t5.Exit");  
        printf("\n\t\t\t Enter your choice \n");        
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            {   
                push();  
                break;  
            }  
            case 2:  
            {  
                pop();  
                break;  
            }  
            case 3:  
            {  
                display();  
                break;  
            }  
        
            case 5:
            {
                printf("\nFinished");  
                break; 
            }
            default:  
            {  
                printf("\nEnter valid choice ");
                break;
            }   
        };  
    }  
}  
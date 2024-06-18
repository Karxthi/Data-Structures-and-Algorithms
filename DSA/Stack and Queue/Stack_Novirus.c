#include <stdio.h>   
#include <stdbool.h>
#define N 100 // Setting the maximum upperlimit for the size of the stack
int stack[N],i,j,choice=0,n,top=-1;  
bool isEmpty();
bool isFull();
void push();  
void pop();      //pre declaring all functions
void Display();
void peek();

void main ()  
{  
      
    printf("Enter the number of elements in the stack ");   
    scanf("%d",&n); //            number of elements for the stack
    printf("*********Stack operations using array*********");  
  
printf("\n----------------------------------------------\n");  
    while(choice != 5)  
    {  
        printf("\n\t\t\tChose one from the below options...\n");  
        printf("\n\t\t\t1.Push\n\t\t\t2.Pop\n\t\t\t3.Display\n\t\t\t4.Peek\n\t\t\t5.Exit");  
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
                Display();  
                break;  
            }  
            case 4:   
            {  
                peek();
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
bool isEmpty(){
    if(top==-1){
        return true;
    }
    else{
        return false;
    }
}

bool isFull(){
    if(top==n-1){
        return true;
    }
    else{
        return false;
    }
}
void push ()  
{  
    int val=0;      
    if (isFull()) { 
        printf("\noverflow"); 
        //prinf("\nOverflow"); 
    }
    else   
    {  
        printf("\nEnter the value?");  
        scanf("%d",&val);         
        top = top +1;   
        stack[top] = val;   
    }   
}   
  
void pop ()   
{   
    if(isEmpty()){
        printf("\nUnderflow");
    
    } 
    else  {
        printf("\n%d",stack[top]);
        top = top -1;   
}   
}
void Display()  
{  
    if(isEmpty()){
        printf("\nUnderflow");    
        }
    for (i=top;i>=0;i--)  
    {  
        printf("\n%d\n",stack[i]);  
    }  

    
}  
void peek(){
    if(isEmpty()){
        printf("\nUnderflow");
    }
    else{
        printf("\n%d\n",stack[top]);
    }
}
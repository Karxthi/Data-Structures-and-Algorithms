#include<stdio.h>
#include<stdbool.h>
#define N 10
int queue[N];
int n;
int rear=-1;
int front=-1;
bool isempty(){
    return rear==-1?true:false;
}
bool isfull(){
    return rear==n-1?true:false;
}
void push(){
    if(isfull()){
        printf("\nQueue is full");
    }
    else{
        if(rear==-1 && front==-1){
            rear=0;
            front=0;
        }
        else{
            rear++;
        }
        int val;
        printf("\nEnter value for queue:");
        scanf("%d",&val);
        queue[rear]=val;
    }
}
void pop(){
    if(isempty()){
        printf("\nQueue is empty");
    }
    else{
        int val=queue[front];
        if(rear==front)
        {
            rear=-1;
            front=-1;// reached right side end
        }
        else{
            front++;
        }
        printf("\n Value popped is %d",val);
    }
}
void display(){
    if(isempty()){
        printf("Stack is empty");
    }
    else{
        for(int i=front;i<=rear;i++){
            printf(" %d",queue[i]);
        }
    }
}
int main(){

   printf("Enter N vallue: ");
   scanf("%d",&n);
   while (true){
       printf("\n\n1.Empty 2.Full 3.Enqueue 4.Dequeue  5. Display 6. exit\n Enter : ");
       scanf("%d", &n);
       switch (n) {
           case 1: (isempty())? printf("\nQueue Empty") : printf("\nQueue Not Empty"); break;
           case 2: (isfull())? printf("Queue Full") : printf("Queue Not Full"); break;
           case 3:{
               push();
               break;
               }
           case 4: pop(); break;
           case 5: display(); break;
           case 6: return 0;
       }
   }
}

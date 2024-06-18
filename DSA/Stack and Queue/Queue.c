#include <stdio.h>
#include <stdbool.h>
int front = -1;
int rear = -1;
int maxsize = 20;
int queue[20];      //queue of maxsize = 20


bool isFull(){
   return (rear == (maxsize-1));
}


bool isEmpty(){
   return (rear == -1);
}


void enqueue(int e){
   if (isFull()){
       printf("Queue is full\n");
       return;
   }
   else{
       if (front == -1 && rear == -1){
           front = 0;
           rear = 0;
       }
       else{
           rear++;
       }
       queue[rear] = e;
   }
}


void dequeue(){
   if (isEmpty()){
       printf("Queue is empty\n");
       return;
   }
   else{
       int y = queue[front];
       if (front == rear){
           front = rear = -1;
       }
       else{
           front++;
       }
       printf("\nRemoved %d\n", y);
   }
}


void display(){
   if (isEmpty()){
       printf("Queue is empty\n");
       return;
   }
   else{
       printf("\n\n\n Queue : ");
       for (int i = front; i<= rear; i++){
           printf("%d ", queue[i]);
       }
   }
}




int main(){
   int n;
   while (true){
       printf("\n\n1.Empty 2.Full 3.Enqueue 4.Dequeue  5. Display 6. exit\n Enter : ");
       scanf("%d", &n);
       switch (n) {
           case 1: (isEmpty())? printf("\nQueue Empty") : printf("\nQueue Not Empty"); break;
           case 2: (isFull())? printf("Queue Full") : printf("Queue Not Full"); break;
           case 3:{
               int x;
               printf("Enter Element : ");
               scanf("%d", &x);
               enqueue(x); break;
               }
           case 4: dequeue(); break;
           case 5: display(); break;
           case 6: return 0;
       }
   }
}

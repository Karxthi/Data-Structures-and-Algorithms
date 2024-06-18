#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int data;
    struct Node *next;
};

struct Queue{
    struct Node *front;
    struct Node *rear;
    int count;
    int capacity;
};

struct Queue* createQueue(int capacity){
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->count = 0;
    queue->capacity = capacity;
    return queue;
}

bool isEmpty(struct Queue* queue){
    return queue->count == 0;
}

bool isFull(struct Queue* queue){
    return queue->count == queue->capacity;
}

struct Queue* enqueue(struct Queue* queue, int data){
    if (isFull(queue)){
        printf("Queue is full\n");
        return queue;
    }
    else{
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = data;
        temp->next = NULL;
        if(queue->front == NULL && queue->rear == NULL){
            queue->front = queue->rear = temp;
        }
        else{
            queue->rear->next = temp;
            queue->rear = temp;
        }
        queue->count++;
    }
    return queue;
}

struct Queue* dequeue(struct Queue* queue){
    if (isEmpty(queue)){
        printf("Queue is empty\n");
    }
    else{
        struct Node* temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
        queue->count--;
    }
    return queue;
}

void display(struct Queue* queue){
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    } else {
        struct Node* temp = queue->front;
        printf("\nElements : \n");
        while(temp != NULL){
            printf("%d\n", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}


int main(){
    int n;
    int size;
    printf("Enter size of queue : ");
    scanf("%d", &size);
    struct Queue* queue = createQueue(size);
    while (true){
        printf("\n\n1.Empty 2.Full 3.Enqueue 4.Dequeue  5. Display 6. exit\n Enter : ");
        scanf("%d", &n);
        switch (n) {
            case 1: (isEmpty(queue))? printf("\nQueue Empty") : printf("\nQueue Not Empty"); break;
            case 2: (isFull(queue))? printf("Queue Full") : printf("Queue Not Full"); break;
            case 3:{
                int x;
                printf("Enter Element : ");
                scanf("%d", &x); 
                enqueue(queue, x); break;
                }
            case 4: dequeue(queue); break;
            case 5: display(queue); break;
            case 6: return 0;
        }
    }
}
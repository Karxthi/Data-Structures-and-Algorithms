#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack{
    struct Node* head;
    int count;
    int max;
};

struct Stack* createStack(int size){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->head = NULL;
    stack->count = 0;
    stack->max = size;
    return stack;
}


bool isEmpty(struct Stack* stack){
    return stack->head == NULL;
}

bool isFull(struct Stack* stack){
    return stack->count == stack->max;
}


struct Stack* push(struct Stack* stack, int data){
    if (isFull(stack)){
        printf("Overflow\n");
    }    
    else{
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = data;
        temp->next = stack->head;
        stack->head = temp;
        stack->count++;
    }
    return stack;
}


struct Stack* pop(struct Stack* stack){
    if (isEmpty(stack)){
        printf("Underflow\n");
    }
    else{
        struct Node* temp = stack->head;
        stack->head = stack->head->next;
        stack->count--;
        printf("Popped : %d\n", temp->data);
        free(temp);
    }
    return stack;
}

void display(struct Stack* stack){
    struct Node* temp = stack->head;
    while (temp!= NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void peek(struct Stack* stack){
    if (isEmpty(stack)){
        printf("Stack Empty\n");
    }
    else{
        printf("\nTop Element : %d\n", stack->head->data);
    }
}

int main(){
    int n;
    int size;
    printf("Enter size of stack : ");
    scanf("%d", &size);
    struct Stack* stack = createStack(size);
    while (true){
        printf("\t\t\n\n 1.Empty\n 2.Full\n 3.push\n 4.pop\n 5.peek\n 6.Display\n 7. exit\n Enter : ");
        scanf("%d", &n);
        switch (n) {
            case 1: (isEmpty(stack))? printf("Stack Empty\n") : printf("Stack Not Empty\n"); break;
            case 2: (isFull(stack))? printf("Stack Full\n") : printf("Stack Not Full\n"); break;
            case 3:{
                int x;
                printf("Enter Element : ");
                scanf("%d", &x); 
                push(stack, x); break;
                }
            case 4: pop(stack); break;
            case 5 : peek(stack); break;
            case 6: display(stack); break;
            case 7: free(stack); return 0;
        }
    }
}
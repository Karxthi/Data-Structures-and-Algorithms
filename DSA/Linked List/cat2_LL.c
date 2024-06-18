#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

void LLTraversal(struct Node *head){
    struct Node *ptr = head;
    while(ptr!=NULL){
        printf("\n%d",ptr->data);
        struct Node *next = ptr->next;
    }
}
//insertn

struct Node * insertatfirst(struct Node *head,int data){
    struct Node *ptr = head;
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

void insertatindex(struct Node *head,int index,int data){
    struct Node *iterationhead = head;
    int i=0;
    while(i!=index){
        iterationhead = iterationhead->next;
        i++;
    }
    struct Node *ptr;
    ptr->data = data;
    ptr->next = iterationhead->next;
    iterationhead->next = ptr;
}

void insertatlast(struct Node *head,int data){
    struct Node * iterationhead=head;
    while(iterationhead->next!=NULL){
        iterationhead=iterationhead->next;
    }
    struct Node * ptr;
    ptr->data=data;
    iterationhead->next=ptr;
    ptr->next=NULL;

}

void insertAfterValue(struct Node *node,int value,int data){
    struct Node * ptr;
    ptr->data=data;
    struct Node *iterationhead;
    while(iterationhead->next!=NULL && iterationhead->data!=value){
        iterationhead=iterationhead->next;

    }
    ptr->next=iterationhead->next;
    iterationhead->next=ptr;
}

int main(){
    struct Node *head= (struct Node *)malloc(sizeof(struct Node));
    head->next=NULL;
    head->data=0;
    head = insertatfirst(head,1);
    insertatlast(head,4);
    insertatindex(head,2,2);
    insertAfterValue(head,2,3);

    LLTraversal(head);


}

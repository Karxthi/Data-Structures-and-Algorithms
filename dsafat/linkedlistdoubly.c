#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node * createnode(int data){
    struct Node * ptr=(struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;
}
void LLtraversal(struct Node *ptr)
{
    while(ptr!=NULL)
    {
        printf("Element: %d\n",ptr->data);
        ptr=ptr->next;
    }
}
//insrting
struct Node *insertfirst(struct Node *head,int data){
    struct Node *ptr=createnode(data);
    ptr->next = head;
    ptr->prev = NULL;
    return ptr;
}
void insertatindex(struct Node *head,int data,int index){
    struct Node *ptr=createnode(data);
    struct Node * iterationhead=head;
    int i=0;
    while(i!=index-1){
        iterationhead=iterationhead->next;
        i++;
    }
    ptr->next=iterationhead->next;
    iterationhead->next=ptr;
    ptr->prev=iterationhead;
    iterationhead->next->prev=ptr;
}
void insertlast(struct Node * head,int data){
    struct Node * ptr=createnode(data);
    struct Node * iterationhead=head;
    while(iterationhead->next!=NULL){
        iterationhead=iterationhead->next;
    }
    iterationhead->next=ptr;
    ptr->next=NULL;
    ptr->prev=iterationhead;
}
//deletion

struct Node * deletefirst(struct Node * head){
    struct Node *ptr=head;
    head=head->next;
    head->prev=NULL;
    free(ptr);
    return head;
}
void deleteatindex(struct Node * head, int index){
    struct Node *p= head;
    struct Node *q= head->next;
    int i=0;
    while(i!=index-1){
        p=p->next;
        q=q->next;
        i++;
    }
    p->next=q->next;
    q->next->prev=p;
    free(q);
}
void deletelast(struct Node * head){
    struct Node *p= head;
    struct Node *q= head->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
}
int main()
{
   struct Node * head = (struct Node *)malloc(sizeof(struct Node));
    struct Node * tail = (struct Node *)malloc(sizeof(struct Node));

    head->data =1;
    head->next =tail;
    head->prev=NULL;
    tail->data =3;
    tail->next=NULL;
    tail->prev=head;
    printf("\nInitially");
    LLtraversal(head);
    //______________Insertion at First________________
    printf("\nInsetion at First\n");
    head=insertfirst(head,0);
    LLtraversal(head);
    //______________Insertion at index________________
    printf("\nInsetion at Index\n");
    insertatindex(head,2,2);
    LLtraversal(head);
    //______________Insertion at Last________________
    printf("\nInsetion at Last\n");
    insertlast(head,4);
    LLtraversal(head);
    //______________Deletion at First________________
    printf("\nDeletion at First\n");
    head=deletefirst(head);
    LLtraversal(head);
    //______________Deletion at Index________________
    printf("\nDeletion at Index\n");
    deleteatindex(head,2);
    LLtraversal(head);
    //______________Deletion at Last________________
    printf("\nDeletion at Last\n");
    deletelast(head);
    LLtraversal(head);
}
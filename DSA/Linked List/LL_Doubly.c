#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
void LinkedListTraversal(struct Node * ptr)
{
    //struct Node * ptr = ptr;
    while(ptr!=NULL){
        printf("\nElement: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
//_______________________________INSERTIONS_____________________________
struct Node * insertFirst(struct Node * head,int data){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    ptr->prev = NULL;
    return ptr;
}

void insertAtIndex(struct Node * head,int index,int data){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node * iterationhead = head;
    int i=0;
    while(i!=index-1){
        iterationhead = iterationhead->next;
        i++;
    }
    ptr->data = data;

    ptr->next = iterationhead->next; // next of i th node
    iterationhead->next=ptr; // next of i-1 th  node

    ptr->prev = iterationhead; // prev of i node
    iterationhead->next->prev=ptr; // prev of i+1 th node

}

void insertAtLast(struct Node * head,int data){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node * iterationhead = head;
    while(iterationhead->next!=NULL){
        iterationhead=iterationhead->next;
    }
    iterationhead->next=ptr;
    ptr->next=NULL;
    ptr->prev=iterationhead;
    ptr->data =data;
}

//___________________________DELETIONS__________________________

struct Node * deleteFirst(struct Node *head){
    struct Node * ptr=head;
    head=head->next;
    head->prev=NULL;
    free(ptr);
    return head;
}

void deleteValue(struct Node * head,int value){
    struct Node * p=head;
    struct Node *q= head->next;
    while(q->next!=NULL && q->data!=value){
        q=q->next;
        p=p->next;
    }
    p->next=q->next;
    q->next->prev =p;
    free(q);
}
void deleteLast(struct Node * head){
    struct Node *p=head;
    struct Node *q=head->next;
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
    LinkedListTraversal(head);
    //______________Insertion at First________________
    printf("\nInsetion at First\n");
    head=insertFirst(head,0);
    LinkedListTraversal(head);
    //______________Insertion at index________________
    printf("\nInsetion at Index\n");
    insertAtIndex(head,2,2);
    LinkedListTraversal(head);
    //______________Insertion at Last________________
    printf("\nInsetion at Last\n");
    insertAtLast(head,4);
    LinkedListTraversal(head);
    //______________Deletion at First________________
    printf("\nDeletion at First\n");
    head=deleteFirst(head);
    LinkedListTraversal(head);
    //______________Deletion at Index________________
    printf("\nDeletion at Index\n");
    deleteValue(head,3);
    LinkedListTraversal(head);
    //______________Deletion at Last________________
    printf("\nDeletion at Last\n");
    deleteLast(head);
    LinkedListTraversal(head);
}
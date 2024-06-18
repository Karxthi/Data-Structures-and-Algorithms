#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next; // SIMILAR TO LL , JUST LAST ELEMENT POINTS TO FIRST ELEMENT POINTS
};
//_____________________________INSERTIONS______________________________________________________
struct Node * insertAtFirst(struct Node * head,int data){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node * p=head;
    while(p->next!=head){// last node
        p=p->next;
    }
    ptr->data=data;
    //ptr->next=p->next;
    ptr->next=head;
    p->next=ptr;
    return ptr;
//-----------------Here just iterate just like insertAt index, then add node in between(start)---------------------------------------
}

void insertAtIndex(struct Node * head,int index,int data){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node * iterationhead=head;
    int i=0;
    while(i!=index-1){
        iterationhead=iterationhead->next;
        i++;
    }
    ptr->next=iterationhead->next;
    iterationhead->next=ptr;
    ptr->data=data;
}

void insertAtEnd(struct Node * head,int data){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node * iterationhead=head;
    while(iterationhead->next!=head){
        iterationhead=iterationhead->next;
    }
    iterationhead->next=ptr;
    ptr->data=data;
    ptr->next=head;

}
//_______________________DELETION_________________


struct Node * deleteFirst(struct Node *head){
    struct Node * p = head;//------just for deletion(freeing)---------
    struct Node * iterationhead=head;
    while(iterationhead->next!=head){
        iterationhead=iterationhead->next;
    }// reaches the last index
    head=head->next;
    iterationhead->next=head;
    //--------------------Its Important to make sure last node points to updates first node------------------------------
    free(p);
    return head;
}


void deleteValues(struct Node *head,int value){
    struct Node * p=head;
    struct Node * q=head->next;
    while(q->data!=value & q->next!=head){//*******************MISTAKE Q->DATA ********************************
        p=p->next;
        q=q->next;// reaches node just before
    }
    p->next=q->next;
    free(q);


}

void deleteLast(struct Node *head){
    struct Node *p=head;
    struct Node *q=head->next;
    while(q->next!=head){
        p=p->next;
        q=q->next;// reaches node just before
    }
    p->next=head;
    free(q);


}
void LinkedListTraversal(struct Node * head)
{
    struct Node *ptr=head;
    do{
        printf("\n Element : %d", ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);//_______________________MANUALLY INCREMENTING ONE TIME__________________________________
//_______________________(otherwise wont run, since ptr is head initially)________________________________
       
}
int main()
{
   struct Node * head = (struct Node *)malloc(sizeof(struct Node));
    struct Node * tail = (struct Node *)malloc(sizeof(struct Node));

    head->data =1;
    head->next =tail;
    tail->data =3;
    tail->next=head;
    printf("\n Intially");
    LinkedListTraversal(head);
    //_________Insertion at first node________
    printf("\nInsertion at first\n");
    head=insertAtFirst(head,0);
    LinkedListTraversal(head);
    //__________Insertion at index____________
    printf("\nInsertion at index\n");
    insertAtIndex(head,2,2);
    LinkedListTraversal(head);
    //___________Insertion at end_____________
    printf("\nInsertion at end\n");
    insertAtEnd(head,4);
    LinkedListTraversal(head);
    //___________Deletion at first____________
    printf("\nDeletion at first\n");
    head=deleteFirst(head);
    LinkedListTraversal(head);
    //___________Deletion at value____________
    printf("\nDeletion at value\n");
    deleteValues(head,2);
    LinkedListTraversal(head);
    //___________Deletion at Last____________
    printf("\nDeletion at Last\n");
    deleteLast(head);
    LinkedListTraversal(head);
    
    
}
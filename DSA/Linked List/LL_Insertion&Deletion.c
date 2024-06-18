#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
//INSERT AT FIRST
struct Node * insertAtFirst(struct Node * head, int data) // Adds new Head node and returns the new head
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node)); // Create a new node ptr
    ptr->next = head;
    ptr->data = data;
    return ptr; // returns new head node structure
}

//INSERT IN BETWEEN
struct Node * insertAtIndex(struct Node * head, int data,int index) // adds node at any Index and returns it
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * iterationhead =head; //_________________________ We alwys create a new node and assign it as head \
    inside the function , else it will affect the head outside________________________________
    int i=0;

    while(i!=index-1){
        iterationhead=iterationhead->next;
        i++;
    }
    ptr->data = data; //*******imp*******
    ptr->next =iterationhead->next;
    iterationhead->next =ptr;

    return head;
};

//INSERT AFTER NODE , SAME AS BETWEEM
void insertAfter(struct Node * prevNode, int data)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next=ptr;
}

//INSERT AT END

void insertAtEnd(struct Node * head,int data)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * iterationhead=head;
    while(iterationhead->next!=NULL){
        iterationhead=iterationhead->next;

    }
    ptr->data = data;
    iterationhead->next=ptr;
    ptr->next =NULL;

    //return head;
}

//_______________DELETION__________________

struct Node * deleteFirst(struct Node * head){
    struct Node * ptr = head;             // assign a head node   , point it to next, free previous head
    head = head->next;
    free(ptr);
    return head;
}

// Delete after index

void deleteAtindex(struct Node * head,int index){
    struct Node * p = head; //                   0th node
    struct Node * q= head->next; //              1st node
    int i=0;
    while(i<index-1){
        p=p->next;
        q=q->next;
        i++; //         *****MISTAKE I MADE*****
    }
    p->next=q->next;  
    free(q);
    
}

// Delete last node

void deleteLast(struct Node * head){
    struct Node * p=head;
    struct Node * q=head->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);   
}

// Delete by Value

void deleteValue(struct Node * head,int value){
    struct Node * p=head;
    struct Node * q=head->next;
    while(q->next!=NULL && q->data!=value){
        p=p->next;
        q=q->next;
    }
    if(q->data==value){
        p->next=q->next;
        free(q);
    }    
}


void LinkedListTraversal(struct Node * ptr)
{
    while(ptr!=NULL){
        printf(" Element : %d\n",ptr->data);
        ptr=ptr->next;
    }
}


int main(){
    struct Node * head = (struct Node *)malloc(sizeof(struct Node));
    struct Node * tail = (struct Node *)malloc(sizeof(struct Node));

    head->data =1;
    head->next =tail;
    tail->data =2;
    tail->next=NULL;
    LinkedListTraversal(head);
    printf("\n First ");
    
    head=insertAtFirst(head,0);
    LinkedListTraversal(head);
    printf("\n Between");
    
    head=insertAtIndex(head,222,1);
    LinkedListTraversal(head);
    printf("\n After Node ");

    insertAfter(head,111);
    LinkedListTraversal(head);
    printf("\n End");
    
    insertAtEnd(head,100);
    LinkedListTraversal(head); 

    //Deletion
    printf("\n Deletion\n");
    head=deleteFirst(head);
    LinkedListTraversal(head);

    printf("\n Deletion at Index : 3 \n");
    deleteAtindex(head,2);
    LinkedListTraversal(head);

    printf("\n End \n");
    deleteLast(head);
    LinkedListTraversal(head);

    printf("\n Delete by Value \n");
    deleteValue(head, 222);
    LinkedListTraversal(head);


}


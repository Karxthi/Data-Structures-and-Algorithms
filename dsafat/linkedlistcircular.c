#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
void LLtraversal(struct Node * head){
    struct Node * ptr=head;
    do{
        printf("\n Element %d ", ptr->data);
        ptr = ptr->next;
    }
    while(ptr!=head);
}
struct Node * createnode(int data){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    return ptr;
}
//insertion
struct Node * insertfirst(struct Node *head,int data){
    struct Node * ptr=createnode(data);
    struct Node * iterationhead = head;
    while(iterationhead->next!=head){
        iterationhead = iterationhead->next;
    }
    iterationhead->next=ptr;
    ptr->next=head;
    return ptr;
}
void insertatindex(struct Node * head,int data,int index){
    struct Node * ptr=createnode(data);
    struct Node * iterationhead=head;
    int i=0;
    while(i!=index-1){
        iterationhead=iterationhead->next;
        i++;
    }
    ptr->next=iterationhead->next;
    iterationhead->next=ptr;
}
void insertatlast(struct Node * head,int data){
    struct Node * ptr=createnode(data);
    struct Node *iterationhead=head;
    while(iterationhead->next!=head){
        iterationhead=iterationhead->next;
    }
    iterationhead->next=ptr;
    ptr->next=head;
}
struct Node* deletefirst(struct Node *head){
    struct Node * ptr=head;
    struct Node * iterationhead=head;
    while(iterationhead->next!=head){
        iterationhead=iterationhead->next;
    }
    head=head->next;
    iterationhead->next=head;
    free(ptr);
    return head;
}
void deleteatindex(struct Node * head, int index){
    struct Node * p=head;
    struct Node * q=head->next;
    int i=0;
    while(i!=index-1){
        p=p->next;
        q=q->next;
        i++;
    }
    p->next=q->next;
    free(q);
}
void deletelast(struct Node * head){
    struct Node * p=head;
    struct Node * q=head->next;
    while(q->next!=head){
        p=p->next;
        q=q->next;
    }
    p->next=head;
    free(q);

}
int main(){
    // //struct Node * head = createnode(0);
    // struct Node * head=createnode(1);
    // head=insertfirst(head,1);
    // insertatindex(head, 2, 1);
    // insertatlast(head, 3);
    // LLtraversal(head);
    // printf("\n\tdeletion");
    // head=deletefirst(head);
    // deleteatindex(head, 2);
    // LLtraversal(head);
    // deletelast(head);
    // LLtraversal(head);
    struct Node * head=createnode(1);
    head->next=head;
    printf("\n Intially");
    LLtraversal(head);
    //_________Insertion at first node________
    printf("\nInsertion at first\n");
    head=insertfirst(head,0);
    LLtraversal(head);
    //__________Insertion at index____________
    printf("\nInsertion at index\n");
    insertatindex(head,2,2);
    LLtraversal(head);
    //___________Insertion at end_____________
    printf("\nInsertion at end\n");
    insertatlast(head,4);
    LLtraversal(head);
    //___________Deletion at first____________
    printf("\nDeletion at first\n");
    head=deletefirst(head);
    LLtraversal(head);
    //___________Deletion at value____________
    printf("\nDeletion at value\n");
    deleteatindex(head,2);
    LLtraversal(head);
    //___________Deletion at Last____________
    printf("\nDeletion at Last\n");
    deletelast(head);
    LLtraversal(head);
}

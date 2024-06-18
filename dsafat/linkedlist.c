#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node * createnode(int data){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    return ptr;
}
struct Node *insertfirst(struct Node * head,int data){
    struct Node * ptr = createnode(data);
    ptr->next=head;
    return ptr;
}
void insertatindex(struct Node * head,int data,int index){
    struct Node *ptr = createnode(data);
    struct Node *iterationhead=head;
    int i=0;
    while(i!=index-1){
        iterationhead=iterationhead->next;
        i++;
    }
    ptr->next=iterationhead->next;
    iterationhead->next=ptr;
    }
void insertlast(struct Node * head,int data){
    struct Node * ptr=createnode(data);
    struct Node* iterationhead=head;
    while(iterationhead->next!=NULL){
        iterationhead=iterationhead->next;
    }
    iterationhead->next=ptr;
    ptr->next=NULL;
}
//deltion
struct Node *deletefirst(struct Node * head){
    struct Node *ptr=head;
    head=head->next;
    free(ptr);
    return head;
}

void deleteatindex(struct Node * head,int index){
    struct Node *p=head;
    struct Node *q=head->next;
    int i=0;
    while(i!=index-1){
        p=p->next;
        q=q->next;
        i++
    }
    p->next=q->next;
    free(q);
}

void deletelast(struct Node * head){
    struct Node *p=head;
    struct Node *q=head->next;
    while(q->next!=NULL){
        q=q->next;
        p=p->next;
    }
    p->next=NULL;
    free(q);
}

void deletebyvalue(struct Node * head,int value){
    struct Node *p=head;
    struct Node *q=head->next;
    while(q->data!=value && q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    if(q->data==value){
        p->next=q->next;
        free(q);
    }
}
void LLTraversal(struct Node *ptr){
    while(ptr!=NULL){
        printf(" %d ", ptr->data);
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
    LLTraversal(head);
    printf("\n First ");
    
    head=insertfirst(head,1);
    LLTraversal(head);
    printf("\n Between");
    
    insertatindex(head,222,1);
    LLTraversal(head);
    printf("\n After Node ");

    insertlast(head,111);
    LLTraversal(head);
    printf("\n End");
    
    insertlast(head,100);
    LLTraversal(head); 

    //Deletion
    printf("\n Deletion\n");
    head=deletefirst(head);
    LLTraversal(head);

    printf("\n Deletion at Index : 3 \n");
    deleteatindex(head,2);
    LLTraversal(head);

    printf("\n End \n");
    deletelast(head);
    LLTraversal(head);

    printf("\n Delete by Value \n");
    deletebyvalue(head, 222);
    LLTraversal(head);


}


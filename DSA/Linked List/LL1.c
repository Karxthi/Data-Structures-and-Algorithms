#include <stdio.h>
#include <stdlib.h>
struct Node
{
    /* data */
    int data;
    struct Node *next;
};

void LinkedListTraversal(struct Node * ptr)
{
    while(ptr!=NULL){
        printf("\n Element : %d",ptr->data);
        ptr=ptr->next; // points to next
    }
}
int main()
{
    struct Node * head; // Head Node Pointer
    struct Node * second; // Second Node Pointer
    struct Node * tail; // Tail Node Pointer
  
    // Allocate memory for nodes in the LL in HEAP
    head = (struct Node *)malloc(sizeof(struct Node)); // Head node size
    second = (struct Node *)malloc(sizeof(struct Node)); // second node size
    tail = (struct Node *)malloc(sizeof(struct Node)); // Tail node size   

    head->data = 1;
    head->next = second;

    //Link second and tail nodes 

    second->data =2;
    second->next = tail;

    //Terminate at last node 

    tail->data =3;
    tail->next = NULL; // NULL 

    LinkedListTraversal(head); //       becuase it starts from head node
    return 0;
}
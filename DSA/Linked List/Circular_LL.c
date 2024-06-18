#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
if (newNode == NULL) {
    printf("Memory allocation failed\n");
    exit(1);
}
newNode->data = data;
newNode->next = NULL;
return newNode;
}
//INSERTTIONS
void insertAtBeginning(struct Node** head, int data) {
    printf("Insertion at Beginning: %d\n", data);
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next; // temp reaches the last node
        }
    temp->next = newNode; 
    newNode->next = *head;
    *head = newNode;//new head
    }
}
void insertAtMiddle(struct Node* head, int data, int position) {
    printf("Insertion at Middle: %d at position %d\n", data, position);
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    for (int i = 1; i < position - 1; i++) {
        if (temp == NULL || temp->next == head) {// ie either overflow or at the last node which isnt middle
            printf("Invalid position\n");
            return;
        }
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    }
void insertAtEnd(struct Node** head, int data) {
    printf("Insertion at End: %d\n", data);
    struct Node* newNode = createNode(data);
    if (*head == NULL) {// if no head
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
             temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}
void deleteFromBeginning(struct Node** head) {
    printf("Deletion from Beginning\n");
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
        }
    if (temp == *head) { // if theres only head node
        free(temp);
        *head = NULL;
    } else {
        struct Node* first = *head;
        temp->next = (*head)->next;
        *head = (*head)->next;
        free(first);
    }
}
void deleteFromMiddle(struct Node** head, int position) {
    printf("Deletion from Middle: position %d\n", position);
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
        for (int i = 1; i < position - 1; i++) {
        if (temp == NULL || temp->next == *head) {
            printf("Invalid position\n");
            return;
        }
        temp = temp->next;
    }
    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}
void deleteFromLast(struct Node** head) {
    printf("Deletion from Last\n");
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* prev = NULL;
    struct Node* temp = *head;
    while (temp->next != *head) {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL) {
        free(temp);
        *head = NULL;
    } else {
        prev->next = temp->next;
        free(temp);
    }
}
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List: ");
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
int main() {
struct Node* head = NULL;
insertAtBeginning(&head, 3);
display(head);
insertAtBeginning(&head, 1);
display(head);
insertAtMiddle(head, 3, 2);
display(head);
insertAtEnd(&head, 4);
display(head);
deleteFromBeginning(&head);
display(head);
deleteFromMiddle(&head, 2);
display(head);
deleteFromLast(&head);
display(head);
return 0;
}
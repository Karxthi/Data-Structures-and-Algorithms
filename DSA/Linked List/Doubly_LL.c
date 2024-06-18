#include <stdio.h>
#include <stdlib.h>
struct Node { // Structure
int data;
struct Node* prev;
struct Node* next;
};

struct Node* createNode(int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
if (newNode == NULL) {
    printf("Memory allocation failed\n");
    exit(1);
}
newNode->data = data;
newNode->prev = NULL;
newNode->next = NULL;
return newNode;
}
void insertAtFirst(struct Node** head, int data) {
    printf("Inserting %d at the beginning\n", data);
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}
void insertAtMiddle(struct Node** head, int data, int position) {
    printf("Inserting %d at position %d\n", data, position);
    if (position < 1) {
        printf("Invalid position\n");
        return;
    }
    if (position == 1) {
        insertAtFirst(head, data);
        return;
    }
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    for (int i = 1; i < position - 1; i++) {
        if (temp == NULL) {
            printf("Invalid position\n"); // underflow
            return;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n"); // Overflow
        return;
    }
    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode; // imp
    }
    temp->next = newNode;
    newNode->prev = temp; // completing the link
}
void insertAtEnd(struct Node** head, int data) {
    printf("Inserting %d at the end\n", data);
    struct Node* newNode = createNode(data);
    if (*head == NULL) { // if there is no head
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}
void deleteFromBeginning(struct Node** head) {
    printf("Deleting from the beginning\n");
    if (*head == NULL) {
        printf("List is empty\n"); // no LL
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next; // point head to next index
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}
void deleteFromMiddle(struct Node** head, int position) {
    printf("Deleting from position %d\n", position);
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (position < 1) {
        printf("Invalid position\n");
        return;
    }
    if (position == 1) {
        deleteFromBeginning(head);
        return;
    }
    struct Node* temp = *head;
    for (int i = 1; i < position; i++) {
        if (temp == NULL) {
            printf("Invalid position\n"); // overflow
            return;
        }
        temp = temp->next;
    }
    // if (temp == NULL) {
    //     printf("Invalid position\n");
    //     return;
    //}
    temp->prev->next = temp->next;// skipping temp next index
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;// skipping temp prev index
    }
    free(temp);
    }
void deleteFromEnd(struct Node** head) {
    printf("Deleting from the end\n");
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        *head = NULL;
    }
    free(temp);
    }
void LLTraversal(struct Node* head) {
    printf("\nList: ");
    
    while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
    }
    printf("\n");printf("\n");
}
int main() {
struct Node* head = NULL;
insertAtFirst(&head, 1);
LLTraversal(head);
insertAtFirst(&head, 3);
LLTraversal(head);
insertAtMiddle(&head, 2, 2);
LLTraversal(head);
insertAtEnd(&head, 4);
LLTraversal(head);
deleteFromBeginning(&head);
LLTraversal(head);
deleteFromMiddle(&head, 1);
LLTraversal(head);
deleteFromEnd(&head);
LLTraversal(head);
return 0;
}
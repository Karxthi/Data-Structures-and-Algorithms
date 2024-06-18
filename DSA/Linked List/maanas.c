#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

void listTraversal(struct Node* head) {
    struct Node* ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
        if (ptr == head)
            break;
    }
}

struct Node* insertAtFirst(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;
    if (head == NULL) {
        head = ptr;
        ptr->next = head;
    } else {
        struct Node* p = head;
        while (p->next != head) {
            p = p->next;
        }
        p->next = ptr;
        ptr->next = head;
        head = ptr;
    }
    return head;
}

struct Node* insertAfter(struct Node* head, int value, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;
    if (head == NULL) {
        head = ptr;
        ptr->next = head;
    } else {
        struct Node* p = head;
        while (p->data != value && p->next != head) {
            p = p->next;
        }
        if (p->data == value) {
            ptr->next = p->next;
            p->next = ptr;
        } else {
            printf("Value not found\n");
            free(ptr);
        }
    }
    return head;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;
    if (head == NULL) {
        head = ptr;
        ptr->next = head;
    } else {
        struct Node* p = head;
        while (p->next != head) {
            p = p->next;
        }
        p->next = ptr;
        ptr->next = head;
    }
    return head;
}

struct Node* deleteFirst(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        struct Node* ptr = head;
        struct Node* p = head;
        while (p->next != head) {
            p = p->next;
        }
        ptr = ptr->next;
        p->next = ptr->next;
        head = ptr->next;
        free(ptr);
    }
    return head;
}

struct Node* deleteByKey(struct Node* head, int value) {
    struct Node* ptr = head;
    struct Node* prev = NULL;
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        do {
            if (ptr->data == value) {
                if (prev == NULL) {
                    head = ptr->next;
                } else {
                    prev->next = ptr->next;
                }
                free(ptr);
                break;
            }
            prev = ptr;
            ptr = ptr->next;
        } while (ptr != head);
    }
    return head;
}

struct Node* deleteLast(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        struct Node* ptr = head;
        struct Node* prev = NULL;
        while (ptr->next != head) {
            prev = ptr;
            ptr = ptr->next;
        }
        if (prev == NULL) {
            head = NULL;
        } else {
            prev->next = head;
        }
        free(ptr);
    }
    return head;
}

int main() {
    struct Node* head = NULL;
    printf("SINGLY CIRCULAR LINKED LIST\n");
    printf("1.Insert At First\n2.Insert At End\n3.Insert After Value\n4.Delete At First\n5.Delete At End\n6.Delete by Key\n7.Display\n8.EXIT");
    int ch;
    while (1) {
        printf("\nInput choice: ");
        scanf("%d", &ch);
        if (ch == 1) {
            int data;
            printf("Insert at First\nEnter the data: ");
            scanf("%d", &data);
            head = insertAtFirst(head, data);
        } else if (ch == 2) {
            int data;
            printf("Insert at End\nEnter the data: ");
            scanf("%d", &data);
            head = insertAtEnd(head, data);
        } else if (ch == 3) {
            int data, value;
            printf("Insert after value\nEnter the value: ");
            scanf("%d", &value);
            printf("Enter the data: ");
            scanf("%d", &data);
            head = insertAfter(head, value, data);
        } else if (ch == 4) {
            printf("Delete First\n");
            head = deleteFirst(head);
        } else if (ch == 5) {
            printf("Delete Last\n");
            head = deleteLast(head);
        } else if (ch == 6) {
            int value;
            printf("Delete a Value\nEnter the value: ");
            scanf("%d", &value);
            head = deleteByKey(head, value);
        } else if (ch == 7) {
            listTraversal(head);
        } else if (ch == 8) {
            break;
        } else {
            printf("Invalid Input");
        }
    }
    return 0;
}
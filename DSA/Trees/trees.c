#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *insertNode(struct Node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }

    return root;
}

void inOrderTraversal(struct Node *root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

void preOrderTraversal(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(struct Node *root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

struct Node *searchNode(struct Node *root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }

    if (value < root->data) {
        return searchNode(root->left, value);
    }

    return searchNode(root->right, value);
}
struct Node *findMinNode(struct Node *root) {
    if (root == NULL || root->left == NULL) {
        return root;
    }
    return findMinNode(root->left);
}
// struct Node *minValueNode(struct Node *node) {
//     struct Node *current = node;
//     while (current && current->left != NULL) {
//         current = current->left;
//     }
//     return current;
// }
struct Node *findMaxNode(struct Node *root) {
    if (root == NULL || root->right == NULL) {
        return root;
    }
    return findMaxNode(root->right);

}

struct Node *deleteNode(struct Node *root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        struct Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int main() {
    struct Node *root = NULL;
    int nodes[] = {5, 3, 8, 2, 4, 6, 9, 1, 7, 10};
    int i, n = sizeof(nodes) / sizeof(nodes[0]);

    for (i = 0; i < n; i++) {
        root = insertNode(root, nodes[i]);
    }

    printf("In-order traversal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Pre-order traversal: ");
    preOrderTraversal(root);
    printf("\n");

    printf("Post-order traversal: ");
    postOrderTraversal(root);
    printf("\n");

    int searchValue = 6;
    struct Node *searchResult = searchNode(root, searchValue);
    if (searchResult != NULL) {
        printf("Node with value %d found in the tree.\n", searchValue);
    } else {
        printf("Node with value %d not found in the tree.\n", searchValue);
    }

    printf("Deleting node with value 8...\n");
    root = deleteNode(root, 8);
    printf("In-order traversal after deletion: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Minimum value node: %d\n", findMinNode(root)->data);
    printf("Maximum value node: %d\n", findMaxNode(root)->data);

    return 0;
}

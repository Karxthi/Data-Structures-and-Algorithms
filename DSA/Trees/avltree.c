#include <stdio.h>
#include <stdlib.h>
struct avlN {
    int data;
    struct avlN* left;
    struct avlN* right;
    int height;
};
struct avlN* createNode(int data) {
    struct avlN* ptr = (struct avlN*)malloc(sizeof(struct avlN));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->height = 1;
    return ptr; // predefined function to create an avl node
}
int height(struct avlN* node) {// height at particular position
    if (node == NULL)
        return 0;
    return node->height;
}
int balanceFactor(struct avlN* node) {// balance factor
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}
void updateHeight(struct avlN* node) {
    if (node != NULL)
        node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));// changing heights
}
struct avlN* leftRotate(struct avlN* x) {
    struct avlN* y = x->right;
    struct avlN* T = y->left;
    y->left = x;
    x->right = T;
    updateHeight(x);
    updateHeight(y);

    return y;
}
struct avlN* rightRotate(struct avlN* y) {
    struct avlN* x = y->left;
    struct avlN* T = x->right;
    x->right = y;
    y->left = T;
    updateHeight(y);
    updateHeight(x);

    return x;
}
struct avlN* insertNode(struct avlN* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);
    else 
        return root;
    updateHeight(root);
    // rotation cases
    int balance = balanceFactor(root);
    if (balance > 1 && data < root->left->data)
        return rightRotate(root);

    if (balance < -1 && data > root->right->data)
        return leftRotate(root);

    if (balance > 1 && data > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && data < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
struct avlN* minValueNode(struct avlN* node) {
    struct avlN* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

struct avlN* deleteNode(struct avlN* root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            struct avlN* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            free(temp);
        } else {
            struct avlN* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;
    updateHeight(root);
    int balance = balanceFactor(root);
    if (balance > 1 && balanceFactor(root->left) >= 0)
        return rightRotate(root);

    if (balance < -1 && balanceFactor(root->right) <= 0)
        return leftRotate(root);

    if (balance > 1 && balanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && balanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
void displayTree(struct avlN* root) {
    if (root != NULL) {
        displayTree(root->left);
        printf("%d ", root->data);
        displayTree(root->right);
    }
}
int main() {
    struct avlN* root = NULL;
    root = insertNode(root, 33);
    root = insertNode(root, 22);
    root = insertNode(root, 77);
    root = insertNode(root, 15);
    root = insertNode(root, 25);
    root = insertNode(root, 11);
    root = insertNode(root, 55);
    root = insertNode(root, 88);
    root = insertNode(root, 35);
    root = insertNode(root, 66);
    printf("Nodes of AVL tree: ");
    displayTree(root);
    printf("\n");
    printf("Delete node 2: ");
    root = deleteNode(root, 66);
    displayTree(root);
    printf("\n");
    printf("Delete node 15: ");
    root = deleteNode(root, 35);
    displayTree(root);
    printf("\n");
    printf("Delete node 5: ");
    root = deleteNode(root, 11);
    displayTree(root);
    printf("\n");
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
struct Node{
    int key;
    struct Node *left;
    struct Node *right;
    int height;//      one more parameter
};
struct Node * createnode(int key){
    struct Node * ptr= (struct Node *)malloc(sizeof(struct Node));
    ptr->key = key;
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->height = 1; // since leaf node has height 1;
    return ptr;
    
}
int max (int a, int b){
    return (a>b)?a:b;
}

int getheight(struct Node *n){
    if(n==NULL){
        return 0;
    }
    return n->height;
}

//_________________BALANCE FACTOR_______________
int getBalanceFactor(struct Node *n){
    if(n==NULL){
        return 0;
    }
    return getheight(n->left) - getheight(n->right);
}

//_______________ ROTATIONS _______________
//LEFT ROTATION

struct Node * rightRotate(struct Node * y){ // y is root
    struct Node * x = y->left; // x is child
    struct Node * T2 =x->right;
    //      x                y
    //     / \              / \ 
    //    T1   y   <=      x   T3
    //        / \         / \ 
    //       T2   T3     T1  T2
    //rotating
    x->right = y;
    y->left=T2;

    y->height=max(getheight(y->right),getheight(y->left))+1;
    x->height=max(getheight(x->right),getheight(x->left))+1;

    return x; // inpostiion of y
}

struct Node * leftRotate(struct Node *x){
    struct Node * y=x->right;
    struct Node *T2=y->left;
    //      x                y
    //     / \              / \ 
    //    T1   y   =>      x   T3
    //        / \         / \ 
    //       T2   T3     T1  T2
    //Linkin
    y->left=x;
    x->right=T2;
    
    y->height=max(getheight(y->right),getheight(y->left))+1;
    x->height=max(getheight(x->right),getheight(x->left))+1;
    
    return y; 
}

struct Node *insert(struct Node* node, int key){
    if (node == NULL)
        return  createnode(key);
 
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
 
    node->height = 1 + max(getheight(node->left), getheight(node->right));
    int bf = getBalanceFactor(node);
 
    // Left Left Case
        if(bf>1 && key < node->left->key){
            return rightRotate(node);
        }
    // Right Right Case
        if(bf<-1 && key > node->right->key){
            return leftRotate(node);
        }
    // Left Right Case
    if(bf>1 && key > node->left->key){
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    // Right Left Case
    if(bf<-1 && key < node->right->key){
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    return node;
}

void preOrder(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(){
    struct Node *root = (struct Node *)malloc(sizeof(struct Node));
    root=insert(root,5);
    root=insert(root,3);
    root=insert(root,6);
    root=insert(root,1);
    root=insert(root,4);
    preOrder(root);
}
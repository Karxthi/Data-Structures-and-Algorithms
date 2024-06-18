#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node * left;
    struct Node * right;
};
struct Node * createnode(int data){
    struct Node * ptr=(struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->left=NULL;
    ptr->right=NULL;
    return ptr;
};
void inorder(struct Node *root){
    if(root!=NULL){
        inorder(root->left);
        printf(" %d",root->data);
        inorder(root->right);
    }
}
void insertion(struct Node * root,int data){
    struct Node * prev=NULL;
    while(root!=NULL){
        prev=root;
        if(root->data==data){
            printf("Invalid");
            return;
            
        }
        else if(data<root->data){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    struct Node * p= createnode(data);
    if(data<prev->data){
        prev->left=p;
    }
    else{
        prev->right=p;
    }
}
int main(){
    struct Node * p=createnode(100);
    insertion(p,100);
    inorder(p);
}

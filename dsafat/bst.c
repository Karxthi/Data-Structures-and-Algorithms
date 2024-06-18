#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node * left;
    struct Node * right;
};
struct Node * createNode(int data){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->left=NULL;
    ptr->right=NULL;
}
void preorder(struct Node * root){
    if(root!=NULL){
        printf(" %d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node * root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf(" %d ",root->data);
    }
}
void inorder(struct Node * root){
    if(root!=NULL){
        inorder(root->left);
        printf(" %d",root->data);
        inorder(root->right);
    }
}
//isbst
int isbst(struct Node * root){
    static struct Node * prev = NULL;
    if(root!=NULL){
        if(!isbst(root->left)){
            return 0;
        }
        else if(prev!=NULL && root->data<=prev->data){
            return 0;

        }
        prev = root;
        return isbst(root->right);
    }
    else{
        return 1;
    }
}
//searhcing
struct Node * search(struct Node * root,int key){
    while(root!=NULL){
        if(root->data==key){
            return root;
        }
        else if(key<root->data){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
}
//insertion
void inser(struct Node * root,int key){
    struct Node * prev =NULL;//temp
    while(root!=NULL){
        prev=root;
        if(root->data ==key){
            printf("\n DUPLICATE!! ");
            return;
        }
        else if(key<root->data){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    struct Node * ptr= createNode(key);
    if(key<prev->data){
        prev->left=ptr;
    }
    else{
        prev->right=ptr;
    }
}

struct Node * iprre(struct Node * root){
    root=root->left;
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}
//deletion
struct Node * delete(struct Node * root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right ==NULL){
        free(root);
        return NULL;
    }
    if(key<root->data){
        root->left= delete(root->left,key);
    }
    else if(key>root->data){
        root->right=delete(root->right,key);
    }
    else{
        struct Node * ipre=iprre(root);
        root->data=ipre->data;
        root->left=delete(root->left,ipre->data);
    }
    return root;
}
int main(){
    
    struct Node *p = createNode(5); // Root Node
    struct Node *p1 = createNode(3);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(1);
    struct Node *p4 = createNode(4);
     // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4  
    //Linking
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    printf("Preorder \n");
    preorder(p);
    printf("\nPostorder \n");
    postorder(p);
    printf("\ninorder\n");
    inorder(p);
    printf("\nIs Binary Tree\n");
    printf("%d\n",isbst(p));
    printf("_______________\nSearching\n");
    struct Node * s= search(p,7);
    if(s!=NULL){
        printf(" Found %d\n",s->data);
    }
    else{
        printf("\nNULL");
    }
    printf("\nINSERTION\n");
    inser(p,7);
    
    inorder(p);
    //printf("\n%d\n",p->right->right->data);
    printf("\n After Deletion\n");
    delete(p,5);
    inorder(p);
}
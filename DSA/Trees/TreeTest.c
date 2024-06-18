#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node * createnode(int data){
    struct Node* ptr=(struct Node*) malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->left =NULL;
    ptr->right =NULL;
}
void preorder(struct Node* root){
    if(root!=NULL){
        printf(" %d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node* root){
    if(root!=NULL){
        postorder(root->left);
        printf(" %d",root->data);
        postorder(root->right);
    }
}
void inorder(struct Node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

int isbst(struct Node* root){
    static struct Node* iterationhead=NULL;
    if(root!=NULL){
        if(!isbst(root->left)){
            return 0;
        }
        if(iterationhead!=NULL && root->data <= iterationhead->data)
        {
            return 0;
        }
        iterationhead=root;
        return isbst(root->right);
    }
    else{
        return 1;
    }
}

struct Node * search(struct Node* root,int data){
    if(root!=NULL){
        if(root->data==data){
            return root;
        }
        else if(data<root->data){
            search(root->left,data);
        }
        else{
            search(root->right,data);
        }
    }
}

void insertion(struct Node* root,int data){
    struct Node * iterationhead = NULL;
    while(root!=NULL){
        iterationhead=root;
        if(root->data==data){
            printf("\n Invalid");}
        else if(data<root->data){
            root=root->left;
        }
        else{
            root=root->right;
        }

    }
    struct Node * ptr = createnode(data);
    if(data<iterationhead->data){
        iterationhead->left=ptr;
    }
    else{
        iterationhead->right=ptr;
    }
}
struct Node * inorderpre(struct Node * root){
    root=root->left;
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}
struct Node * deletion(struct Node * root,int data){
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
    }
    // searching
    if(data<root->data){
        root->left=deletion(root->left,data);
    }
    else if(data>root->data){
        root->right=deletion(root->right,data);

    }
    else{//found
        struct Node *inpre=inorderpre(root);
        root->data=inpre->data;
        root->left=deletion(root->left,inpre->data);
    }
    return root;
    
}
int main()
{
    struct Node * p = createnode(2);
    struct Node * p1= createnode(1);
    struct Node * p2= createnode(3);

    p->right=p2;
    p->left=p1;

    inorder(p);
    printf("insertion\n");
    insertion(p,4);
    inorder(p);
    printf("deletion\n");
    deletion(p,2);
    inorder(p);
}

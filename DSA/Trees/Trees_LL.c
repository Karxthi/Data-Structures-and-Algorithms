#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node * left;
    struct Node * right;
};

// Function to Create a new Node                
struct Node * createNode(int data){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}
//________________________________________________________________

void preOrder(struct Node * root){
    if(root!=NULL){ // to stop at LEAF node
        printf(" %d", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct Node * root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf(" %d", root->data);
    }
}

void inOrder(struct Node * root){
    if(root!=NULL){
        inOrder(root->left);
        printf(" %d", root->data);
        inOrder(root->right);
    }
}

//** To check if a tree is a BinaryTree , we check if   INORDER is ASCENDING
 
int isBST(struct Node * root){
    static struct Node *prev=NULL;// parent node
    if(root!=NULL){
        if(!isBST(root->left)){ // Since Left Subtree should also be a BinaryTree
            return 0;//______LEFT______
        }
        if(prev!=NULL && root->data <= prev->data){// child>parent
            return 0;//______ROOT_______
        }
        prev=root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}

//SEARCHING

struct Node * search(struct Node *root,int key)
{
    if(root!=NULL){
        if(root->data==key){
            return root;
        }
        else if(root->data>key){
            search(root->left,key);
        }
        else if(root->data<key){
            search(root->right,key);
        }
    
    }
    // else{
    //     return NULL;
    // }
}

//INSERTION

void insertNode(struct Node *root,int key){
    struct Node *prev=NULL; // because we need a tempnode for traversing

    while(root!=NULL)
    {
        prev=root;
        if(key==root->data){
            printf("\nDUPLICATE");
            return; //DUPLICATE
        }
        else if(key<root->data){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
       
    struct Node * new= createNode(key);
    if(key<prev->data){
        prev->left=new;
    }
    else{
        prev->right=new;
    }
}
struct Node * inOrderPredecessor(struct Node *root){
    root=root->left; // Left subtree
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}
//DELETION
struct Node * deleteNode(struct Node * root,int key){
 
 if(root==NULL){
    return NULL;
 }
 if(root->left==NULL && root->right==NULL){
    free(root);
    return NULL; // (FOR LEAF  NODE CASES: TO SET DLETED NODE AS NULL)
 }

 // searching for the node to be deleted
  if(key<root->data){
    root->left=deleteNode(root->left,key);//finding node
  }  
  else if(key>root->data){
    root->right=deleteNode(root->right,key);//finding node
  }
  else{ //___ WHEN THE NODE IS FOUND

    struct Node * ipre= inOrderPredecessor(root);
    root->data=ipre->data; //       In order Predecessor se replace kar
    root->left=deleteNode(root->left,ipre->data); 
    //                    because inorderPredecessor is in left subtree(only left part ,because all rights are loops)
    //                                                                        1        ,    n                        
  }
  return root;
}



//    struct Node* new = createNode(key);
//    if(key<prev->data){
//        prev->left = new;
//    }
//    else{
//        prev->right = new;
//    }
// }
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
    preOrder(p);
    printf("\nPostorder \n");
    postOrder(p);
    printf("\ninorder\n");
    inOrder(p);
    printf("\nIs Binary Tree\n");
    printf("%d\n",isBST(p));
    printf("_______________\nSearching\n");
    struct Node * s= search(p,7);
    if(s!=NULL){
        printf(" Found %d\n",s->data);
    }
    else{
        printf("\nNULL");
    }
    printf("\nINSERTION\n");
    insertNode(p,7);
    
    inOrder(p);
    //printf("\n%d\n",p->right->right->data);
    printf("\n After Deletion\n");
    deleteNode(p,5);
    inOrder(p);
}
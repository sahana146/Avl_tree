//implementation of insertion into balanced tree(AVL)

#include<stdio.h>
#include<stdlib.h>

struct tree                              //structure for the tree node
{

   int ele,height;
   struct tree *left;
   struct tree *right;


};

int max(int a,int b)                    //to find the largest height between height of left and right sub tree
{

if(a>b)return a;
else 
return b;

}

int height(struct tree *node)              //returns the height of tree from the current node
{


if(node==NULL)
  return 0;

return node->height;


}


int bal(struct tree* node)                 // return the balanced value of a particular node
{

if(n=NULL)
return 0;

return (height(node->left)-height(node->right));            //difference between left and right height

}


struct tree* left(struct tree* n)                             // performs left rotation at node n
{

struct tree * temp=n->right;
struct tree *t=temp->left;

temp->left=n;
n->right=t;

n->height=max(height(n->left),height(n->right))+1;
temp->height=max(height(temp->left),height(temp->right))+1;

return temp;
}


struct tree* right(struct tree* n)                            //performs right rotation at node n
{

struct tree * temp=n->left;
struct tree *t=temp->right;

temp->right=n;
n->left=t;

n->height=max(height(n->left),height(n->right))+1;
temp->height=max(height(temp->left),height(temp->right))+1;

return temp;

}


struct tree * insert(struct tree *nn, int a)                // inserts a new node into the tree and balances it
{

struct tree * new=(struct tree*)malloc(sizeof(struct tree));
new->ele=a;
new->right=NULL;
new->left=NULL;
new->height=1;
if(nn==NULL)
   { return new;}
else
 {
 
   if(a<nn->ele)
     nn->left=insert(nn->left,a);
   else if(a>nn->ele)
     nn->right=insert(nn->right,a);
   else
   {return nn;}
}

nn->height=1+max(height(nn->left),height(nn->right));         //updates the height of each node according to the position of the new node 

int b=bal(nn);

if(b>1&&a<nn->left->ele)                              // balanced value > 1 (new node inserted to left subtree)-----perform right rotation
    return right(nn);

if(b<-1&&a>nn->right->ele)                            // balanced value < -1 (new node inserted to left subtree)------ perform left rotation
    return left(nn);

if(b<-1&&a<nn->right->ele)
 {
    nn->right=right(nn);               // balanced value <-1(new node inserted to left subtree of right node)---perform right-left rotation
    return left(nn);
 }

if(b>1&&a>nn->left->ele)
 {
    nn->left=left(nn);                 // balanced value > 1(new node inserted to right subtree of left node)---perform left-right rotation
    return right(nn);
 }

return nn;

}




void inorder(struct tree *root1)      //display the tree using inorder traversal
{

if(root1!=NULL)
 {
    inorder(root1->left);
    printf("%d\t",root1->ele);
    inorder(root1->right);
 }

}



int main()                         //main function
{

struct tree *root=NULL;
root=insert(root,10);
root=insert(root,20);
root=insert(root,30);
root=insert(root,40);
root=insert(root,50);
root=insert(root,25);

inorder(root);                     //inorder traversal

return 0;
}

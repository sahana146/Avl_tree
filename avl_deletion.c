//implementation of (insertion and) deleteion into balanced tree(AVL)

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

if(node==NULL)
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



struct tree * insucc(struct tree * nn)                              //finding the inorder succesor
{
       
   struct tree* curr=nn;
  while(curr->left!=NULL)
  {
         curr=curr->left;

  }

 return curr;
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


//Deleting a node

struct tree * delete(struct tree *nn, int k)
{

 if(nn==NULL)                           //empty tree
  return nn;

 if(k<nn->ele)                          //key value less than current node   value
   nn->left=delete(nn->left,k);

 else if(k>nn->ele)                    //key value greater than current node value
   nn->right=delete(nn->right,k);

 else                                  //key node found
  {
          struct tree *temp;   
         if( (nn->left == NULL) && (nn->right == NULL) )           // No child case 
        { 
            temp = nn; 
            nn = NULL;
            free(temp);
        }
                                    
        else if (nn->left!=NULL)                                 // One child case
        { 
              temp=nn;
              nn=nn->left;
              nn->left=NULL;
              free(temp);   

        } 
         else if (nn->right!=NULL)                                 // One child case
        { 
              temp=nn;
              nn=nn->right;
              nn->left=NULL;
              free(temp);   

        }  
        else
        { 
                                                     // node with two children: Get the inordersuccessor  
            temp = insucc(nn->right); 
  
                                                     // Copy the inorder successor's data to this node 
            nn->ele = temp->ele; 
  
                                                      // Delete the inorder successor 
            nn->right = delete(nn->right, temp->ele); 
        } 

  }
 
 if(nn==NULL)
 return nn;

nn->height=1+max(height(nn->left),height(nn->right));    //updates the height of each node

int b=bal(nn);

if(b>1 && bal(nn->left)>=0)                              // balanced value > 1 perform right rotation
    return right(nn);

if(b<-1 && bal(nn->right)<=0)                            // balanced value < -1  perform left rotation
    return left(nn);

if(b<-1 && bal(nn->right)>0)
 {
    nn->right=right(nn);               // balanced value <-1  perform right-left rotation
    return left(nn);
 }

if(b>1&&bal(nn->left)<0)
 {
    nn->left=left(nn);                 // balanced value > 1 perform left-right rotation
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
int x,op;
struct tree *root=NULL;
while(1)
{
printf("Choose one of the options\n");
printf(" 1.Insert\n 2.Delete\n 3.Display\n 4.Quit\n");
scanf("%d",&op);

if(op==1){
printf("Enter the element to be inserted\n");
scanf("%d",&x);
root=insert(root,x);
}

else if(op==3)
{inorder(root); printf("\n");}

else if(op==2)
{
printf("Enter the element to be deleted\n");
scanf("%d",&x);
root=delete(root,x);
}
else
 break;                     
}

return 0;
}

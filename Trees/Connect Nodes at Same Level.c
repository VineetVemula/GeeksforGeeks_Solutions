

Write a function to connect all the adjacent nodes at the same level in a binary tree. Structure of the given Binary Tree node is like following.
 

struct Node{

  int data;

  Node* left;

  Node* right;

  Node* nextRight; 

}


Initially, all the nextRight pointers point to garbage values. Your function should set these pointers to point next right for each node.

Example:

Input Tree
       10
      / \
     3   5
    / \   \
   4   1   2


Output Tree
       10--->NULL
      / \
     3-->5-->NULL
    / \   \   
   4-->1-->2-->NULL

 

Input:

The task is to complete the method which takes one argument, root of Binary Tree. There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should update nextRight pointers of all nodes.

Constraints:
1 <=T<= 30
1 <=Number of nodes<= 100
1 <=Data of a node<= 1000

Example:
Input:
2
2
3 1 L 3 2 R
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
3 1 2
1 3 2
10 20 30 40 60
40 20 60 10 30

There are two test casess.  First case represents a tree with 3 nodes and 2 edges where root is 3, left child of 3 is 1 and right child of 3 is 2.   Second test case represents a tree with 4 edges and 5 nodes.

The output contains level order and inorder traversals of the modified tree.  Level order traversal is done using nextRight pointers.

--code--

Node* y;
void funct(Node *a[],int *i,int*s)
{
    Node *x,*p;
    int l=0;
    int level[1000];
    level[0]=0;
    while(*s!=*i)
    {
    x=a[(*s)++];
    if(l!=level[(*s)-1])
    {
        l++;
        //printf("$ ");
        y->nextRight=NULL;
    }
    //printf("%d ",x->data);
    else if(y!=NULL)
        y->nextRight=x;
    y=x;
    if(x->left!=NULL && x->right!=NULL)
    {
        level[*i]=l+1;
        a[(*i)++]=x->left;
        level[*i]=l+1;
        a[(*i)++]=x->right;
    }
     if(x->left!=NULL && x->right==NULL)
    {
        level[*i]=l+1;
        a[(*i)++]=x->left;
    }
     if(x->right!=NULL && x->left==NULL)
    {
        level[*i]=l+1;
        a[(*i)++]=x->right;
    }
    
    }
}
void connect(Node *p)
{
    int io=0,j,s=0;
    int *in=&io,*st=&s;
    Node * a[1000];
    a[io]=p;
    io++;
    funct(a,in,st);
    //printf("$");
    y->nextRight=NULL;
}
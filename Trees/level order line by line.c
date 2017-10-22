Given a Binary Tree, your task is to print its level order traversal where each level is separated by $ 

For the below tree the output will be 1 $ 2 3 $ 4 5 6 7 $ 8 $

          1
       /     \
     2        3
   /    \     /   \
  4     5   6    7
    \
     8

            

Input:
The task is to complete the method which takes one argument, root of Binary Tree. The struct Node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should print the level order traversal of the tree as specified in the problem statement .

Constraints:
1 <=T<= 20
1 <= Number of edges<= 1000
1 <= Data of a node<= 100

Example:
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
1 $ 3 2  $
10 $ 20 30 $ 40 60 $

--code--

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
        printf("$ ");
    }
    printf("%d ",x->data);
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
void levelOrder(Node* node)
{
    int io=0,j,s=0;
    int *in=&io,*st=&s;
    Node * a[1000];
    a[io]=node;
    io++;
    funct(a,in,st);
    printf("$");
}

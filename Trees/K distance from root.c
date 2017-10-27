Given a Binary Tree and a number k. Print all nodes that are at distance k from root (root is considered at distance 0 from itself).  Nodes should be printed from left to right.  If k is more that height of tree, nothing should be printed.

For example, if below is given tree and k is 2.  Output should be 4 5 6.

          1
       /     \
     2        3
   /         /   \
  4        5    6 
     \
      8

            

Input:
The task is to complete the method which takes two arguments, root of Binary Tree and k. The struct Node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should print nodes at k distance from root. Nodes should be printed from left to right.

Constraints:
1 <=T<= 30
1 <= Number of nodes<= 100
1 <= Data of a node<= 1000

Example:
Input:
2
2 0
1 2 R 1 3 L
4 2
10 20 L 10 30 R 20 40 L 20 60 R

Output:
1
40 60

--code--

void funct(Node *a[],int *i,int*s,int k)
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
    }
    if(l==k)
        printf("%d ",x->data);
    if(l>k)
        return;
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
void printKdistance(Node *root, int k)
{
    int io=0,j,s=0;
    int *in=&io,*st=&s;
    Node * a[1000];
    a[io]=root;
    io++;
    funct(a,in,st,k);
}

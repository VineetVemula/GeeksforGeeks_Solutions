Level order traversal of a tree is breadth first traversal for the tree.

Example Tree
Example Tree

Level order traversal of the above tree is 1 2 3 4 5

 

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
1 3 2
10 20 30 40 60 

--code--

void funct(Node *a[],int *i,int*s)
{
    Node *x;
    while(*s!=*i)
    {
    x=a[(*s)++];
    if(x->left!=NULL && x->right!=NULL)
    {
        a[(*i)++]=x->left;
        a[(*i)++]=x->right;

    }
     if(x->left!=NULL && x->right==NULL)
    {
        a[(*i)++]=x->left;
    }
     if(x->right!=NULL && x->left==NULL)
    {
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
    for(j=0;j<io;j++)
    {
        printf("%d ",a[j]->data);
    }
    
}

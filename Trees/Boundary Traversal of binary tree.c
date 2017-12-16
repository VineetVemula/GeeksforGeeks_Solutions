Write a function to print Boundary Traversal of a binary tree.
For below tree, function should print 20 8 4 10 14 25 22 .
                                              
                                     
 

Input:
The task is to complete the method which takes one argument, root of the Tree. The struct node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.


Output:
The function should print Boundary  traversal of the tree.

Constraints:
1 <=T<= 30
1 <=Number of nodes<= 100
1 <=Data of a node<= 1000

Example:
Input:
2
2
1 2 R 1 3 L
7
20 8 L 20 22 R 8 4 L 8 12 R 12 10 L 12 14 R 22 25 R

Output:
1 3 2
20 8 4 10 14 25 22 .

There are two test casess.  First case represents a tree with 3 nodes and 2 edges where root is 1, left child of 1 is 3 and right child of 1 is 2.   Second test case represents a tree with 7 edges and 8 nodes.

--code--

void inorder(Node*x)
{
    if(x!=NULL)
    {
        inorder(x->left);
        if(x->left==NULL && x->right==NULL)
        {
            printf("%d ",x->data);
        }
        inorder(x->right);
    }
}
int funct(Node *a[],int *i,int*s,int q[][100],int index[],Node * root)
{
    Node *x,*p;
    int l=0;
    int level[1000],child[100];
    level[0]=0;
    child[0]=1;
    while(*s!=*i)
    {
    x=a[(*s)++];
    if(l!=level[(*s)-1])
    {
        
        if(index[l]==0)
        {
            if(child[(*s)-2]==2)
            {
                q[l][1]=q[l][0];
                q[l][0]=-1;
                index[l]=1;
            }
        }
        l++;
    }
    if(x->left!=NULL || x->right!=NULL)
    {
        index[l]=index[l]+1;
        q[l][index[l]]=x->data;
    }
    else q[l][++index[l]]=-1;
     if(x->left!=NULL)
    {
        level[*i]=l+1;
        if(x==root)
            child[*i]=1;
        else child[*i]=child[(*s)-1];
        a[(*i)++]=x->left;
    }
     if(x->right!=NULL)
    {
        level[*i]=l+1;
        if(x==root)
            child[*i]=2;
        else child[*i]=child[(*s)-1];
        a[(*i)++]=x->right;
    }
    
    }
    return l;
}
void printBoundary(Node *root)
{
    int io=0,j,s=0,q[100][100],index[100],max,i;
    int *in=&io,*st=&s;
    Node * a[1000];
    a[io]=root;
    io++;
    for(i=0;i<100;i++)
    {
        index[i]=-1;
    }
    max=funct(a,in,st,q,index,root);
    printf("%d ",q[0][0]);
    for(i=1;i<max;i++)
    {
        if(q[i][0]!=-1)
            printf("%d ",q[i][0]);
    }
    inorder(root);
    for(i=max-1;i>0;i--)
    {
        if(index[i]!=0 && q[i][index[i]]!=-1)
            printf("%d ",q[i][index[i]]);
    }
}

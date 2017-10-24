Given a binary tree of size N, your task is to complete the function printOddNodes(), that print's the nodes of binary tree present at odd level of the tree.At each level print nodes in any left to right order. Root is considered at level 1.

For example consider the following tree
          1
       /     \
      2       3
    /   \       \
   4     5       6
        /  \     /
       7    8   9

Output  1 4 5 6
Input:
The function takes a single argument as input, the reference pointer to the root of the binary tree.
There will be T testcases and for each test case the function will be called separately.

Output:
For each test case print space separated all the nodes of the tree that are present at odd level starting from level 1.

Constraints:
1<=T<=100
1<=N<=500

Example:
Input:
2
2
1 2 L 1 3 R
5
10 20 L 10 30 R 20 40 L 20 60 R 30 90 L
Output:
1 
10 40 60 90 

--code--

void printOddNodes(Node *root)
{
    int i=0,j,s=0;
    Node * a[1000],*x;
    int l=1;
    int level[1000];
    level[0]=1;
    a[i]=root;
    i++;
    if(root==NULL)
    {
        printf("\n");
        return;
    }
    while(s!=i)
    {
    x=a[(s)++];
    if(l!=level[(s)-1])
    {
        l++;
    }
    if(l%2==1)
        printf("%d ",x->data);
    
     if(x->left!=NULL)
    {
        level[i]=l+1;
        a[(i)++]=x->left;
    }
     if(x->right!=NULL)
    {
        level[i]=l+1;
        a[(i)++]=x->right;
    }
    
    }
    printf("\n");
    
}

alternate code

void funct(Node *a[],int *i,int*s)
{
    Node *x,*p;
    int l=1;
    int level[1000];
    level[0]=1;
    
    while(*s!=*i)
    {
    x=a[(*s)++];
    if(l!=level[(*s)-1])
    {
        l++;
    }
    if(l%2==1)
        printf("%d ",x->data);
    
     if(x->left!=NULL)
    {
        level[*i]=l+1;
        a[(*i)++]=x->left;
    }
     if(x->right!=NULL)
    {
        level[*i]=l+1;
        a[(*i)++]=x->right;
    }
    
    }
    printf("\n");
}

void printOddNodes(Node *root)
{
    int io=0,j,s=0;
    int *in=&io,*st=&s;
    Node * a[1000];
    a[io++]=root;
    if(root==NULL)
    {
        printf("\n");
        return;
    }
    funct(a,in,st);
}

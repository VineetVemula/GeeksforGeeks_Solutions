Given a Binary Tree, print Right view of it. Right view of a Binary Tree is set of nodes visible when tree is visited from Right side.

Right view of following tree is 1 3 7 8

          1
       /     \
     2        3
   /   \      /    \
  4     5   6    7
    \
     8

            

Input:
The task is to complete the method which takes one argument, root of Binary Tree. The struct Node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should print nodes in right view of Binary Tree.

Constraints:
1 <=T<= 30
1 <= Number of nodes<= 100
1 <= Data of a node<= 1000

Example:
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
1 2
10 30 60

--code--

void funct(Node *a[],int b[],int *i,int*s,int * n)
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
        b[(*n)++]=-1;
    }
    //printf("%d ",x->data);
    b[(*n)++]=x->data;
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
void rightView(Node *root)
{
    int io=0,j,s=0,n=0,b[1000],l,k;
    int *in=&io,*st=&s;
    Node * a[1000];
    a[io]=root;
    io++;
    funct(a,b,in,st,&n);
    //printf("$");
    for(l=0,k=1;k<n;k++,l++)
    {
        if(b[k]==-1)
            printf("%d ",b[l]);
    }
    printf("%d",b[n-1]);
}

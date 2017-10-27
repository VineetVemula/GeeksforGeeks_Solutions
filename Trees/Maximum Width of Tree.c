Given a Binary Tree, find the maximum width of it.  Maximum width is maximum number of nodes in any level.  For example, maximum width of following tree is 4 as there are 4 nodes at 3rd level

          1
       /     \
     2        3
   /    \    /    \
  4    5   6    7
    \
      8

            

Input:
The task is to complete the method that takes root of tree as an argument.

There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should return maximum width of tree.

Constraints:
1 <=T<= 30
1 <= Size of arrays <= 100
1 <= Values in arrays <= 1000

Example:
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R
 

Output:
2
2

--code--

int funct(Node *a[],int *i,int*s)
{
    Node *x,*p;
    int l=0,max=0,c=0;
    int level[1000];
    level[0]=0;
    
    while(*s!=*i)
    {
    x=a[(*s)++];
    if(l!=level[(*s)-1])
    {
        l++;
        if (max<c)
            max=c;
        c=0;
        
    }
    c++;
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
    if (max<c)
        max=c;
    return max;
}
int getMaxWidth(Node* root)
{
    int io=0,j,s=0,ans;
    int *in=&io,*st=&s;
    Node * a[1000];
    a[io]=root;
    io++;
    ans=funct(a,in,st);
    return ans;
}

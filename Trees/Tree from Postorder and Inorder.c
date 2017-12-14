Given inorder and postorder traversals of a Binary Tree, construct the tree

For example, if given inorder and postorder traversals are {4, 8, 2, 5, 1, 6, 3, 7} and {8, 4, 5, 2, 6, 7, 3, 1}  respectively, then your function should construct below tree.

          1
       /      \
     2        3
   /    \     /   \
  4     5   6    7
    \
      8

            

Input:
The task is to complete the method which takes three arguments, one is an array that has inorder traversal, second is another array that has postorder traversal, third is size of two arrays (You may assume that both arrays are of same size). 

There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should return root of constructed tree.

Constraints:
1 <=T<= 30
1 <= Size of arrays <= 100
1 <= Values in arrays <= 1000

Example:
Input:
1
8
4 8 2 5 1 6 3 7
8 4 5 2 6 7 3 1
 

Output:
1 2 4 8 5 3 6 7

--code--

int len=-1;
int left(int in[],int post[],int data,int lent,int n)
{
    int i,j,k;
    for(i=0;i<lent;i++)
    {
        if(in[i]==data)
            break;
    }
    for(j=n;j>=0;j--)
    {
        for(k=i-1;k>=0;k--)
        {
            if(in[k]==post[j])
            {
                return j;
            }
        }
    }
    return -1;
}
int right(int in[],int post[],int data,int lent,int n)
{
    int i,j,k;
    for(i=0;i<lent;i++)
    {
        if(in[i]==data)
            break;
    }
    for(j=n;j>=0;j--)
    {
        for(k=i+1;k<len;k++)
        {
            if(in[k]==post[j])
            {
                return j;
            }
        }
    }
    return -1;
}
Node *buildTree(int in[], int post[], int n)
{
    if(n<=0)
        return NULL;
    if(len==-1)
        len=n;
    Node * p=(Node*)malloc(sizeof(Node));
    p->data=post[n-1];
    int l,r;
    l=left(in,post,post[n-1],len,n-2);
    r=right(in,post,post[n-1],len,n-2);
    post[n-1]=-2;
    p->left=buildTree(in,post,l+1);
    p->right=buildTree(in,post,r+1);
    if(n==len)
        len=-1;
    return p;
}

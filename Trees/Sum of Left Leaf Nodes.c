Given a Binary Tree of size N, your task is to complete the function leftLeafSum(), that should return the sum of all the leaf nodes that are left child of their parent of the given binary tree.
Example:

Input : 
         1
        /  \
       2    3
     /  \     \
    4    5     8 
  /  \        /  \
 7    2      6    9
Output :
sum = 6 + 7 = 13
Input:
The function takes a single arguments as input, the reference pointer to the root of the binary tree.
There are T test cases and for each test case the function will be called separately.

Output:
The function should return the sum of all the left leaf nodes of the binary tree.

Constraints:
1<=T<=100
0<=N<=100

Example:
Input:
2
2
1 2 L 1 3 R
5
10 20 L 10 30 R 20 40 L 20 60 R 30 90 L
Output:
2
130

--code--

void in(Node *x,int *m,int status)
{
    if(x!=NULL)
    {
        if(status==0)
        {
            if(x->left==NULL && x->right==NULL)
            {
                *m=*m+x->data;
            }
        }
        in(x->left,m,0);
        in(x->right,m,1);
    }
}
int leftLeafSum(Node* root)
{
    int ans=0;
    in(root,&ans,1);
    return ans;
}

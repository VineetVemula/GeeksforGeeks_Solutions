Given a Binary Tree of size N, your task is to complete the function isSymettric(), that check whether a binary is Symmetric or not, i.e. the binary tree is Mirror image of itself or not.
For example:
The following binary tree is symmetric:

        1
      /   \
    2       2
  /   \   /   \
 3     4 4     3

But the following is not:

       1
     /   \
    2      2
     \      \
      3      3
Input:

The function takes a single argument as input, the root node of the binary tree. There will be T test cases and for each test case the function will be called separately. 
 

Output:
For each testcase the function should return a boolean value.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
1 1
1 2 L 1 2 R 0
2 1
10 20 R 10 20 L 20 30 R 5
2 2
10 20 R 10 20 L 10 20 R 10 20 L 20 30 L 100 

Output:
True
False
True

--code--

void in(Node *x,Node * y,int * res)
{
    if(*res==1)
    {
        if((x==NULL && y!=NULL) || (x!=NULL && y==NULL))
        {
            *res=0;
            return;
        }
        if(x!=NULL && y!=NULL)
        {
            if(x->key!=y->key)
            {
                *res=0;
                return;
            }
            in(x->left,y->right,res);
            in(x->right,y->left,res);
        }
    }
}
bool isSymmetric(struct Node* root)
{
	int result=1;
    in(root->left,root->right,&result);
    if(result==1)
        return true;
    else return false;
}

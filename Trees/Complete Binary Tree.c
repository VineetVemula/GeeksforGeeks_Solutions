Given a Binary Tree, write a function to check whether the given Binary Tree is Complete Binary Tree or not. A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer n denoting the number of edges. The next line contains the edges of the binary tree.
 
Output:
Print "Complete Binary Tree" if the tree is a complete binary tree.
Print "Not Complete Binary Tree" if the tree is not a complete binary tree.

Constraints:
1<=T<=100
1<=n<=100

Example:
Input:
3
2
1 2 L 1 3 R
3
1 2 L 2 4 L 1 3 R
1
1 3 R

Output:
Complete Binary Tree
Complete Binary Tree
Not Complete Binary Tree

--code--

int l=-1,n=0,z=1;
bool isCompleteBT(struct node* root)
{
    bool y,r;
    if(root!=NULL)
    {
        n++;
        if(root->left==NULL && root->right==NULL)
        {
            if(l==-1)
            {
                l=n;
            }
            if(n==l)
            {
                n--;
                return true;
            }
            if(n==l-1 && z==1)
            {
                z=0;
                l--;
                n--;
                return true;
            }
            n--;
            return false;
        }
        if(root->left==NULL && root->right!=NULL)
        {
            n--;
            return false;
        }
        y=isCompleteBT(root->left);
        r=isCompleteBT(root->right);
        n--;
        if(n==0)
        {
            l=-1;
            z=1;
        }
        return(y && r);
    }
    if(n==l-1)
        return true;
    return false;
}

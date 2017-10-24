Given a binary tree, find if it is height balanced or not.  A tree is heigh balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree.    Expected time complexity is O(n).

A height balanced tree
        1
     /     \
   10      39
  /
5

An unbalanced tree
        1
     /    
   10   
  /
5

 

Input:
The task is to complete the method which takes one argument, root of Binary Tree. The struct Node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should return true if tree is height balanced, else false.

Constraints:
1 <=T<= 30
1 <=Number of nodes<= 100
1 <=Data of a node<= 1000

Example:
Input:
2
2
1 2 L 2 3 R
4
10 20 L 10 30 R 20 40 L 20 60 R

--code--

#include<stdlib.h>
int in(Node *x,int* max)
{
    if(x==NULL)
        return 0;
    if(x!=NULL)
    {
        int ls,rs;
        ls=in(x->left,max);
        rs=in(x->right,max);
        if(*max<abs(ls-rs))
            *max=abs(ls-rs);
        if(ls>rs)
            return ls+1;
        else return rs+1;
    }
}
bool isBalanced(Node *root)
{
    int max=0,rls,rrs;
    if(root==NULL)
        return true;
    rls=in(root->left,&max);
    rrs=in(root->right,&max);
    
    if(max<abs(rls-rrs))
        max=abs(rls-rrs);
    if(max>1)
        return false;
    else return true;
    
}

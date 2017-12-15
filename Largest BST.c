Given a binary tree, Your task is to complete the function largestBst that returns the size of the largest subtree which is also a Binary Search Tree (BST). If the complete Binary Tree is BST, then return the size of whole tree.

Input:
The task is to complete the method which takes one argument, root of Binary Tree. The Node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should return the size of the max subtree which is also the BST.

Constraints:
1 <=T<= 30
1 <=Number of nodes<= 100
1 <=Data of a node<= 1000

Example(To be used only for expected output):
Input
2
2
3 2 L 3 4 R
4
10 20 L 10 30 R 20 40 L 20 60 R

Output
3
1

--code--

int in(Node * x,int * n,int * maxl,int * minr)
{
    if(x!=NULL)
    {
        int m=0,p=0,c1,c2,ml1,mr1,ml2,mr2;
        c1=in(x->left,&m,&ml1,&mr1);
        c2=in(x->right,&p,&ml2,&mr2);
        if(m==1 && p==1)
        {
            if(x->left!=NULL && x->right!=NULL && x->data>x->left->data && x->data<x->right->data && x->data>mr1 && x->data<ml2)
            {
                *n=1;
                *maxl=mr1>mr2?mr1:mr2;
                *minr=ml1>ml2?ml1:ml2;
                return (c1+c2+1);
            }
            else if(x->left!=NULL && x->right==NULL && x->data>x->left->data && x->data>mr1)
            {
                *n=1;
                *maxl=ml1;
                *minr=x->data;
                return(c1+c2+1);
            }
            else if(x->right!=NULL && x->left==NULL  && x->data<x->right->data && x->data<ml2)
            {
                *n=1;
                *maxl=x->data;
                *minr=mr2;
                return (c1+c2+1);
            }
            else if(x->right==NULL && x->left==NULL)
            {
                *n=1;
                *maxl=x->data;
                *minr=x->data;
                return (c1+c2+1);
            }
            else
            {
                *n=0;
                return(c1>c2?c1:c2);
            }
        }
        else
        {
            *n=0;
            return(c1>c2?c1:c2);
        }
        
    }
    else 
    {
        *n=1;
        return 0;
    }
}
int largestBst(Node *root)
{
    int c,u,m,n;
    c=in(root,&u,&m,&n);
    return c;
}

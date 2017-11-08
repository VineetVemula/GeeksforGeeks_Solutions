Write a function to detect if two trees are isomorphic. Two trees are called isomorphic if one of them can be obtained from other by a series of flips, i.e. by swapping left and right children of a number of nodes. Any number of nodes at any level can have their children swapped. Two empty trees are isomorphic.

Input:
First line consists of T test cases. First line of every test case consists of N, denoting number of Node in tree. Second and third line of every test case consists of N, nodes of binary tree.

Output:
Single line output, return the boolean value true if "Yes" else "No".

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
3
1 2 L 1 3 R 2 4 L
1 3 L 1 2 R 3 4 R
3
1 2 L 1 3 R 2 4 L
1 3 L 1 2 R 2 4 R
Output:
No
Yes

--code--

void flip(Node * z)
{
    if(z!=NULL)
    {
        Node * temp;
        temp=z->left;
        z->left=z->right;
        z->right=temp;
        temp=NULL;
        flip(z->left);
        flip(z->right);
    }
}
void in(Node *x,Node *y,int * res)
{
    Node *temp;
    if(x!=NULL && y!=NULL && *res==1)
    {
        if(x->data!=y->data)
            *res=0;
        if(x->left!=NULL && x->right!=NULL && y->left!=NULL && y->right!=NULL)
        {
            if(x->left->data==y->right->data && x->right->data==y->left->data)
            {
                flip(y);
            }
            
        }
        else if(x->left!=NULL && x->right==NULL && y->left==NULL && y->right!=NULL)
        {
            if(x->left->data==y->right->data)
            {
                flip(y);
            }
        }
        else if(x->left==NULL && x->right!=NULL && y->left!=NULL && y->right==NULL)
        {
            if(x->right->data==y->left->data)
            {
                flip(y);
            }
        }
        in(x->left,y->left,res);
        in(x->right,y->right,res);
    }
    else if(x==NULL && y==NULL)
    {
        
    }
    else *res=0;
    temp=NULL;
}
bool isIsomorphic(Node *root1,Node *root2)
{
    int res=1;
    in(root1,root2,&res);
    if(res==1)
        return true;
    else return false;
}

Two of the nodes of a Binary Search Tree (BST) are swapped. Fix (or correct) the BST.

Input:

First line consists of T test cases. First line of every test case consists of N, denoting number of elements in BST. Second line of every test case consists 3*N elements 2 integers and a character.

Note: It is guaranteed than the given input will form BST ,except for 2 nodes that will be wrong.

Output:
Return the fixed BST.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
1
4
10 5 L 10 8 R  5 2 L 5 20 R 
Output:
1

--code--

void in(struct node* x,struct node** f, struct node **s,int low,int up)
{
    if(*s==NULL && x!=NULL)
    {
        if(x->data<low || x->data>up)
        {
            if(*f==NULL)
                *f=x;
            else *s=x;
        }
        in(x->left,f,s,low,x->data);
        in(x->right,f,s,x->data,up);
    }
}
struct node *correctBST( struct node* root )
{
    int temp;
    struct node * fir=NULL,* sec=NULL;
    struct node** fi=&fir,**se=&sec;
    in(root,fi,se,-1,9999);
    temp=fir->data;
    fir->data=sec->data;
    sec->data=temp;
    return root;
}

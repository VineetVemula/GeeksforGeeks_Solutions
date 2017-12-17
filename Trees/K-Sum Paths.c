A binary tree and a number k are given. Print the count of every path in the tree with sum of the nodes in the path as k.

Input:
First line consists of T test cases. First line of every test case consists of N, denoting the number of Node is Binary tree. Second line consists of N spaced 3 elements denoting the Parent node, Child Node and a character denoting left or right child. Third line of every test case consists of a integer K.

Output:
Return the Count of number of paths in tree.

Constraints:
1<=T<=20
1<=N<=100

Example:
Input:
1
4
1 3 L 3 2 L 3 -1 R -1 1 R
4
Output:
2

--code--

void in(Node * x,int *c,int sum,int k)
{
    if(x!=NULL)
    {
        sum=sum+x->data;
        if(sum==k)
            (*c)++;
        in(x->left,c,sum,k);
        in(x->right,c,sum,k);
    }
}
int printCount(Node *root,int k)
{
    if(root!=NULL)
    {
        int c=0,c1,c2;
        in(root,&c,0,k);
        c1=printCount(root->left,k);
        c2=printCount(root->right,k);
        return(c+c1+c2);
    }
    else return 0;
}

Given a binary tree of size  N, a node and a positive integer K., your task is to complete the function kthAncestor(), the function should return the Kth ancestor of the given node in the binary tree. If there does not exist any such ancestor then return -1.
Example:



Input:
     K = 2
     Node = 4 
Output: 1
Since, K is 2 and node is 4, so we
first need to locate the node and
look k times its ancestors.
Here in this Case node 4 has 1 as his
2nd Ancestor aka the Root of the tree.
Input:
The function takes three arguments as input, first the reference pointer to the root of the binary tree, second an integer variable K denoting the kth ancestor and last the integer variable Node, denoting the node whose ancestor is to be located.
There will be T, test cases and for each test case the function will be called separately.

Output:
For each test the function should return the Kth ancestor of the given Node form the binary tree.

Constraints:
1<=T<=500
1<=N<=103

Example:
Input:
2 
2 
1 2 L 1 3 R 
1 3
4
1 2 L 1 3 R 2 4 L 2 5 R
2 4
Output:
1
1

--code--

int fa(Node *x,int q[],int *no,int nod,int *ans,int k)
{
    if(x!=NULL && *ans==-2)
    {
        int i;
        q[(*no)++]=x->data;
        if(x->data==nod)
        {
            i=(*no)-1-k;
            if(i<0)
                *ans=-1;
            else *ans=q[i];
        }
        fa(x->left,q,no,nod,ans,k);
        fa(x->right,q,no,nod,ans,k);
        (*no)--;
    }
}
int kthAncestor(Node *root, int k, int node)
{
    int q[1000],no=0,ances=-2,nod=node;
    int *ans;
    if(k==0)
        return -1;
    ans=&ances;
    fa(root,q,&no,nod,ans,k);
    return ances;
}

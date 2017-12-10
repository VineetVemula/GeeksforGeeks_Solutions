Given a Binary Search Tree and a target sum, write a function that returns true if there is a pair with sum equals to target sum, otherwise return false.

Input:
First line consists of T test cases. First line of every test case consists of N and target, denoting the number of elements in bst and target sum. Second line consists of elements of BST.

Output:
Return True if target sum pair is found else False.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
7 10
1 2 3 4 5 6 7
7 33
15 10 20 8 12 16 25  
Output:
1
1

--code--

bool ans=false,con=true;
void in(struct node *x,int c,struct node *a)
{
    if(x!=NULL && ans==false && con==true)
    {
        in(x->left,c,a);
        if(x->val==c && x!=a)
            ans=true;
        if(x->val>c && x!=a)
            con=false;
        in(x->right,c,a);
    }
}
void out(struct node *v,struct node*root,int tar)
{
    if(v!=NULL && ans==false)
    {
        out(v->left,root,tar);
        if(v->val<tar)
        {
            con=true;
            in(root,tar-(v->val),v);
        }
        out(v->right,root,tar);
    }
}
bool isPairPresent(struct node *root, int target)
{
    out(root,root,target);
    if(ans==true)
    {
        ans=false;
        return true;
    }
    else return ans;
}

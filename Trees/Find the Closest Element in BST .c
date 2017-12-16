Given a binary search tree and a target node K. The task is to complete the function which returns an integer denoting the node having minimum absolute difference with given target value K.

Example



For above binary search tree
Input  :  k = 4
Output :  4

Input  :  k = 18
Output :  17

Input  :  k = 12
Output :  9


Input:
The first line of the input contains an integer 'T' denoting the number of test cases. Then 'T' test cases follow. Each test case consists of three lines. First line of each test case contains an integer N denoting the no of nodes of the BST . Second line of each test case consists of 'N' space separated integers denoting the elements of the BST. These elements are inserted into BST in the given order.The last line of each test case contains an integer k as specified in problem statement.

Output:
The output for each test case will be the value of the node with minimum absolute difference with given target value K.
 

Constraints:
1<=T<=100
1<=N<=200
 

Example(To be used only for expected output):
Input:
2
9
9 4 3 6 5 7 17 22 20
18
9
9 4 3 6 5 7 17 22 20
4   
Output:
17
4

--code--

void in(Node * x,Node ** v,int * diff,int k)
{
    if(x!=NULL && *diff!=0)
    {
        if(abs(x->data-k)<*diff)
        {
            *v=x;
            *diff=abs(x->data-k);
        }
        if(x->data>k)
            in(x->left,v,diff,k);
        else in(x->right,v,diff,k);
    }
}
int maxDiff(Node *root, int k)
{
    int dif=9999;
    Node *v=NULL;
    in(root,&v,&dif,k);
    return v->data;
}

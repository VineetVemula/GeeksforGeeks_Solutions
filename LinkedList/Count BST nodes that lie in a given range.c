Given a Binary Search Tree (BST) and a range, count the number of nodes in the BST that lie in the given range. You are required to complete the function getCountOfNode. You should not read any input from stdin/console. There are multiple test cases. For each test case, this method will be called individually.
 

Input (only to be used for Expected Output):
The first line of the input contains an integer 'T' denoting the nummber of test cases. Then 'T' test cases follow. Each test case consists of three lines. Description of  test cases is as follows:
The First line of each test case contains an integer 'N' which denotes the no of nodes in the BST.   .
The Second line of each test case contains 'N' space separated values of the nodes in the BST.
The Third line of each test case contains two space separated integers 'l' and 'h' denoting the range, where l < h

Output:
You are required to complete the function getCountOfNode which takes three arguments. The first being the root of the tree, and then two integers l and h, denoting the range. The function returns an integer denoting the no of nodes in the given range.

Constraints:
1 <= T <= 50
1 <= N <= 50
1 <= l < h < 1000

Example:
Input
1
6
10 5 50 1 40 100
5 45

Output
3

--code--

void in(Node *x,int l,int h,int* c)
{
    if(x!=NULL)
    {
        if(x->data<=h && x->data>=l)
            (*c)++;
        if(x->data>=l)
            in(x->left,l,h,c);
        if(x->data<=h)
            in(x->right,l,h,c);
    }
}
int getCountOfNode(Node *root, int l, int h)
{
    int c=0;
    in(root,l,h,&c);
    return c;
}

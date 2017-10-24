Given a Binary Tree of size N, your task is to complete the function sumBt(), that should return the sum of all the nodes of the given binary tree.

Input:
The function takes a single arguments as input, the reference pointer to the root of the binary tree.
There are T test cases and for each test case the function will be called separately.

Output:
The function should return the sum of all the nodes of the binary tree.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
2
1 2 L 1 3 R
5
10 20 L 10 30 R 20 40 L 20 60 R 30 90 L
Output:
6
250

--code--

void in(Node *x,long int *sum)
{
    if(x!=NULL)
    {
        *sum=*sum+x->key;
        in(x->left,sum);
        in(x->right,sum);
    }
}
long int sumBT(Node* root)
{
    long int sum=0;
    in(root,&sum);
    return sum;
}

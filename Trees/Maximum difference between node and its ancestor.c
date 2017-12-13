Given a Binary Tree you need to  find maximum value which you  can get by subtracting value of node B from value of node A, where A and B are two nodes of the binary tree and A is an ancestor of B . You are required to complete the function maxDiff . You should not read any input from stdin/console. There are multiple test cases. For each test case, this method will be called individually.

Input:
The task is to complete the function maxDiff which takes 1 argument, root of the Tree . The struct node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should return an integer denoting the maximum difference.

Constraints:
1 <=T<= 30
1 <=Number of nodes<= 100
1 <=Data of a node<= 1000

Example
Input
1
2
5 2 L 5 1 R

Output
4

                5
           /    \
         2      1
In above example there is one test case which represents a  tree with 3 nodes and 2 edges where root is 5, left child of 5 is 2 and right child of 5 is 1 hence the max difference we can get is from 5 and 1 ie 4 .

--code--

int m;
void in (Node * x,int * min)
{
    if(x!=NULL)
    {
    in(x->left,min);
    if(x->data<*min)
        *min=x->data;
    in(x->right,min);
    }
}
void out(Node * v,int * dif)
{
    if(v!=NULL)
    {
    out(v->left,dif);
    m=9999;
    in(v->left,&m);
    if(*dif<(v->data-m))
        *dif=v->data-m;
    in(v->right,&m);
    if(*dif<(v->data-m))
        *dif=v->data-m;
    out(v->right,dif);
    }
}
int maxDiff(Node* root)
{
    int diff=-9999;
    out(root,&diff);
    return diff;
}

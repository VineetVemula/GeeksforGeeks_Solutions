Given a BST,  and a reference to a Node x the task is to find the Inorder Successor of the node . 

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow.  The second line consist of an integer N. Then in the next line are N space separated values of the BST nodes. In the next line is an integer x representing the value of the node in the BST.

Output:
For each test case output will be the Inorder successor of the given node. If no such successor is present output will be -1.

Constraints:
1<=T<=100
1<=N<1100
1<=A[]<=1000

Example:
Input:
2
7
20 8 22 4 12 10 14
8
7
20 8 22 4 12 10 14
10
Output:
10
12

--code--

void in(Node * v,Node *x,Node **p,int* a)
{
    if(v!=NULL && *p==NULL)
    {
        in(v->left,x,p,a);
        if(*a==1 && *p==NULL)
            *p=v;
        if(v==x)
            *a=1;
        in(v->right,x,p,a);
    }
}
Node * inOrderSuccessor(Node *root, Node *x)
{
    Node * p=NULL;
    int a=0;
    in(root,x,&p,&a);
    return p;
}

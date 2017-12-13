Given 2 Arrays of Inorder and preorder traversal. Construct a tree and print the Postorder traversal. 

Input:
First line consists of T test cases. First line of every test case consists of N , denoting the number of elements in array. Second and Third line of every test case consists of Inorder and preOrder traversal of a tree.

Output:
Single line output, return the Node of the tree.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
1
7
3 1 4 0 5 2 6 
0 1 3 4 2 5 6 
Output:
3 4 1 5 6 2 0

--code--

int n=-1;
int search(int in[],int pre[], int inStrt, int inEnd,int* index)
{
    int i,j;
    for(i=0;i<=n;i++)
    {
        for(j=inStrt;j<=inEnd;j++)
        {
            if(pre[i]==in[j])
            {
                *index=j;
                return pre[i];
            }
        }
    }
    return -1;
}
Node* buildTree(int in[],int pre[], int inStrt, int inEnd)
{
    if(inStrt==0 && n<inEnd)
        n=inEnd;
    if(inStrt>inEnd)
    {
        return NULL;
    }
    Node *p=(Node*)malloc(sizeof(Node));
    int index1;
    p->data=search(in,pre,inStrt,inEnd,&index1);
    p->left=buildTree(in,pre,inStrt,index1-1);
    p->right=buildTree(in,pre,index1+1,inEnd);
    return p;
}

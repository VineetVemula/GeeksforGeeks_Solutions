Given root of binary search tree and K as input, find K-th smallest element in BST. Your task is to return the K-th smallest element in BST from the function k_smallest_element().

Note: The Time Complexity will be O(h) where h is the height of the Tree.

Input:
The first line of input will contain the number of test cases T. Then T test cases follow. First line of every test case will be n, denoting the number of nodes in the BST. Second line of every test case will be n spaced integers denoting the Integer value of Nodes in BST. Third line of every test case will be k, denoting kth the smallest number.

Output:
For each test case, output will be the kth smallest element of BST.

Constraints:
1<=T<=100
1<=N<=100
1<=K<=N


Example(To be used only for expected output):
Input:
1
5
20 8 4 22 12
3 
Output:
12

--code--

void in(Node * v,Node **p,int* a,int k)
{
    if(v!=NULL && *p==NULL)
    {
        in(v->left,p,a,k);
        (*a)++;
        if(*a==k)
            *p=v;
        in(v->right,p,a,k);
    }
}
int KthSmallestElement(Node *root, int k)
{
    Node * p=NULL;
    int a=0;
    in(root,&p,&a,k);
    //printf("%d ",p->data);
    return p->data;
}

Given a Binary Tree, print the diagnol traversal of the binary tree.

Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.

Input : Root of below tree
unnamed

Output : 
Diagonal Traversal of binary tree : 
 8 10 14 3 6 7 13 1 4


Input:
The task is to complete the method which takes 1 argument, root of Binary Tree. The struct Node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should print out the diagonal traversal of the binary tree.

Constraints:
1 <=T<= 30
1 <= Number of nodes<= 100
1 <= Data of a node<= 1000

Example:

Input
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output
1 2 3
10 30 20 60 40

--code--

void in(Node * x,int q[][100],int index[],int l)
{
    if(x!=NULL)
    {
        in(x->left,q,index,l+1);
        q[l][index[l]++]=x->data;
        in(x->right,q,index,l);
    }
}
void diagonalPrint(Node *root)
{
    int q[100][100],i,j,index[100];
    for(i=0;i<100;i++)
    {
        for(j=0;j<100;j++)
        {
            q[i][j]=-1;
        }
        index[i]=0;
    }
    in(root,q,index,0);
    for(i=0;q[i][0]!=-1;i++)
    {
        for(j=0;j<index[i];j++)
        {
            printf("%d ",q[i][j]);
        }
    }
}

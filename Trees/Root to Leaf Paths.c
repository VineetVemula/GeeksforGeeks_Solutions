Given a Binary Tree of size N, your task is to complete the function printPaths() that prints all the possible paths from root node to the all the leaf node's of the binary tree.

       1
    /     \
   2       3
  /  \    / \
 4    5  6   7
All possible paths:
1->2->4
1->2->5
1->3->6
1->3->7


Input:
The function takes a single argument as input, the reference pointer to the root of the binary tree. There will be multiple test cases (T) and for each test case the function will be called seperately.

Output:
The function should print all possible paths from root node to leaf node. The paths should start from root to leftmost leaf node and then should move towards right of the tree. After every path append a '#' symbol to the path. 

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
1 3 #1 2 #
10 20 40 #10 20 60 #10 30 #

--code--

int arr[1000];
int n=0;
void printPaths(Node* root)
{
    if(root!=NULL)
    {
    arr[n++]=root->data;
    if(root->left==NULL && root->right==NULL)
    {
        int i=0;
        for(i=0;i<n;i++)
        {
            printf("%d ",arr[i]);
        }
        printf("#");
    }
    printPaths(root->left);
    printPaths(root->right);
    n--;
    }
    if(n==0)
        printf("\n");
}

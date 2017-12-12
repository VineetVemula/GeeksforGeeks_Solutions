Given a Binary Search Tree and 2 nodes value n1 and n2  , your task is to find the lowest common ancestor of the two nodes . You are required to complete the function LCA . You should not read any input from stdin/console. There are multiple test cases. For each test case, this method will be called individually.

Input:
The task is to complete the method LCA which takes 3 arguments, root of the Tree and two nodes value  n1 and n2 . The struct node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should return the node which is the least common ancestor of the two nodes n1 and n2 .

Constraints:
1 <=T<= 100
1 <=Number of nodes<= 100
1 <=Data of a node<= 1000

Example:

Input
1
6
5 4 6 3 7 8
7 8

Output 
7

Explanation 
The BST in above test case will look like

    5
   /  \ 
  4  6
 /      \
3        7
            \ 
             8
here the LCA of 7 and 8 is 7 .

--code--

Node* LCA(Node *root, int n1, int n2)
{
    Node * y=root;
    while((y->data<n1 && y->data<n2) ||(y->data>n1 && y->data>n2))
    {
        while(y->right!=NULL && y->data<n1 && y->data<n2)
        {
            y=y->right;
        }
        while(y->left!=NULL && y->data>n1 && y->data>n2)
        {
            y=y->left;
        }
    }
    return y;
}

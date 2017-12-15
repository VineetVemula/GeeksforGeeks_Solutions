Given a Binary Tree where each node has positive and negative values. Convert this to a tree where each node contains the sum of the left and right sub trees in the original tree. The values of leaf nodes are changed to 0.

For example, the following tree

             10
          /      \
        -2        6
       /   \     /  \
     8     -4   7    5

should be changed to

       20(4-2+12+6)
          /              \
     4(8-4)      12(7+5)
       /   \           /  \
     0      0       0    0

 

Input:

The task is to complete the method which takes one argument, root of Binary Tree. There are multiple test cases. For each test case, this method will be called individually.

Output:
The function convert the passed tree to its sum tree.  

Constraints:
1 <=T<= 30
1 <=Number of nodes<= 100
1 <=Data of a node<= 1000

Example:
Input:
2
2
3 1 L 3 2 R
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:

0 3 0
0 100 0 150 0 

--code--

void toSumTree(Node *node)
{
    if(node!=NULL)
    {
        if(node->left!=NULL && node->right!=NULL)
            node->data=node->left->data+node->right->data;
        else if(node->left!=NULL)
            node->data=node->left->data;
        else if(node->right!=NULL)
            node->data=node->right->data;
        toSumTree(node->left);
        toSumTree(node->right);
        if(node->left!=NULL && node->right!=NULL)
            node->data=node->left->data+node->right->data+node->data;
        else if(node->left!=NULL)
            node->data=node->left->data+node->data;
        else if(node->right!=NULL)
            node->data=node->right->data+node->data;
        else if(node->left==NULL && node->right==NULL)
        {
            node->data=0;
        }
    }
}

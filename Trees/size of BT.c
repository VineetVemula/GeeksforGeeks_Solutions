Given a binary tree, count number of nodes in it. For example, count of node in below tree is 4.

        1
     /      \
   10      39
  /
5

Input:
The task is to complete the method which takes one argument, root of Binary Tree. The struct Node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should return count of nodes in tree.

Constraints:
1 <=T<= 30
1 <=Number of nodes<= 100
1 <=Data of a node<= 1000

Example:
Input:
2
2
1 2 L 1 3 R
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
3
5

--code--

void inorder(Node* x,int *c)
{
    (*c)++;
    if(x->left!=NULL && x->right!=NULL)
    {
        inorder(x->left,c);
        inorder(x->right,c);
    }
}
int getSize(Node* node)
{
   int size=0;
   int *s;
   s=&size;
   inorder(node,s);
   return size;
}

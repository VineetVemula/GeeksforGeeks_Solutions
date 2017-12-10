Given a binary tree, your task is to complete the function binaryTreeToBST which converts the binary tree to binary search tree(BST) and returns the root of the converted binary search tree.
Note : The conversion must be done in such a way that keeps the original structure of Binary Tree.

          1
       /    \
     2       3
   /        
4       

For the tree above the converted tree will be

        3
      /   \
    2     4
  /
1

Input:

The task is to complete the method which takes one argument, root of Binary Tree and returns the root of the new converted binary search tree.There are multiple test cases. For each test case, this method will be called individually.

Output:
The output will be the inorder traversal of the the converted  binary search tree .

Constraints:
1 <=T<= 30
1 <= Number of nodes<= 20
 

Example(To be used only for expected output):
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
1 2 3
10 20 30 40 60

--code--

int temp=0;
Node *yy=NULL;
void in(Node* x,Node ** y)
{
    if(x!=NULL)
    {
        in(x->left,y);
        if(*y!=NULL && (*y)->data>x->data)
        {
            temp=(*y)->data;
            (*y)->data=x->data;
            x->data=temp;
            //printf("x%d y%d ",x->data,(*y)->data);
        }
        *y=x;
        in(x->right,y);
    }
}
void out(Node* root,Node *yz)
{
    if(yz!=NULL)
    {
        out(root,yz->left);
        yy=NULL;
        in(root,&yy);
        out(root,yz->right);
    }
}
Node *binaryTreeToBST (Node *root)
{
    out(root,root);
    return root;
}

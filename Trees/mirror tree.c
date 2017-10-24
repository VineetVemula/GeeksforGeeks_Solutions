Given a Binary Tree, convert it into its mirror.


MirrorTree1            

Input:
The task is to complete the method that takes one argument, root of Binary Tree and modifies the tree.

Output:
The function should conert the tree to its mirror

Constraints:
1 <=T<= 75
1 <= Number of nodes<= 100
1 <= Data of a node<= 1000

Example:
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
2 1 3
30 10 60 20 40

--code--

void mirror(Node* node) 
{
    if(node!=NULL)
    {
        Node * temp;
        temp=node->left;
        node->left=node->right;
        node->right=temp;
        mirror(node->left);
        mirror(node->right);
    }
}

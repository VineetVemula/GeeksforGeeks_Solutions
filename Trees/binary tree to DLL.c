Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be same as Inorder of the given Binary Tree. The first node of Inorder traversal (left most node in BT) must be head node of the DLL.

TreeToList

Input:
The task is to complete the method which takes two arguments, root of Binary Tree and reference to head of DLL.

The struct Node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should change reference of head to head of linked list. 

Constraints:
1 <=T<= 30
1 <=Number of nodes<= 100
1 <=Data of a node<= 1000

Example:
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:

3 1 2 
2 1 3 
40 20 60 10 30 
30 10 60 20 40 

--code--

void btdll(Node *x)
{
    Node * tleft,*tright,*rm,*lm;
    if(x!=NULL && (x->left!=NULL || x->right!=NULL))
    {
        tleft=x->left;
        tright=x->right;
        for(rm=x->left;rm!=NULL && rm->right!=NULL;rm=rm->right)
        {
            
        }
        x->left=rm;
        for(lm=x->right;lm!=NULL && lm->left!=NULL;lm=lm->left)
        {
            
        }
        x->right=lm;
        btdll(tleft);
        btdll(tright);
        x->left->right=x;
        x->right->left=x;
    }
}

void BToDLL(Node *root, Node **head_ref)
{
    *head_ref=root;
    while((*head_ref)->left!=NULL)
    {
        (*head_ref)=(*head_ref)->left;
    }
    btdll(root);
}

Given a Binary Tree, extract all leaves of it in a Doubly Linked List (DLL). Note that the DLL need to be created in-place. Assume that the node structure of DLL and Binary Tree is same, only the meaning of left and right pointers are different. In DLL, left means previous pointer and right means next pointer. Head of DLL should point to the left most leaf and than in inorder traversal and so on.

Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.

Input:
The task is to complete the method which takes two arguments, root of Binary Tree and reference to head of DLL.
The struct Node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.

Output:
In the function make changes in Head.

Constraints:
1<=T<=100
1<=N<=10000

Example:
Input:
2
2
1 2 L 1 3 R
3
1 2 L 1 3 R 2 4 L
Output:
2 3
3 2 
4 3
3 4 

--CODE--

void in(Node *r,Node **p)
{
    //Node *q;
    if(r!=NULL)
    {
        in(r->left,p);
        in(r->right,p);
        if(r->left==NULL && r->right==NULL)
        {
            (*p)->data=r->data;
            Node *q=(Node*)malloc(sizeof(Node));
            q->left=*p;
            (*p)->right=q;
            *p=(*p)->right;
            (*p)->right=NULL;
            q=NULL;
        }
        
    }
}
Node *convertToDLL(Node *root,Node **head_ref)
{
    Node**p;
    *head_ref=(Node*)malloc(sizeof(Node));
    *p=*head_ref;
    (*p)->left=NULL;
    in(root,p);
    *p=(*p)->left;
    (*p)->right=NULL;
    return *head_ref;
}

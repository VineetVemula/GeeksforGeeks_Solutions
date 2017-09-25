Given a Binary Tree (BT), convert it to a Circular Doubly Linked List(DLL) In-Place. The left and right pointers in nodes are to be used as previous and next pointers respectively in converted CDLL. The order of nodes in CDLL must be same as Inorder of the given Binary Tree. The first node of Inorder traversal (left most node in BT) must be head node of the CDLL.

Input:
The task is to complete the method which takes a arguments, root of Binary Tree.
The struct Node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should return the head of CDLL.

Constraints:
1 <=T<= 100
1 <=Number of nodes<= 100
1 <=Data of a node<= 100

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

--CODE--

void inorder(Node* x,Node **l,Node** head)
{
    if(x!=NULL)
    {
        inorder(x->left,l,head);
        if(*head==NULL)
        {
            Node*p;
            p=(Node*)malloc(sizeof(Node));
            p->data=x->data;
            p->left=NULL;
            p->right=NULL;
            *head=p;
            *l=p;
            p=NULL;
        }
        else
        {
            Node *p;
            p=(Node*)malloc(sizeof(Node));
            p->data=x->data;
            p->left=*l;
            (*l)->right=p;
            p->right=NULL;
            *l=p;
            p=NULL;
        }
        inorder(x->right,l,head);
    }
    
}
Node *bTreeToCList(Node *root)
{
    Node *head,*l;
    Node **lol,**h;
    head=NULL;
    l=NULL;
    lol=&l;
    h=&head;
    inorder(root,lol,h);
    l->right=head;
    head->left=l;
    return head;
}

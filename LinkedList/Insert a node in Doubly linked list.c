Insert a node in Doubly linked list (Function Problem)
Show Topic Tags     
Given a doubly linked list, a position p and an integer x your task  is to add a new node with value x at position just after pth node in the doubly linked list .
In this function problem, the function addNode() takes three argument: Address of the head of the linked list,  the position p and integer x  where the node is to be added . 
There are multiple test cases. For each test case, this function will be called individually.

Note: The first node is considered as node no 0.

Example

Input:
The first line contains an integer 'T' denoting the number of test cases. Then 'T' test cases follow. Each test case consists of 3 lines. First line of each test case contains an integer N denoting the size of the linked list. Second line of each test case consists of 'N' space separated integers denoting the elements of the linked list.The third line contains two integers p and x
 

Output:
Prints the nodes of the linked list .

Constraints:
1<=T<=200
1<=N<=200

Example:
Input:
2
3
2 4 5
2 6
4
1 2 3 4
0 44

Output:
2 4 5 6
1 44 2 3 4

--CODE--

void addNode(struct Node **head_ref,int pos,int data)
{
    struct Node *p,*q;
    p=*head_ref;
    if(p==NULL)
    {
        q=(Node*)malloc(sizeof(Node));
        q->data=data;
        *head_ref=q;
        q=NULL;
        return;
    }
    while(pos>0)
    {
        p=p->next;
        pos--;
    }
    q=(Node*)malloc(sizeof(Node));
    q->data=data;
    q->next=p->next;
    q->prev=p;
    if(p->next!=NULL)
        p->next->prev=q;
    p->next=q;
    q=NULL;
}

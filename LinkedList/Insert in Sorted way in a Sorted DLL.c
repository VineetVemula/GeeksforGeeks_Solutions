Given a sorted doubly linked list and an element X, your task is to complete the function sortedInsert(), that insert's the value in Doubly linked list in sorted way.

Example:
Initial doubly linked list:


Doubly Linked List after insertion of 9:


Input:
The function takes two arguments as input, reference pointer to the head of the doubly linked list and an element X.
There will be T test cases and for each test case the function will be called separately.

Output:
For each test print the space separated vales of the doubly linked list.

Constraints:
1<=T<=100
0<=N<=1000

Example:
Input:
2
5
1 9 16 25 78
2
3
1 2 3
5
Output:
1 2 9 16 25 78
1 2 3 5

--CODE--

void sortedInsert(struct Node** head_ref, struct Node* newNode)
{
    Node*p,*q;
    p=*head_ref;
    if(*head_ref==NULL)
    {
        *head_ref=newNode;
        newNode->next=NULL;
        newNode->prev=NULL;
        return;
    }
    while(p!=NULL)
    {
        if(p->data>newNode->data)
        {
            newNode->prev=p->prev;
            newNode->next=p;
            if(p->prev!=NULL)
                p->prev->next=newNode;
            p->prev=newNode;
            if(p==*head_ref)
            {
                *head_ref=newNode;
            }
            return;
        }
        if(p->next==NULL)
            q=p;
        p=p->next;
        if(p==NULL)
        {
            q->next=newNode;
            newNode->prev=q;
            newNode->next=NULL;
            return;
        }
    }
}

Given a Circular Linked List of size N, your task is to delete the given node (excluding the first and last node) in circular linked list and then print the reverse of the circular linked list.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer n denoting the size of the circular linked list. The next line contains n space separated integers forming the circular linked list. The last line contains the node to be deleted in between the circular linked list.

Output:
Print the reverse of the circular linked list with the deleted node.

Constraints:
1<=T<=100
1<=n<=100
1<=data<=100

Example:
Input:
2
5
2 5 7 8 10
8
4
1 7 8 10
8

Output:
10 7 5 2 
10 7 1

--CODE--

void deleteNode(struct Node *head, int key)
{
    Node* p,*r;
    p=head->next;
    r=head;
    while(p!=head)
    {
        if(p->data==key)
        {
           r->next=p->next;
           break;
        }
        r=r->next;
        p=p->next;
    }
}
/* Function to reverse the linked list */
static void reverse(struct Node** head_ref)
{
    Node *r,*p,*q;
    r=*head_ref;
    p=r->next;
    q=p->next;
    while(1)
    {
        p->next=r;
        r=p;
        if(r==*head_ref)
            break;
        p=q;
        q=q->next;
    }
    *head_ref=(*head_ref)->next;
}

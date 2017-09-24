Given a Cirular Linked List split it into two halves circular lists. If there are odd number of nodes in the given circular linked list then out of the resulting two halved lists, first list should have one node more than the second list. The resultant lists should also be circular lists and not linear lists.

Input:

You have to complete the method which takes 3 argument: The address of the head of the linked list , addresses of the head of the first and second halved resultant lists.. You should not read any input from stdin/console. There are multiple test cases. For each test case, this method will be called individually.

Output:

Set the *head1_ref and *head2_ref to first resultant list and second resultant list respectively.


Constraints:

1<=T<=100
2<=N<=100


Example:

Input:
2
3
1 5 7
4
2 6 1 5

Output:
1 5
7
2 6
1 5

--CODE--

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node *p,*q,*last;
    p=head;
    q=head;
    *head1_ref=head;
    *head2_ref=head;
    last=head;
    int c=1,m=1;
    if(head==NULL)
    {
        *head1_ref=NULL;
        *head2_ref=NULL;
        return;
    }
    while(last->next!=head)
    {
        last=last->next;
        c++;
    }
    c++;
    c=c/2;
    while(m<c)
    {
        *head2_ref=(*head2_ref)->next;
        p=p->next;
        m++;
    }
    *head2_ref=(*head2_ref)->next;
    last->next=*head2_ref;
    p->next=*head1_ref;
}

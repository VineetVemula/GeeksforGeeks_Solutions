Given a single linked list of size N, your task is to complete the function alternatingSplitList() that splits the given linked list into two smaller list. The sublists should be made from alternating elements from the original list.

Original linked List: 5 4 3 2 1 0
Resultant Linked List 'a' 5 3 1
Resultant Linked List 'b' 4 2 0
Note: the sublist should in the order with respect to original list. 
Input:
The function takes three inputs, reference pointer to the head of the original list (headRef) and two NULL reference pointer to the head of the two sublist's (aRef and bRef).
There will be multiple test cases and for each test thi function will be called seperately.

Output:
For each test case print the two sublists head1 and head2.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
6
0 1 0 1 0 1
5
2 5 8 9 6
Output:
0 0 0
1 1 1
2 8 6
5 9

--CODE--

void alternatingSplitList(struct node* headRef, struct node** aRef, struct node** bRef)
{
    node *p,*q,*r,*head;
    p=headRef;
    head=headRef;
    q=*aRef;
    r==*bRef;
    if(p==NULL)
    {
        *aRef=NULL;
        *bRef=NULL;
        return;
    }
    while(head!=NULL)
    {
        head=head->next;
        if(*aRef==NULL)
        {
            *aRef=p;
            p->next=NULL;
            q=p;
            p=head;
        }
        else
        {
            q->next=p;
            q=p;
            p->next=NULL;
            p=head;
        }
        if(head==NULL)
            return;
        head=head->next;
        if(*bRef==NULL)
        {
            *bRef=p;
            r=p;
            p->next=NULL;
            p=head;
        }
        else
        {
            r->next=p;
            r=p;
            p->next=NULL;
            p=head;
        }
        if(head==NULL)
            return;
    }
}

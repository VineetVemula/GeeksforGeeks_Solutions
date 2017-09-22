Given a Singly Linked List of size N, your task is to complete the function areIdentical(), which checks whether two linked list are identical or not. Two Linked Lists are identical when they have same data and arrangement of data is also same.

Example:

Input:
head1:- 1->2->3
head2:- 1->2->3
Output: Identical

Input:
head1:- 1->3->2
head2:- 1->2->3
Output: Not identical
 

Input:
The function takes two argument as input, the reference pointer to the two heads (head1 & head2) of the two linked list.
There will be T test cases and for each test case the function will be called separately. 

Output:
For each test the output will be 'Identical' if two list are identical else 'Not identical'.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
6
1 2 3 4 5 6
4
99 59 42 20
5
1 2 3 4 5
5
1 2 3 4 5
Output:
Not identical
Identical

--CODE--

bool areIdentical(struct Node *head1, struct Node *head2)
{
    Node *p,*q;
    p=head1;
    q=head2;
    if(p==NULL && q==NULL)
        return 1;
    while(p!=NULL && q!=NULL)
    {
        if(p->data!=q->data)
            return 0;
        p=p->next;
        q=q->next;
    }
    if(p!=NULL || q!=NULL)
        return 0;
    return 1;
}

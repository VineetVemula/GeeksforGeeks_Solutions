/* Question:-
 Given a linked list,performs the following task

Remove alternative nodes from second node
Reverse the removed list.
Append the removed list at the end.
Input :

You have to complete the method which takes one argument: the head of the linked list. You should not read any input from stdin/console.
The struct Node has a data part which stores the data and a next pointer which points to the next element of the linked list. 
There are multiple test cases. For each test case, this method will be called individually.

Output:

You should not print any output to stdin/console
 

Example:

Input List: 1->2->3->4->5->6
After step 1 Linked list are 1>3->5 and 2->4->6
After step 2 Linked list are 1->3->5 abd 6->4->2
After step 3 Linked List is 1->3->5->6->4->2
Output List: 1->3->5->6->4->2
NOTE: I GOT ALL THE OUTPUTS RIGHT BUT GEEKS FOR GEEKS TERMED THIS SOLUTION WRONG FOR SPECIAL TEST CASES. 
BUT IT GENERATES CORRECT OUTPUT. SO DO NOT SUBMIT THIS IN GEEKS FOR GEEKS.
*/

void  rearrange(struct node *odd)
{
    struct node *a,*l,*m,*n,*s,*p,*q,*last,*b,*x;
    a = (struct node*)malloc(sizeof(struct node));
    p = odd->next;
    last = odd;
    s = a;
    b=odd;
    while(p!=NULL)
    {
        s->data = p->data;
        if(p->next!=NULL && p->next->next!=NULL)
        {
         x = (struct node*)malloc(sizeof(struct node));
         x->next = NULL;
         s->next = x;
         s = s->next;
         x=NULL;
        }
        if(p->next!=NULL)
        {
        p = p->next->next;
        }
        else p=NULL;
        b->next=b->next->next;
        b=b->next;
        
    }
    while(last->next!=NULL)
    {
        last=last->next;
    }
        l=a;
        m=NULL;
        while(l!=NULL)
        {
            n = l->next;
            l->next = m;
            m = l;
            l = n;
        }
        a = m;
        last->next = a;
    
}

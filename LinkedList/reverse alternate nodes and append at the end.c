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

Note: If you use "Test" or "Expected Output Button" use below example format

INPUT:
1(Number of Test cases)
8
10 4 9 1 3 5 9 4

OUTPUT:
10 9 3 9 4 5 1 4 

--CODE--

void rearrange(struct node *odd)
{
    node *p,*q,*l;
    p=odd;
    q=odd->next;
    l=NULL;
    while(p!=NULL && q!=NULL)
    {
        p->next=q->next;
        q->next=l;
        l=q;
        if(p->next==NULL)
        {
            p->next=l;
            break;
        }
        p=p->next;
        q=p->next;
        if(q==NULL)
            p->next=l;
    }
}

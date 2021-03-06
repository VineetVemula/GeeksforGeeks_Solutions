Given a singly linked list, rotate the linked list counter-clockwise by k nodes. Where k is a given positive integer smaller than or equal to length of the linked list. For example, if the given linked list is 10->20->30->40->50->60 and k is 4, the list should be modified to 50->60->10->20->30->40.

Input:

In this problem, complete the method which takes two argument: the head of the linked list and int k. We should not read any input from stdin/console.
The struct Node has a data part which stores the data and a next pointer which points to the next element of the linked list. 
There are multiple test cases. For each test case, this method will be called individually.

Output:
Rotate the link list from index k and return its new head pointer.


Note: If you use "Test" or "Expected Output Button" use below example format

Example:
Input:
1
8
1 2 3 4 5 6 7 8
4

Output:
5 6 7 8 1 2 3 4



--CODE--

void rotate(struct node **head_ref, int k)
{
   int i;
   struct node *last,*p;
   last=*head_ref;
   p=*head_ref;
   while(last->next!=NULL)
    last=last->next;
   for(i=1;i<k;i++)
   {
       p=p->next;
   }
   last->next=*head_ref;
   *head_ref=p->next;
   p->next=NULL;
}

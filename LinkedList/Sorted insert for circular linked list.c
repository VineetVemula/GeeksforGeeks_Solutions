Given a sorted circular linked list, insert a newnode so that it remains a sorted circular linked list.

Input:

In this problem, method takes two argument: the address of the head of the linked list and the data which you have to insert. The function should not read any input from stdin/console.
The Node structure has a data part which stores the data and a next pointer which points to the next element of the linked list. 
There are multiple test cases. For each test case, this method will be called individually.

Output:
Set the * head_ref to head of resultant linked list.

Note: If you use "Test" or "Expected Output Button" use below example format

Constraints:

1<=T<=100
0<=N<=200

Example:

Input:
2
3                           Size of Linked List
1 2 4                    Elements of Linked List
2                           Element to be inserted
4
1 4 7 9
5

Output:

1 2 2 4
1 4 5 7 9

--CODE--

void sortedInsert(Node** head_ref, int x)
{
   Node *p,*q,*last;
   q=(Node*)malloc(sizeof(Node));
   q->data=x;
   p=*head_ref;
   last =*head_ref;
   if(p==NULL)
   {
       *head_ref=q;
       q->next=q;
       q=NULL;
       return;
   }
    while(last->next!=*head_ref)
        last=last->next;
   if(p->data>x)
   {
       
       q->next=p;
       *head_ref=q;
       last->next=q;
       q=NULL;
       return;
   }
   if(p->next==*head_ref)
   {
       q->next=p->next;
       p->next=q;
       q=NULL;
       return;
   }
   while(p->next!=*head_ref  && p->next->data<x)
   {
       p=p->next;
   }
   q->next=p->next;
   p->next=q;
   q=NULL;
   
}

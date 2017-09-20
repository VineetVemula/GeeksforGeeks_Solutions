Given a singly linked list, rearrange it in a way that all odd position nodes are together and all even positions node are together,

Input: You have to complete the method which takes one argument: the head of the linked list. You should not read any input from stdin/console.. 
Note: There are multiple test cases, for each test case, this method will be called individually.

Output:  
Your function should return pointer to head of the modified list.

Constraints:
1 <=T<= 50
1 <=N<= 100
1 <=value<= 1000

Example:
Input:
2
4
1 2 3 4
5
1 2 3 4 5

Output:
1 3 2 4
1 3 5 2 4

--CODE--

Node *rearrangeEvenOdd(Node *head)
{
   Node *p,*q,*last,*r,*s;
   p=head;
   q=head;
   r=head;
   last=head;
   s=head;
   while(p->next!=NULL)
   {
       p=p->next;
       last=last->next;
   }
   q=q->next;
   
   if(r==last)
   {
       return s;
   }
   if(q->next==NULL)
   {
       return s;
   }
   do
   {
       p->next=q;
       r->next=q->next;
       q=q->next->next;
       r=r->next;
       p=p->next;
       p->next=NULL;
   }while(r!=last && p!=last);
   
   return s;
}

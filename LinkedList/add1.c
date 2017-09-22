A number (n) is represented in Linked List such that each digit corresponds to a node in linked list. Add 1 to it.

Input:
You have to complete the method which takes one argument: the head of the linked list. You should not read any input from stdin/console.. There are multiple test cases. For each test case, this method will be called individually

Output:
Your function should return pointer to head of the modified list.

Constraints:
1 <=T<= 50
1 <=n<= 10000

Example:

Input:
4
456
123
999
1879

Output:
457 
124 
1000 
1880
 
 
 --CODE--
 
 Node *addOne(Node *head)
{
   Node *last,*q;
   int c=0,i,d=1,t;
   last=head;
   while(last!=NULL)
   {
       last=last->next;
       c++;
   }

   while(c!=0)
   {
       last=head;
       for(i=1;i<c;i++)
       {
           last=last->next;
       }
       t=last->data+d;
       last->data=t%10;
       d=t/10;
       if(d==0)
       {
           break;
       }
       c--;
   }
   if(d==1)
   {
       q=(Node*)malloc(sizeof(Node));
       q->data=d;
       q->next=head;
       head=q;
       q=NULL;
   }
   return head;
}

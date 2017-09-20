Given a linked list of size N, your task is to complete the function countNodesinLoop() that checks whether a given Linked List contains loop or not and if loop is present then return the count of nodes in loop or else return 0.

For Example:
Size of the loop in the below linked list is 4.

Input:
The function takes a single argument as input, the reference pointer to the head of the linked list.
There will be T, test cases and for each test case the function will be called separately.

Output:
For each test case the function must return the size of the loop in the linked list or else 0.

Constraints:
1<=T<=100
1<=N<=500

Example:
Input:
2
10
25 14 19 33 10 21 39 90 58 45
4
2
1 0
1
Output:
6
1

--CODE--

int countNodesinLoop(struct Node *head)
{
   Node* p,*q;
   int c=0;
   p=head;
   q=head;
   if(head==NULL)
   {
       return 0;
   }
   while(p!=NULL && q!=NULL)
   {
       if(p->next==NULL)
       {
           return 0;
       }
       p=p->next->next;
       q=q->next;
       if(p==q)
       {
           do
           {
               q=q->next;
               c++;
           }while(q!=p);
           return c;
       }
   }
   return 0;

}

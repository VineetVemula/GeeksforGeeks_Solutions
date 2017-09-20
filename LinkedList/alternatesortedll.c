Given a Linked list of size N, the list is in alternating ascending and descending orders, your task is to complete the function sort() that sorts the given linked list in non-decreasing order.

Example:
Input List: 10->40->53->30->67->12->89->NULL
Output List: 10->12->30->43->53->67->89->NULL

Input:
The function takes a single argument as input the reference pointer to the head of the linked list.
There are T test cases and for each test case the function will be called separately.

Output:
For each test case function should return reference pointer to the head of the new linked list.

Constraints:
1<=T<=100
1<=N<=100
0<=A[]<=103

Example:
Input:
2
6
1 9 2 8 3 7
5
13 99 21 80 50
Output:
1 2 3 7 8 9
13 21 50 80 99

--CODE--

void sort(Node **head)
{
     struct Node* last,*start,*r,*p,*d,*l;
     l=NULL;
     start=*head;
     p=start->next;
     while(start!=NULL && p!=NULL)
     {
        start->next=p->next;
        p->next=l;
        l=p;
        start=start->next;
        if(start!=NULL)
            p=start->next;
     }
     start=*head;
     d=start;
     p=l;
     r=NULL;
        while(start!=NULL && l!=NULL) 
        {
            if((start->data)<=(l->data))
            {
               start=start->next;
               if(r==NULL)
               {
                   r=d;
                   r->next=NULL;
                   *head=r;
               }
               else
               {
                    r->next=d;
                    r=r->next;
                    r->next=NULL;
               }
               d=start;
            }
            else
            {
                l=l->next;
                if(r==NULL)
                {
                   r=p;
                   r->next=NULL;
                   *head=r;
                }
                else
                {
                    r->next=p;
                    r=r->next;
                    r->next=NULL;
                }
                p=l;
            }
        }
        while(start!=NULL)
        {
            start=start->next;
               if(r==NULL)
               {
                   r=d;
                   r->next=NULL;
                   *head=r;
               }
               else
               {
                    r->next=d;
                    r=r->next;
                    r->next=NULL;
               }
               d=start;
        }
        while(l!=NULL)
        {
             l=l->next;
                if(r==NULL)
                {
                   r=p;
                   r->next=NULL;
                   *head=r;
                }
                else
                {
                    r->next=p;
                    r=r->next;
                    r->next=NULL;
                }
                p=l;
        }
}

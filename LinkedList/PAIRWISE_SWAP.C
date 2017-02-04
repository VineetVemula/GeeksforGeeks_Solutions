TAKE NOTE:Pointers are passed by value as anything else. That means the contents of the pointer variable (the address of the 
object pointed to) is copied. That means that if you change the value of the pointer in the function body, 
that change will not be reflected in the external pointer that will still point to the old object.

QUESTION
Given a singly linked list, write a function to swap elements pairwise. For example, if the linked list is 1->2->3->4->5 then the function should change it to 2->1->4->3->5, and if the linked list is 1->2->3->4->5->6 then the function should change it to 2->1->4->3->6->5.

Input:

In this problem, method takes one argument: the head of the linked list. The function should not read any input from stdin/console.
The struct Node has a data part which stores the data and a next pointer which points to the next element of the linked list. 
There are multiple test cases. For each test case, this method will be called individually.

Output:
Pairwise swap linked list elements .

Note: If you use "Test" or "Expected Output Button" use below example format

Example:
Input:
1
8
1 2 2 4 5 6 7 8

Output:
2 1 4 2 6 5 8 7

SOLUTION
*
  Pairwise swap a linked list
  The input list will have at least one element  
  node is defined as 
  struct node
  {
     int data;
     struct node *next;
  }
*/
void pairWiseSwap(struct node *head)
{
  struct node *p,*r,*q;
  int c=0;
  q = head;
  p = head->next;
  r = head;
  *head = *head->next;
  while(q!=NULL)
  {
      if(p==NULL)
      {
          goto a;
      }
      q->next=p->next;
      p->next=q;
      if(c>0)
      {
          r->next=p;
          r=r->next->next;
      }
      c++;
      if(p->next->next==NULL)
      {
          break;
      }
      if(p->next->next->next==NULL)
      {
          p=NULL;
          goto a;
      }
      p=p->next->next->next;
      a: q = q->next;
  }
  
}


YOU MUST PASS THE PPOINTER(HEAD) USING CALL BY REFERENCE CONCEPT FOR ABOVE CODE TO WORK.
  ALTERNATIVE SOLUTION BECAUSE PASS BY REFERENCE WONT WORK FOR THIS TYPE OF SITUATION. 

  
#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
};
void pairWiseSwap(struct node *head)
{
    struct node *p,*r,*q;
    int c=0;
    q = (struct node *)malloc(sizeof(struct node));
    q->data=head->data;
    q->next=p;
    p = head->next;
    r = q;
    r->next=p;
    
   
    while(q!=NULL)
    {
        if(p==NULL)
        {
            goto a;
        }
        q->next=p->next;
        p->next=q;
        if(c>0)
        {
            r->next=p;
            r=r->next->next;
        }
        c++;
        if(p->next->next==NULL)
        {
            break;
        }
        if(p->next->next->next==NULL)
        {
            p=NULL;
            goto a;
        }
        p=p->next->next->next;
    a: q = q->next;
    }
   
    
}

int main()
{
    
    struct node *start = NULL,*g=NULL,*x=NULL,*q=NULL;
    int i;
    
    for(i=1;i<=8;i++)
    {
        x = (struct node*)malloc(sizeof(struct node));
        if(i==1)
        {
            g=x;
            start=g;
        }
        x->data=i;
        if(i>1)
        {
            g->next = x;
            g=g->next;
        }
    }
    g->next=NULL;
    pairWiseSwap(start);
    start=start->next;
    printf("after func head is %d\n",start->data);
    q=start;
    while(q!=NULL)
    {
        printf("%d %d\n",q->data,q->next->data);
        q=q->next;
    }
    
}

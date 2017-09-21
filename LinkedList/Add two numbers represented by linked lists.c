Given two numbers represented by two lists, write a function that returns sum list. The sum list is list representation of addition of two input numbers.

Suppose you have two linked list 5->4 ( 4 5 )and 5->4->3( 3 4 5) you have to return  a resultant linked list 0->9->3 (3 9 0).

Input:

In this problem, method takes two argument: the head of the first and second linked list. The function should not read any input from stdin/console.
The struct Node has a data part which stores the data and a next pointer which points to the next element of the linked list. 
There are multiple test cases. For each test case, this method will be called individually.

Output:
Add  two numbers represented by linked lists.

Note: If you use "Test" or "Expected Output Button" use below example format
Constraints:

1<=T<=100

1<=N<=100
Example:

Input:

2

2

4 5

3

3 4 5

2

6 3

1

7

Output:

0 9 3 

0 7

--CODE--

Node*  addTwoLists(Node* first, Node* second)
{
    Node *q,*f,*s,*start,*p;
    int x=0,d=0,t,m;
    f=first;
    s=second;
    start=NULL;
    while(f!=NULL && s!=NULL)
    {
        q=(Node*)malloc(sizeof(Node));
        q->next=NULL;
        x= f->data+s->data;
        t=x%10;
        m=t+d;
        q->data=m%10;
        d=x/10;
        if(d==0)
            d=m/10;
        if(start==NULL)
        {
            start=q;
            p=q;
        }
        else
        {
            p->next=q;
            p=p->next;
        }
        q=NULL;
        f=f->next;
        s=s->next;
    }
    while(f!=NULL)
    {
        q=(Node*)malloc(sizeof(Node));
        q->next=NULL;
        x= f->data;
        x=x+d;
        t=x%10;
        q->data=t;
        d=x/10;
        if(start==NULL)
        {
            start=q;
            p=q;
        }
        else
        {
            p->next=q;
            p=p->next;
        }
        q=NULL;
        f=f->next;
    }
    while(s!=NULL)
    {
        q=(Node*)malloc(sizeof(Node));
        q->next=NULL;
        x= s->data;
        x=x+d;
        t=x%10;
        q->data=t;
        d=x/10;
        if(start==NULL)
        {
            start=q;
            p=q;
        }
        else
        {
            p->next=q;
            p=p->next;
        }
        q=NULL;
        s=s->next;
    }
    if(d!=0)
    {
        q=(Node*)malloc(sizeof(Node));
        q->next=NULL;
        q->data=d;
        p->next=q;
        q=NULL;
    }
    return start;
}

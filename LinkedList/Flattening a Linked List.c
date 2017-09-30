Given a Linked List where every node represents a linked list and contains two pointers of its type:
(i) a next pointer to the next node
(ii) a bottom pointer to a linked list where this node is head.

You have to flatten the linked list to a single linked list which is sorted.

For Ex: Shown below is a given linked list

           5 -> 10 -> 19 -> 28
       |    |     |     |
       V    V     V     V
       7    20    22    35
       |          |     |
       V          V     V
       8          50    40
       |                |
       V                V
       30               45
and after flattening it, the sorted linked list looks like:

 5->7->8->10->19->20->22->28->30->35->40->45->50

The  node structure has 3 fields as mentioned. A next pointer, a bottom pointer and a data part.
There are multiple test cases. For each test case, this function will be called individually.

Note : All linked lists are sorted.

Input (To be used for Expected Output):
The first line of the input contains an integer 'T' denoting the number of test cases. Then T test cases follow.
First line of each test case contains an integer N denoting the number of head nodes connected to each other.
Second line of each test case contains N space separated numbers (M1, M2...Mn) denoting number of elements in linked lists starting with each head.
Third line of each test case contains all the elements of the linked list starting with 1st head node and covering all the elements through its down pointer, then 2nd head node and covering all its elements through down pointer and so on till the last head node of the linked list.

Output:
Return a pointer to the flattened linked list.

Constraints:

1<=T<=50
0<=N<=50
1<=Mi<=20
1<=Element of linked list<=1000

Example:
Input
1                   
4 
4 2 3 4                  
5 7 8 30 10 20 19 22 50 28 35 40 45

Output
5 7 8 10 19 20 22 28 30 35 40 45 50

--CODE--

Node *flatten(Node *root)
{
     Node *p,*last,*q,*r,*s,*u,*v;
    last=root;
    int c=0,temp,i,j=1;
    if(root==NULL)
        return root;
    while(last->next!=NULL)
    {
        last=last->next;
        j++;
    }
    if(root->next==NULL)
        c=1;
    r=root;
    if(r->next==NULL)
        goto d;

    for(i=0;i<j-1;i++)
    {
        for(r=root;r->next!=NULL;r=r->next)
        {
            if(r->data>r->next->data)
            {
                temp=r->data;
                r->data=r->next->data;
                r->next->data=temp;
                v=r->bottom;
                r->bottom=r->next->bottom;
                r->next->bottom=v;
            }
            
        }
    }
    d:;
    while(last!=NULL && last->bottom!=NULL)
    {
        last->next=last->bottom;
        last->bottom=NULL;
        last=last->next;
    }
    while(c!=1)
    {
        r=root;
        last=root;
        while(r->next!=NULL)
        {
            if(r->next->bottom==NULL && r->bottom!=NULL)
                last=r;
            r=r->next;
        }
        if(last==root)
            c=1;
        p=last;
        a:;
        while(p->next==NULL || p->bottom->data<=p->next->data)
        {
            p->bottom->next=p->next;
            p->next=p->bottom;
            p->bottom=NULL;
            p=p->next;
            if(p->bottom==NULL)
                goto b;
        }
        q=p;
        while(q->next!=NULL && p->bottom->data>q->next->data)
        {
            q=q->next;
        }
        p->bottom->next=q->next;
        q->next=p->bottom;
        p->bottom=NULL;
        p=q->next;
        last=p;
        if(p!=NULL && p->bottom!=NULL)
            goto a;
        b:;
    }
    p=root;
    while(p!=NULL)
    {
        p->bottom=p->next;
        p=p->next;
    }
    return root;
}

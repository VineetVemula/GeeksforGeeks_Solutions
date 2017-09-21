Given two linked lists, your task is to complete the function makeUnion, that returns the union of two linked lists.

Input:
The function takes 2 arguments, reference pointer to the head of the first linked list (head1) and reference pointer to the head of the second linked list (head2). 
There are multiple test cases and for each test case this function will be called separately.

Output:
The function should return reference pointer to the head of the new list that is formed by the union of the two the lists. 
Note: The new list formed should be in non-decreasing order.

Constraints:
1<=T<=100
1<=N<=103

Example:
Input:
1
6
9 6 4 2 3 8
5
1 2 8 6 2
Output:
1 2 3 4 6 8 9

--CODE--

struct node* makeUnion(struct node* head1, struct node* head2)
{
    struct node* h1,*h2,*l,*q,*start;
    l=NULL;

    for(h1=head1;h1!=NULL;h1=h1->next)
    {
        for(h2=head2;h2!=NULL;h2=h2->next)
        {
            if(h2->data==h1->data)
            {
                break;
            }    
                
        }
        if(h2!=NULL)
            continue;
        q=(node*)malloc(sizeof(node));
        q->data=h1->data;
        if(l==NULL)
        {
            l=q;
            start=l;
            l->next=NULL;
        }
        else
        {
            l=start;
            if(l->data==q->data)
            {
                q=NULL;
                continue;
            }
            if(l->data>q->data)
            {
                q->next=l;
                start=q;
                q=NULL;
                continue;
            }
            while(l->next!=NULL && l->next->data<q->data)
            {
                l=l->next;
            }
            if(l->next==NULL)
                {
                    q->next=l->next;
                    l->next=q;
                }
            if(q->data!=l->next->data)
            {
                q->next=l->next;
                l->next=q;
            }
        }
        q=NULL;
    }
    for(h2=head2;h2!=NULL;h2=h2->next)
        {
            q=(node*)malloc(sizeof(node));
            q->data=h2->data;
            if(start==NULL)
            {
                start=q;
                start->next=NULL;
            }
            else
                {
                    l=start;
                    if(l->data==q->data)
                    {
                        q=NULL;
                        continue;
                    }
                    if(l->data>q->data)
                    {
                        q->next=l;
                        start=q;
                        q=NULL;
                        continue;
                    }
                    while(l->next!=NULL && l->next->data<q->data)
                    {
                        l=l->next;
                    }
                    if(l->next==NULL)
                    {
                        q->next=l->next;
                        l->next=q;
                    }
                    if(q->data!=l->next->data)
                    {
                        q->next=l->next;
                        l->next=q;
                    }
                }
                q=NULL;
        }   
    return start;
}


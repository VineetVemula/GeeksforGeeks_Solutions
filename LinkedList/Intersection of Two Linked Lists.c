Given two linked lists, your task is to complete the function findIntersection, that returns the intersection of two linked lists.

Input:
The function takes 2 arguments, reference pointer to the head of the first linked list (head1) and reference pointer to the head of the second linked list (head2). 
There are multiple test cases and for each test case this function will be called separately.

Output:
The function should return reference pointer to the head of the new list that is formed by the intersection of the two the lists. 
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
2 6 8

--CODE--

struct node* findIntersection(struct node* head1, struct node* head2)
{
    struct node* h1,*h2,*l,*q,*start;
    l=NULL;
    if(h1==NULL)
    {
        return h2;
    }
    if(h2==NULL)
    {
        return h1;
    }
    
    for(h1=head1;h1!=NULL;h1=h1->next)
    {
        for(h2=head2;h2!=NULL;h2=h2->next)
        {
            if(h2->data==h1->data)
            {
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
                    if(l->data>=q->data)
                    {
                        q->next=l;
                        start=q;
                        q=NULL;
                        h2->data=-1;
                        break;
                    }
                    while(l->next!=NULL && l->next->data<=q->data)
                    {
                        l=l->next;
                    }
                    q->next=l->next;
                    l->next=q;
                }
                q=NULL;
                h2->data=-1;
                break;
            }
        }
    }
    return start;
}

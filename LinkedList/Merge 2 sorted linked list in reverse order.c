Given two linked lists sorted in increasing order. Merge them such a way that the result list is in decreasing order. Both the Linked list can be of different sizes.

Input:
You have to complete the method which takes 2 argument: the head of the first linked list  and the head of second linked list. You should not read any input from stdin/console. There are multiple test cases. For each test case, this method will be called individually.

Output:
Your function should return a pointer to the list obtained by merging the two sorted linked list passed as argument.

Constraints:
1 <=T<= 50
1 <= size of linked lists <= 1000

Example:
Input:
2
4 3
5 10 15 40 
2 3 20
2 2
1 1
2 4 
 

Output:
40 20 15 10 5 3 2
4 2 1 1 

--CODE--

struct Node * mergeResult(Node *node1,Node *node2)
{
    Node *p,*q,*r,*s,*l;
    p=node1;
    q=node2;
    r=p;
    s=q;
    l=NULL;
    while(p!=NULL && q!=NULL)
    {
        if(p->data<q->data)
        {
            p=p->next;
            r->next=l;
            l=r;
            r=p;
        }
        else
        {
            q=q->next;
            s->next=l;
            l=s;
            s=q;
        }
    }
    while(p!=NULL)
    {
        p=p->next;
        r->next=l;
        l=r;
        r=p;
    }
    while(q!=NULL)
    {
        q=q->next;
        s->next=l;
        l=s;
        s=q;
    }
    return l;
}

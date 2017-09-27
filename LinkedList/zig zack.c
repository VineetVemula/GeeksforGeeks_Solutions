Given a Linked list, rearrange it such that converted list should be of the form a < b > c < d > e < f .. where a, b, c are consecutive data node of linked list and such that the order of linked list is sustained.
For example: In 11 15 20 5 10 we consider only 11 20 5 15 10 because it satisfies the above condition and the order of linked list. 5 20 11 15 10 is not considered as it does not follow the order of linked list.

Input:
You have to complete the method which takes 1 argument: the head of the  linked list. You should not read any input from stdin/console. There are multiple test cases. For each test case, this method will be called individually.

Output:
Your function should return a pointer to the zig zack linked list.

Constraints:
1 <=T<= 100
1 <= size of linked list(a) <= 1000

Example:
Input:
2
4
1 2 3 4 
5
11 15 20 5 10

Output:
1 3 2 4
11 20 5 15 10

--CODE--

Node *zigZack(Node* head)
{
    Node *p,*q;
    p=head;
    q=head;
    int c=0,temp;
    while(p!=NULL && q!=NULL)
    {
        if(c==0)
        {
            q=p->next;
            if(q==NULL)
                break;
            if(p->data>q->data)
            {
                temp=q->data;
                q->data=p->data;
                p->data=temp;
                p=p->next;
                c=1;
            }
            else 
            {
                p=p->next;
                c=1;
            }
        }
        else
        {
             q=p->next;
             if(q==NULL)
                break;
            if(p->data<q->data)
            {
                temp=q->data;
                q->data=p->data;
                p->data=temp;
                p=p->next;
                c=0;
            }
            else 
            {
                p=p->next;
                c=0;
            }
        }
    }
    return head;
}

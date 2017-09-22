Given a singly linked list, remove all the nodes which have a greater value on right side.

Input:
You have to complete the method which takes 1 argument: the head of the  linked list  .You should not read any input from stdin/console. There are multiple test cases. For each test case, this method will be called individually.

Output:
Your function should return a pointer to the linked list in which all nodes which have a greater value on right side are removed.

Constraints:
1<=T<=50
1<=size of linked list <=100
1<=element of linked list <=1000

Example:

Input:
3
8
12 15 10 11 5 6 2 3
6
10 20 30 40 50 60
6
60 50 40 30 20 10

Output:

15 11 6 3
60
60 50 40 30 20 10

--CODE--

Node *compute(Node *head)
{
    Node* start,*p,*r,*q;
    start=head;
    for(p=head;p->next!=NULL;p=p->next)
    {
        for(r=p->next;r!=NULL;r=r->next)
        {
            if(r->data>p->data)
            {
                if(p==start)
                {
                    start=start->next;
                    break;
                }
                q=start;
                while(q->next!=p)
                    q=q->next;
                q->next=p->next;
                break;
            }
        }
    }
    return start;
}

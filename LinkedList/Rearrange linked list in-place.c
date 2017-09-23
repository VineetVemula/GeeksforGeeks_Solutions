Given a singly linked list L0 -> L1 -> … -> Ln-1 -> Ln. Rearrange the nodes in the list so that the new formed list is : L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2.

Input:
You have to complete the method which takes 1 argument: the head of the  linked list. You should not read any input from stdin/console. There are multiple test cases. For each test case, this method will be called individually.

Output:
Your function should return a pointer to the rearranged list so obtained.

Constraints:
1 <=T<= 50
1 <= size of linked lists <= 100

Example:
Input:
2
4
1 2 3 4
5
1 2 3 4 5

Output:
1 4 2 3
1 5 2 4 3

--CODE--

Node *inPlace(Node *root)
{
    Node *p,*q,*start,*r,*last;
    r=NULL;
    p=root;
    q=root;
    last=root;
    while(root!=NULL && root->next!=NULL)
    {
        p=root;
        q=root->next;
        last=root;
        while(q->next!=NULL)
        {
            q=q->next;
            last=last->next;
        }
        root=root->next;
        if(root==q)
            root=NULL;
        if(r==NULL)
        {
            r=p;
            start=r;
            p->next=q;
            r=q;
            last->next=NULL;
        }
        else
        {
            r->next=p;
            p->next=q;
            if(last!=p)
                last->next=NULL;
            r=q;
        }
    }
    if(root!=NULL)
    {
        r->next=root;
    }
    return start;
}

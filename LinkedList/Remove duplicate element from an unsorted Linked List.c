Remove duplicate element from an unsorted Linked List ..

Input:
You have to complete the method which takes 1 argument: the head of the  linked list  .You should not read any input from stdin/console. There are multiple test cases. For each test case, this method will be called individually.

Output:
Your function should return a pointer to a linked list with no duplicate element.

Constraints:
1 <=T<= 100
1 <= size of linked lists <= 50

Note: If you use "Test" or "Expected Output Button" use below example format.

Example:
Input
2
4
5 2 2 4
5
2 2 2 2 2

Output
5 2 4
2

--CODE--

Node *removeDuplicates(Node *root)
{
    Node *p,*q;
    p=root;
    int c;
    while(p->next!=NULL)
    {
        q=p;
        c=p->data;
        while(q->next!=NULL)
        {
            if(q->next->data==c)
            {
                q->next=q->next->next;
            }
            else
            {
                q=q->next;
            }
        }
        if(p->next!=NULL)
            p=p->next;
    }
    return root;
}

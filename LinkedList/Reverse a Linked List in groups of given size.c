Given a linked list, write a function to reverse every k nodes (where k is an input to the function).If a linked list is given as 1->2->3->4->5->6->7->8->NULL and k = 3 then output will be 3->2->1->6->5->4->8->7->NULL.

Input:
In this problem, method takes two argument: the head of the linked list and int k. You should not read any input from stdin/console.
The struct Node has a data part which stores the data and a next pointer which points to the next element of the linked list. 
There are multiple test cases. For each test case, this method will be called individually.

Output:
Reverse the linked list in the group of given size and return the reference of starting node(head) of the reversed Linked list .

Note: If you use "Test" or "Expected Output Button" use below example format
Example:
Input:
1
8
1 2 2 4 5 6 7 8
4

Output:
4 2 2 1 8 7 6 5

--CODE--

struct node *reverse (struct node *head, int k)
{ 
    struct node *p,*l,*last,*start,*q;
    int c=0,flag=1;
    p=head;
    last=NULL;
    l=NULL;
    while(p!=NULL)
    {
        while(c!=k)
        {
            q=(node*)malloc(sizeof(node));
            q->data=p->data;
            q->next=l;
            l=q;
            if(last==NULL)
                last=q;
            q=NULL;
            p=p->next;
            c++;
            if(p==NULL)
                break;
        }
        if(flag==1)
            start=l;
        if(flag!=1)
            last->next=l;
        while(last->next!=NULL)
            last=last->next;
        l=NULL;
        flag=0;
        c=0;
    }
    return start;
}

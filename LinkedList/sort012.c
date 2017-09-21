Given a linked list of 0s, 1s and 2s, sort it.

Input:

Complete the method which takes one argument: the head of the linked list. The program should not read any input from stdin/console.
The struct Node has a data part which stores the data and a next pointer which points to the next element of the linked list. 
There are multiple test cases. For each test case, this method will be called individually.

Output: The function should not print any output to stdin/console.
 

Example:

Input:
1 2 2 1 2 0 2 2

Output:
0 1 1 2 2 2 2 2 

For Testing(format):

1(Test cases)
8(Number of elements in Link List)
1 2 2 1 2 0 2 2 
 
 --CODE--
 
 void sortList(Node *head)
{
    Node *p,*last;
    int x,c=0,i,j;
    last=head;
    while(last!=NULL)
    {
        last=last->next;
        c++;
    }
    p=head;
    if(p==NULL)
        return;
    if(p->next==NULL)
        return;
    for(i=0;i<c-1;i++)
    {
        for(p=head;p->next!=NULL;p=p->next)
        {
            if(p->data>p->next->data)
            {
                x=p->data;
                p->data=p->next->data;
                p->next->data=x;
            }
        }
    }
}

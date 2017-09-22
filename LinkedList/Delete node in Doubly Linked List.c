Delete a node from given position in a doubly linked list.

Input:

In this problem, method takes two argument: the address of the head of the linked list and the node you have to delete . The function should not read any input from stdin/console.
The Node structure has a data part which stores the data and a next pointer which points to the next element of the linked list. 
There are multiple test cases. For each test case, this method will be called individually.

Output:

Delete the node from the given doubly linked list and set *head_ref if required .

Constraints:
1<=T<=300
2<=N<=100
1<=x<=N

--CODE--

void deleteNode(struct Node **head_ref, struct Node *del)
{
    if(del==*head_ref)
    {
        *head_ref=(*head_ref)->next;
        (*head_ref)->prev=NULL;
        return;
    }
    if(del->next==NULL)
    {
        del->prev->next=NULL;
        del->prev=NULL;
        return;
    }
    del->next->prev=del->prev;
    del->prev->next=del->next;
    del->prev=NULL;
    del->next=NULL;
}

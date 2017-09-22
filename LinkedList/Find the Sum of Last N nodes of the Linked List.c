Given a single linkd list of size M, your task is to complete the function sumOfLastN_Nodes(), which should return the sum of last N nodes of the linked list.

Input:
The function takes two arguments as input, the reference pointer to the head of the linked list and the an integer N.
There will be T test cases and for each test case the function will be called seperately.

Output:
For each test case output the sum of last N nodes of the linked list.

Constraints:
1<=T<=100
1<=N<=M<=1000

Example:
Input:
2
6 3
5 9 6 3 4 10
2 2
1 2
Output:
17
3

--CODE--

int sumOfLastN_Nodes(struct Node* head, int n)
{
    Node *p,*last;
    int c=0,i,j=0;
    last=head;
    p=head;
    if(head==NULL)
        return 0;
    while(last!=NULL)
    {
        last=last->next;
        c++;
    }
    i=c-n;
    while(i>0)
    {
        p=p->next;
        i--;
    }
    while(p!=NULL)
    {
        j=j+p->data;
        p=p->next;
    }
    return j;
}

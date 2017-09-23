Given two string, represented as linked lists (every character is a node in linked list). Write a function compare() that works similar to strcmp(), i.e., it returns 0 if both strings are same, 1 if first linked list is lexicographically greater, and -1 if second is lexicographically greater.

Input:

In this problem, method takes two argument: the head of the first and second linked list. The function should not read any input from stdin/console.
The struct Node has a data part which stores the data and a next pointer which points to the next element of the linked list. 
There are multiple test cases. For each test case, this method will be called individually.

Output:

Comapare two strings represented as linked list.

Constraints:

1<=T<=100

1<=N,M<=100

Example:
Input:
2
5
a b a b a
4
a b a a
3
a a b
3
a a b

Output:
1
0

--CODE--

int compare(Node *list1, Node *list2) 
{
    Node *p,*q;
    p=list1;
    q=list2;
    while(p!=NULL && q!=NULL)
    {
        if(p->c>q->c)
        {
            return 1;
        }
        if(q->c>p->c)
        {
            return -1;
        }
        p=p->next;
        q=q->next;
    }
    if(q!=NULL)
    {
        return -1;
    }
    if(p!=NULL)
    {
        return 1;
    }
    return 0;
}

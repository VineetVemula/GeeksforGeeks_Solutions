Given a doubly linked list, the task is to Reverse the list. It should be done in-place without altering the nodes' values.

In this function problem, the function reverse takes one argument: Address of the head of the linked list. The function should contain the logic to reverse the linked list.

The linked list node structure has 3 fields, a data part which stores the data, a next pointer which points to the next element of the linked list and a previous pointer which points to the previous node of the linked list. 

There are multiple test cases. For each test case, this function will be called individually.

Note:  The Input/Ouput format and Example given below is used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console, and should not print anything on stdout/console.

Input:
The first line contains an integer 'T' denoting the number of test cases. Then 'T' test cases follow. Each test case consists of two lines. First line of each test case contains an integer N denoting the size of the linked list. Second line of each test case consists of 'N' space separated integers denoting the elements of the linked list.

Output:
Print the linked list in Reverse order.

Constraints:

1<=T<=200
1<=N<=200

Example:
Input:
2
3
2 4 5
4
1 4 6 8

--CODE--

void reverse(struct node **head_ref)
{
  struct node *r,*p,*q;
  r=NULL;
  p=*head_ref;
  if(p==NULL || p->next==NULL)
    return;
  q=p->next;
  while(p!=NULL)
  {
    p->next=r;
    p->prev=q;
    r=p;
    p=q;
    if(q!=NULL)
        q=q->next;
  }
  *head_ref=r;
  
}

Given a linked list of size N and a key, your task is to complete the function insertInMiddle(), that should insert the key in the middle of the linked list.

Input:
The function takes two argument as input, the reference pointer to the head of the linked list and an integer value key, the data to be inserted in the linked list.
There will be T, test cases and for each test case the function will be called separately.

Output:
For each test case the function should return the reference pointer to the head of the linked list.

Constraints:
1<=T<=100
1<=N<=103

Example:
Input:
2
3
1 2 4
3
4
10 20 40 50
30
Output:
1 2 3 4
10 20 30 40 50

--CODE--

Node* insertInMiddle(Node* head, int x)
{
  int c=0;
  struct Node *p,*q,*start;
  start=head;
  p=(Node*)malloc(sizeof(Node));
  p->data=x;
  q=head;
  while(q!=NULL)
  {
    c++;
    q=q->next;
  }
  c++;
  c=c/2;
  q=head;
  while(c!=1)
  {
      c--;
      q=q->next;
  }
  p->next=q->next;
  q->next=p;
  return start;
}

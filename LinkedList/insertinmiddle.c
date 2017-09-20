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

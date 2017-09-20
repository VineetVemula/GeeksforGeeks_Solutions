Node* reverse(Node *head)
{
  Node* p,*q,*r;
  p=head;
  r=NULL;
  q=head->next;
  while(p!=NULL)
  {
      p->next=r;
      r=p;
      p=q;
      if(q!=NULL)
        q=q->next;
  }
  return r;
}

void removeTheLoop(Node *node)
{
   Node *r,*p,*q;
   p=node;
   q=node;
   if(node==NULL)
   {
       return;
   }
   while(p!=NULL && q!=NULL)
   {
       if(p->next==NULL)
       {
           return;
       }
       p=p->next->next;
       q=q->next;
       if(p==q)
        {
            while(1)
            {
                r=node;
                while(r->next!=p)
                {
                    r=r->next;
                    if(p->next==r)
                    {
                        p->next=NULL;
                        return;
                    }
                }
                p=p->next;
            }
        }
   }
   return;
}

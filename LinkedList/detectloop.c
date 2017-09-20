int detectloop(Node *list)
{
   Node* p,*q;
   p=list;
   q=list;
   if(list==NULL)
   {
       return 0;
   }
   while(p!=NULL && q!=NULL)
   {
       if(p->next==NULL)
       {
           return 0;
       }
       p=p->next->next;
       q=q->next;
       if(p==q)
        return 1;
   }
   return 0;
}

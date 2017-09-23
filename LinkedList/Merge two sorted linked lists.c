Given two linked lists sorted in ascending order. Merge them in-place and return head of the merged list.   For example, if first list is 10->20->30 and second list is 15->17, then the result list should be 10->15->17->20->30.

It is strongly recommended to do merging in-place using O(1) extra space.

Input:
You have to complete the method which takes 2 argument: the head of the first linked list  and the head of second linked list. You should not read any input from stdin/console. There are multiple test cases. For each test case, this method will be called individually.

Output:
Your function should return a pointer to the list obtained by merging the two sorted linked list passed as argument.

Constraints:
1 <=T<= 200
1 <= size of linked lists <= 1000
1 <= Data in linked list nodes <= 1000

Example:
Input:
2
4 3
5 10 15 40 
2 3 20
2 2
1 1
2 4 

--CODE--

Node* SortedMerge(Node* head1,   Node* head2)
{
    Node *r,*start,*p,*q;
    r=NULL;
    p=head1;
    q=head2;
    while(head1!=NULL && head2!=NULL)
    {
        
        if(head1->data<head2->data)
        {
            head1=head1->next;
            if(r==NULL)
            {
                r=p;
                start=r;
                r->next=NULL;
                p=head1;
            }
            else
            {
                r->next=p;
                p->next=NULL;
                r=p;
                p=head1;
            }
        }
        else
        {
            head2=head2->next;
            if(r==NULL)
            {
                r=q;
                start=r;
                r->next=NULL;
                q=head2;
            }
            else
            {
                r->next=q;
                q->next=NULL;
                r=q;
                q=head2;
            }    
        }
    }
    while(head1!=NULL)
    {
        head1=head1->next;
            if(r==NULL)
            {
                r=p;
                start=r;
                r->next=NULL;
                p=head1;
            }
            else
            {
                r->next=p;
                p->next=NULL;
                r=p;
                p=head1;
            }
    }
    while(head2!=NULL)
    {
        head2=head2->next;
            if(r==NULL)
            {
                r=q;
                start=r;
                r->next=NULL;
                q=head2;
            }
            else
            {
                r->next=q;
                q->next=NULL;
                r=q;
                q=head2;
            }
    }
    return start;
}

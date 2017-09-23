Given a key (or data) to be inserted, task is to complete the function insertAtBeginning() which inserts the data in front of the linked list and insertAtEnd() which appends the data at the end of the linked list.


Input:
The input's to the functions will be a pointer/reference to the head of the linked list and the data variable (of type integer) that hold the data to be inserted in the list.
With each input there will be an extra boolean variable that chooses from where to insert the data.
0 - Insert at Beginning
1 - Insert at End


Output:
For each test case output will be the linked list after inserting all the elements. 


Constraints:
1<=T<=100
1<=N<=103


Example:
Input:
3
5
9 0 5 1 6 1 2 0 5 0
3
5 1 6 1 9 1
4
15 0 36 0 95 0 14 0
Output:
5 2 9 5 6
5 6 9
14 95 36 15

--CODE--

void insertAtBegining(struct node** headRef, int newData)
{
    struct node* p;
    p=(node*)malloc(sizeof(node));
    p->data=newData;
    p->next=*headRef;
    *headRef=p;
    p=NULL;
}
// function appends the data at the end of the list
void insertAtEnd(struct node** headRef, int newData)
{
    struct node *p,*last;
    last=*headRef;
    p=(node*)malloc(sizeof(node));
    p->data=newData;
    p->next=NULL;
    if(last==NULL)
    {
        *headRef=p;
        p=NULL;
        return;
    }
    while(last->next!=NULL)
    {
        last=last->next;
    }
    
    last->next=p;
    p=NULL;
}

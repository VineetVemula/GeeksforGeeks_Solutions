You are given a Double Link List with one pointer of each node pointing to the next node just like in a single link list. The second pointer which is arbitary pointer  which can point to any node in the list and not just the previous node.  

 

ArbitLinked List1

The task is to complete the function copyList which take one argument the head of the linked list to be copied and should return the head of the copied linked list.
 

Input:
You have to complete the method which takes one argument: the head of the linked list. You should not read any input from stdin/console.
The struct Node has a data part which stores the data and a next pointer which points to the next element of the linked list and an arbitrary pointer (arb) which points to any arbitrary node .
There are multiple test cases. For each test case, this method will be called individually.

Output:
Your function should return the head of the copied list.

Constraints:
1 <=T<= 100
1 <=N<= 100
1 <=Q<= 100
1 <=a,b<= 100

Example:
Input:
1           
4 2                                       
1 2 3 4                             
1 2 2 4                                
The first line above represents T, i.e., the number of test cases. The second line is of the form N Q, where N is the number of nodes and Q is the number of nodes with arbitrary pointers. Third line presents all the nodes of the list. The fourth line represents Q pairs of integers in the order (a b) where a is the pointer and b is the node being pointed to (See explanation below for more understanding).

Explanation of the example: There is one test case. In this test case, there are 4 nodes in linked list.  Among these 4 nodes,  2 nodes have arbit pointer set, rest two nodes have arbit pointer as NULL. Third line tells us the value of four nodes. The fourth line gives the information about arbitrary pointers. The first node with set arbit pointer is 1, its arbit pointer is pointing to node 2.  The second node with set arbit pointer is 2, its arbit pointer is pointing to node 4.

Output:
1    
The output is 1 if linked list is successfully cloned, else false.

--CODE--

Node * copyList(Node *head)
{
    Node *p,*q,*h,*l,*r;
    p=head;
    h=NULL;
    if(head==NULL)
    {
        return head;
    }
    while(p!=NULL)
    {
        q=(Node*)malloc(sizeof(Node));
        q->data=p->data;
        q->arb=p->arb;
        if(h==NULL)
        {
            h=q;
            l=q;
            q->next=NULL;
        }
        else
        {
            l->next=q;
            l=q;
            l->next=NULL;
        }
        q=NULL;
        p=p->next;
    }
    //p=head;
    r=h;
    while(r!=NULL)
    {
        q=head;
        l=h;
        while(q!=r->arb)
        {
            q=q->next;
            l=l->next;
        }
        r->arb=l;
        r=r->next;
        //p=p->next;
    }
    return h;
}

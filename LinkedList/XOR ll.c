An ordinary Doubly Linked List requires space for two address fields to store the addresses of previous and next nodes. A memory efficient version of Doubly Linked List can be created using only one space for address field with every node. This memory efficient Doubly Linked List is called XOR Linked List or Memory Efficient as the list uses bit-wise XOR operation to save space for one address.
Given stream of data of size N for the linked list, your task is to complete the function insert() and printList(). The insert() function pushes (or inserts at beginning) the given data in the linked list and the printList() function prints the linked list first in forward direction and then in backward direction.
Note: There is an utility function XOR() that takes two Node pointer to get the bit-wise XOR of the two Node pointer. Use this function to get the XOR of the two pointers. 

Input:
The insert function takes 2 arguments as input, first the reference pointer to the head of the linked list and an integer data to be inserted in the linked list.
The printList function takes a single argument as input the reference pointer to the head of the linked list.
There are multiple test cases and for each test the function will be called separately. 

Output:
For each test function printList first should print the linked list in the forward direction and then in the backward direction.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
6
9 5 4 7 3 10
3
58 96 31
Output:
10 3 7 4 5 9
9 5 4 7 3 10
31 96 58
58 96 31

--CODE--

void insert(struct Node **head_ref, int data)
{
	Node *p,*q;
	p=*head_ref;
	q=(Node*)malloc(sizeof(Node));
	q->data=data;
	q->npx=p;
	if(p!=NULL)
	{
	    p->npx=XOR(p->npx,q);
	}
	*head_ref=q;
	q=NULL;
}
// function should prints the contents of doubly linked list
// first in forward direction and then in backward direction
// you should print a next line after printing in forward direction
void printList (struct Node *head)
{
	Node *q,*p,*r;
	q=head;
	p=head->npx;
	while(p!=NULL)
	{
	    printf("%d ",q->data);
	    r=p;
	    p=XOR(p->npx,q);
	    q=r;
	}
	printf("%d ",q->data);
	printf("\n");
	while(q!=head)
	{
	    r=XOR(q->npx,p);
	    printf("%d ",q->data);
	    p=q;
	    q=r;
	}
	printf("%d",q->data);
}

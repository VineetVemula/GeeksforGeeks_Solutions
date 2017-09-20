Given a singly linked list and a number k, write a function to find the (n/k)-th element, where n is the number of elements in the list. We need to consider ceil value in case of decimals.

Input:

The first line of input contains an integer T denoting the number of test cases. The first line of each test case consists of an integer n. The second line consists of n spaced integers.The last line consists of an integer k. 

Output:
Print the data value of (n/k)th node in the Linked List.

Constraints: 
1<=T<=100
1<=n<=100

Example:
Input:
2
6
1 2 3 4 5 6
2
5
2 7 9 3 5
3

Output:
3
7

--CODE--

int fractional_node(struct node *head, int k)
{
 int n=0,i;
 float u;
 node* p;
 p=head;
 while(p!=NULL)
 {
     p=p->next;
     n++;
 }
 u=(float)n/k;
 ceil(u);
 p=head;
 for(i=1;i<u;i++)
 {
    p=p->next; 
 }
 return p->data;
}

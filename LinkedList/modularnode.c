Given a singly linked list and a number K, your are required to complete the function modularNode(), that return the modular node of the linked list.
A modular node is the last node of the linked list whose Index is divisible by the number K, i.e. i%k==0.

Input : list = 1->2->3->4->5->6->7
        k = 3
Output : 6
Input : list = 3->7->1->9->8
        k = 2
Output : 9
Input:
The function takes two arguments as input, the reference pointer to the head of the linked list and an integer K.
There will be T, test cases and for each test the function will be called separately.

Output:
For each test case the function must return the modular Node data, if no such node is possible then return "-1".

Constraints:
1<=T<=100
1<=N<=500

Example:
Input:
2
7
1 2 3 4 5 6 7
3
5
19 28 37 46 55
2
Output:
6
46

--CODE--

int modularNode(Node* head, int k)
{
 int n=0,i,u;
 Node* p;
 p=head;
 while(p!=NULL)
 {
     p=p->next;
     n++;
 }
 u=n/k;
 u=k*u;
 if(u==0)
    return -1;
 p=head;
 for(i=1;i<u;i++)
 {
    p=p->next; 
 }
 return p->data;
}

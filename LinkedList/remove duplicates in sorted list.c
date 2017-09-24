Complete the removeDuplicates() function which takes a list sorted in non-decreasing order and deletes any duplicate nodes from the list. The list should only be traversed once.

For example if the linked list is 11->11->11->21->43->43->60 then removeDuplicates() should convert the list to 11->21->43->60.

Input:
You have to complete the method which takes 1 argument: the head of the  linked list  .You should not read any input from stdin/console. There are multiple test cases. For each test case this method will be called individually.

Output:
Your function should return a pointer to a linked list with no duplicate element.

Constraints:
1<=T<=100
1<=size of linked lists<=50

Note: If you use "Test" or "Expected Output Button" use below example format.

Example:
Input
2
4
2 2 4 5
5
2 2 2 2 2

Output
2 4 5
2

--CODE--

Node *removeDuplicates(Node *root)
{
 Node *p,*q;
 int c=root->data;
 p=root;
 while(p->next!=NULL)
 {
    if(p->next->data==c)
    {
        p->next=p->next->next;
    }
    else
    {
        p=p->next;
        c=p->data;
    }
 }
 return root;
}

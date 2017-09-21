You are given a pointer/reference to a node to be deleted in a linked list. The task is to delete the node.  Pointer/reference to head node is not given. 

You may assume that the node to be deleted is not the last node.

Input:

You have to complete a method which takes one argument: pointer/reference to a node to be deleted.  There are multiple test cases. For each test case, this method will be called individually.


Example:
Input
2
2
1 2
1
4
10 20 4 30
20

Output
2
10 4 30



--CODE--



void deleteNode(Node *node)
{
   Node* e;
   e=node;
   while(e->next->next!=NULL)
   {
       e->data=e->next->data;
       e=e->next;
   }
   e->data=e->next->data;
   e->next=NULL;
}

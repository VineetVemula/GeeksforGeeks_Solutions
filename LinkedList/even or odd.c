Given a linked list of size N, your task is to complete the function isLengthEvenOrOdd() which check whether the length of linked list is even or odd.

Input:
The function takes a single argument as input, the reference pointer to the head of the linked list.
There will be T test cases and for each test case the function will be called separately.

Output:
For each test the, If the length of the list is even then function should return 0 else return 1.

Constraints:
1<=T<=100
1<=N<=103
1<=A[]<=103

Example:
Input:
2
3
9 4 3
6
12 52 10 47 95 0
Output:
Odd
Even

--CODE--


int isLengthEvenOrOdd(struct Node* head)
{
     int c=0;
     Node *last;
     last=head;
     while(last!=NULL)
     {
         last=last->next;
         c++;
     }
     if(c%2==1)
        return 1;
    else return 0;
}

Given a singly linked list of 0s and 1s find its decimal equivalent

   Input  : 0->0->0->1->1->0->0->1->0
   Output : 50
   
Decimal Value of an empty linked list is considered as 0.

Since the answer can be very large, answer modulo 1000000007 should be printed.

Input:
The task is to complete the method which takes one argument: the head of the linked list. The struct Node has a data part which stores the data and a next pointer which points to the next element of the linked list. 
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should return should decimal equivalent modulo 1000000007

Constraints:
1 <=T<= 200
0 <=N<= 100
Data of Node is either 0 or 1

Example:
Input:
2
3
0 1 1    
4
1 1 1 0

Output:
3
14

--CODE--

my sol did not work

Given a singly linked list of 0s and 1s find its decimal equivalent

   Input  : 0->0->0->1->1->0->0->1->0
   Output : 50
   
Decimal Value of an empty linked list is considered as 0.

Since the answer can be very large, answer modulo 1000000007 should be printed.

Input:
The task is to complete the method which takes one argument: the head of the linked list. The struct Node has a data part which stores the data and a next pointer which points to the next element of the linked list. 
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should return should decimal equivalent modulo 1000000007

Constraints:
1 <=T<= 200
0 <=N<= 100
Data of Node is either 0 or 1

Example:
Input:
2
3
0 1 1    
4
1 1 1 0

Output:
3
14

correct sol

long long unsigned int decimalValue(Node *head)
{
   // Your Code Here
   long long unsigned int num = 0;
    while(head){
        num = (num % 1000000007) * 2 + head->data;
        
        head = head ->next;
    }
    
    return num % 1000000007;
}

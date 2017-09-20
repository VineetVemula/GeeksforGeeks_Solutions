The task is to complete the function  multiplyTwoLists which multiplies two linked lists l1 and l2 and returns their product . The function takes two linked list l1, l2 as its arguments. 

Note: The output could be large take modulo 10^9+7.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. The first line of each test case contains an integer n denoting the size of the first linked list (l1)  In the next  line are the space separated values of the first linked list. The third line of each test case contains an integer m denoting the size of the second linked list (l2). In the forth line are space separated values of the second linked list .

Output:
For each test case output will be an integer denoting the product of the two linked list.

Constraints:
1<=T<=100
1<=n,m<=100

Example(To be used only for expected output):
Input
2
2
3 2
1
2
3
1 0 0
2
1 0 
Output
64
1000


--CODE--

long long  multiplyTwoLists (Node* l1, Node* l2)
{
  long long num1=0,num2=0,num3=1000000007;
  Node* f,*s;
  s=l1;
  f=l2;
  while(s!=NULL)
  {
      num1=(num1*10)%num3+s->data;
      s=s->next;
  }
  while(f!=NULL)
  {
      num2=(num2*10)%num3+f->data;
      f=f->next;
  }
  return ((num1*num2)%num3);
}

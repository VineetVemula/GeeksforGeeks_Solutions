Given a linked list of strings having n nodes check to see whether the combined string formed is palindrome or not. 

Input:
You have to complete the method which takes one argument: the head of the linked list . You should not read any input from stdin/console.. There are multiple test cases. For each test case, this method will be called individually.

Output:
Your function should return True if the combined string is pallindrome else it should return False.

Constraints:
1 <=T<= 103
1 <=n<= 103
Example:
Input :
2
5
a bc d dcb a
4
a bc d ba
 

Output :
True
False

Explanation:
case 1 : as String "abcddcba" is palindrome the function should return true
case 2 : as String "abcdba" is not palindrome the function should return false

--CODE--

#include<string.h>
bool Compute(Node* root)
{
    //Your code goes here
   string a1,a2;
   while(root!=NULL)
   {
       a1=a1+root->data;
       root=root->next;
   }
   a2=a1;
   reverse(a1.begin(),a1.end());
   if(a1.compare(a2)==0)
   return true;
   else
   return false;
}

Given a binary search tree and a number N. Your task is to complete the function findMaxforKey(), that find's the greatest number in the binary search tree that is less than or equal to N. Print the value of the element if it exists otherwise print -1.


Input : N = 24
Output :result = 21
(searching for 24 will be like-5->12->21)

Input  : N = 4
Output : result = 3
(searching for 4 will be like-5->2->3)
Input:
The function takes two argument as input, the reference pointer to the root of the binary search tree and integer value N.
There will be T, test cases and for each test case the function will be called separately.

Output:
For each test case print the greatest number in the binary search tree that is less than or equal to N

Constraints:
1<=T<=100
1<=N<=103

Example:
Input:
2
5
5 1 3 7 9
8
9
5 2 1 3 12 9 21 19 25
4
Output:
7
3

--code--


int findMaxforN(Node* root, int N)
{
    Node * temp;
    temp=root;
	while(temp!=NULL)
	{
        if(temp->key==N)
            return N;
        if(N>temp->key)
        {
            if(temp->right==NULL)
                return temp->key;
            if(temp->right->key>N)
                return temp->key;
            else
            {
                temp=temp->right;
                continue;
            }
            
        }
        if(N<temp->key)
        {
            if(temp->left==NULL)
                return -1;
            else
            {
                temp=temp->left;
            }
        }
	}
}

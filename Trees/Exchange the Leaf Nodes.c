Given a binary tree of size N, your task is to complete the function pairwiseSwap(), that swap leaf nodes in the given binary tree pairwise starting from from left to right.
Example:

Tree before swapping:


Tree after swapping:

The sequence of leaf nodes in original binary tree
 from left to right is (4, 6, 7, 9, 10). Now if we 
try to form pairs from this sequence, we will have 
two pairs as (4, 6), (7, 9). The last node (10) is 
unable to form pair with any node and thus left unswapped
Input:
The function takes a single arguemnt as input, the reference pointer to the root of the binary Tree.
There will be T, test cases and for each test case the function will be called separately.

Output:
For each test case print the inorder traversal of the new tree on a new line.

Constraints:
1<=T<=103
1<=N<=103

Example:
Input:
1
9
1 2 L 2 4 L 1 3 R 3 5 L 3 8 R 5 6 L 5 7 R 8 9 L 8 10 R
Output:
6 2 1 4 5 9 3 7 8 10 

--code--

Given a binary tree of size N, your task is to complete the function pairwiseSwap(), that swap leaf nodes in the given binary tree pairwise starting from from left to right.
Example:

Tree before swapping:


Tree after swapping:

The sequence of leaf nodes in original binary tree
 from left to right is (4, 6, 7, 9, 10). Now if we 
try to form pairs from this sequence, we will have 
two pairs as (4, 6), (7, 9). The last node (10) is 
unable to form pair with any node and thus left unswapped
Input:
The function takes a single arguemnt as input, the reference pointer to the root of the binary Tree.
There will be T, test cases and for each test case the function will be called separately.

Output:
For each test case print the inorder traversal of the new tree on a new line.

Constraints:
1<=T<=103
1<=N<=103

Example:
Input:
1
9
1 2 L 2 4 L 1 3 R 3 5 L 3 8 R 5 6 L 5 7 R 8 9 L 8 10 R
Output:
6 2 1 4 5 9 3 7 8 10 

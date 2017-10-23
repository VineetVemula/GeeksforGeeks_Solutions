Given a binary tree of size N. Your task is to complete the function sumOfLongRootToLeafPath(), that find the sum of all nodes on the longest path from root to leaf node.
If two or more paths compete for the longest path, then the path having maximum sum of nodes is being considered.

Examples:

Input : Binary tree:
        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3    
      /
     6
Output : 13

        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3 
      /
     6

The highlighted nodes (4, 2, 1, 6) above are 
part of the longest root to leaf path having
sum = (4 + 2 + 1 + 6) = 13
Input:
The function takes a single argument as input the reference pointer to the root of the binary tree.
There will be T, test cases and for each test case the function will be called separately.

Output:
For each test case print the required sum on a new line.

Constraints:
1<=T<=103
1<=N<=103

Example:
Input:
2
2
1 2 L 1 3 R
7
4 2 L 4 5 R 2 7 L 2 1 R 1 6 L 5 2 L 5 3 R
Output:
4
13

--code--

void in(Node *x,int l,int* level,int *max,int*m)
{
    if(x!=NULL)
    {
        *m=*m + x->data;
        if(l>=*level)
        {
            *level=l;
            if(*max<*m)
            {
                *max=*m;
            }
        }
        in(x->left,l+1,level,max,m);
        in(x->right,l+1,level,max,m);
        *m=*m - x->data;
    }
}
int sumOfLongRootToLeafPath(Node* root)
{
	int n=0,lev=0,b=0;
	int* level,*max,*m;
	m=&n;
	max=&b;
	level=&lev;
	in(root,0,level,max,m);
	return b;
}

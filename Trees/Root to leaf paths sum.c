Given a binary tree, where every node value is a number . Find the sum of all the numbers which are formed from root to leaf paths.

For example consider the following Binary Tree.
 

           6                               
         /   \                          
        3     5                      
      /   \     \
     2    5      4             
        /  \                        
       7    4                 
            
  There are 4 leaves, hence 4 root to leaf paths:
  Path                      Number
  6->3->2                   632
  6->3->5->7                6357
  6->3->5->4                6354
  6->5>4                    654   
Answer = 632 + 6357 + 6354 + 654 = 13997 

Input:
The task is to complete the method which takes one argument, root of Binary Tree. The Node has a data part which stores the data, pointer to left child and pointer to right child. There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should return sum of all the numbers which are formed from root to leaf paths.

Constraints:
1 <=T<= 30
1 <=Number of nodes<= 100
1 <=Data of a node<= 1000

Example:
Input:
2
2
1 2 L 1 3 R
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
25
2630

--code--

int arr[1000];
int n=0;
long long ans=0,answer=0;
long long treePathsSum(Node *root)
{
    if(root!=NULL)
    {
    int sum=0;
    arr[n++]=root->data;
    if(root->left==NULL && root->right==NULL)
    {
        int i=0;
        for(i=0;i<n;i++)
        {
            sum=sum*10+arr[i];
        }
        ans=ans+sum;
    }
    treePathsSum(root->left);
    treePathsSum(root->right);
    n--;
    }
    if(n==0)
    {
        answer=ans;
        ans=0;
    }
    return answer;
}

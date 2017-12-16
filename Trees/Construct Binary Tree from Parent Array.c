Given an array that represents a Tree in such a way that array indexes are values in tree nodes and array values give the parent node of that particular index (or node). The value of the root node index would always be -1 as there is no parent for root. Construct the standard linked representation of given Binary Tree from this given representation.

The Binary tree  node structure has 3 fields, a data part which stores the data, a left pointer which points to the left element of the tree and a right pointer which points to the right node of the  tree. 

There are multiple test cases. For each test case, this function will be called individually.

Input:
The first line of the input contains an integer 'T' denoting the number of test cases. Then 'T' test cases follow. Each test case consists of two lines. First line of each test case contains an integer N denoting the size of the tree array . Second line of each test case consists of 'N' space separated integers denoting the elements of the array . 

Output:
The Output will be the sorted level order traversal of the tree you are only required to return the modified tree root.

Expected Time Complexity: O(N)

Constraints:
1<=T<=100
1<=N<=200

Example:
Input:
1
7
-1 0 0 1 1 3 5     

Output:
0 1 2 3 4 5 6       (Sorted Level Order  Traversal of the constructed tree)

Explanation:
 

For the array parent[] = {-1, 0, 0, 1, 1, 3, 5};
the tree generated will have a sturcture like  
         0
       /   \
      1     2
     / \
    3   4
   /
  5 
 /
6

--code--

Node *createTree(int parent[], int n)
{
    Node * q[1000],*p,*y,*v;
    q[0]=NULL;
    int i=0;
    for(i=0;i<n;i++)
    {
        p=(Node *)malloc(sizeof(Node));
        p->data=i;
        p->left=NULL;
        p->right=NULL;
        q[i]=p;
        p=NULL;
    }
    i=0;
    while(i<n)
    {
        p=q[i];
        if(parent[i]==-1)
        {
            v=p;
            i++;
            continue;
        }
        y=q[parent[i]];
        if(y->left==NULL)
            y->left=p;
        else y->right=p;
        i++;
    }
    return v;
}

Reverse Level Order Traversal (Function Problem)
Show Topic Tags         Adobe    Amazon    Flipkart    Microsoft
Write a function to print Reverse Level Order Traversal of a tree. For below tree, function should print 4 5 2  3 1 .
                                              
                                           

 

Input:
The task is to complete the method which takes one argument, root of the Tree. The struct node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.


Output:
The function should print reverse level order traversal of the tree.

Constraints:
1 <=T<= 30
1 <=Number of nodes<= 100
1 <=Data of a node<= 1000

Example:
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R
 

Output:
3 2 1
40 60 20 30 10

--code--

void reversePrint(Node* root)
{
    int i=0,j,s=0,arr[3000],r;
    Node * a[3000], *x;
    int l=0,m=0;
    int level[1000];
    level[0]=0;
    a[i]=root;
    i++;
    
    while(s!=i)
    {
    x=a[(s)++];
    if(l!=level[(s)-1])
    {
        l++;
    }
    arr[m++]=x->data;
    
     if(x->right!=NULL)
    {
        level[i]=l+1;
        a[(i)++]=x->right;
    }
     if(x->left!=NULL)
    {
        level[i]=l+1;
        a[(i)++]=x->left;
    }
    
    }
    for(r=m-1;r>=0;r--)
    {
        printf("%d ",arr[r]);
    }
}

Given a Binary Tree and a target key, your task is to complete the function printAncestors() that prints all the ancestors of the key in the given binary tree.

              1
            /   \
          2      3
        /  \
      4     5
     /
    7
Key: 7
Ancestor: 4 2 1
Input:
The function takes 2 arguments as input, first the reference pointer to the root node of the binary tree and a integer value target. There will be multiple test cases and for each test the function will be called seperately.
Output:
For each test print all the ancestors of the target vlue in the order of their hierarchy.
Constraints:
1<=T<=100
1<=N<=100
Example:
Input:
2
2
1 2 L 1 3 R
2
5
1 2 R 1 3 L 2 4 L 2 5 R 4 7 L
7
Ouput:
1
4 2 1

--code--

void in(Node *x,int a[],int m,int target,int* res)
{
    if(*res==0)
    {
        if(x!=NULL)
        {
            int i;
            if(x->data==target)
            {
                for(i=m-1;i>=0;i--)
                {
                    printf("%d ",a[i]);
                }
                //printf("\n");
                *res==1;
                return;
            }
            a[m++]=x->data;
            in(x->left,a,m,target,res);
            in(x->right,a,m,target,res);
        }
    }
}
bool printAncestors(struct Node *root, int target)
{
    int res=0,m=0,a[3000];
    if(root->data==target)
    {
        printf("\n");
        return 1;
    }
    in(root,a,m,target,&res);
    if(res==0)
        printf("\n");
    return 1;
}

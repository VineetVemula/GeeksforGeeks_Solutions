Given a Binary Tree your task is to print the nodes  which dont have a sibling node . You are required to complete the function printSibling. You should not read any input from stdin/console. There are multiple test cases. For each test case, this method will be called individually.

Input:
The task is to complete the function printSibling which takes 1 argument, root of the Tree .The struct node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should print all the nodes separated by space which don't have sibling in the tree in sorted order if every node has a tree than print -1.

Constraints:
1 <=T<= 30
1 <=Number of nodes<= 100
1 <=Data of a node<= 1000

Example:

Input
1
1
1 2 L 

Output 
2

--code--

void in(Node *x,int arr[],int*i,int status)
{
    if(x!=NULL)
    {
        int ls=0,rs=0;
        if(status==1)
        {
           arr[(*i)++]=x->data; 
        }
        if(x->right==NULL)
            ls=1;
        if(x->left==NULL)
            rs=1;
        in(x->left,arr,i,ls);
        in(x->right,arr,i,rs);
    }
}
void printSibling(Node* node)
{
   int arr[1000],i=0,j,k,temp;
   in(node,arr,&i,0);
   if(i==0)
    {
        printf("-1");
        return;
    }
   for(j=0;j<i-1;j++)
   {
        for(k=0;k<i-1;k++)
        {
            if(arr[k]>arr[k+1])
            {
                temp=arr[k];
                arr[k]=arr[k+1];
                arr[k+1]=temp;
            }
        }
   }
   for(j=0;j<i;j++)
   {
       printf("%d ",arr[j]);
   }
}

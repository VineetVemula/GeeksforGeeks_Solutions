Write a function to print spiral order traversal of a tree. For below tree, function should print 1, 2, 3, 4, 5, 6, 7.


 
 

Input:
The task is to complete the method which takes one argument, root of the Tree. The struct node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should print level order traversal in spiral form .

Constraints:
1 <=T<= 30
1 <=Number of nodes<= 3000
1 <=Data of a node<= 1000

Example:
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
1 3 2
10 20 30 60 40

--code--

void printSpiral(Node *root)
{

    int i=0,j,s=0,l=0,m=0,k,stac[3000],p=0,u=0,r;
    Node * a[3000], *x;
    int level[3000],arr[3000];
    level[0]=0;
    a[i]=root;
    i++;
    while(s!=i)
    {
    x=a[s++];
    if(l!=level[(s)-1])
    {
        l++;
    }

    arr[m++]=x->data;
    
     if(x->left!=NULL)
    {
        level[i]=l+1;
        a[(i)++]=x->left;
    }
     if(x->right!=NULL)
    {
        level[i]=l+1;
        a[(i)++]=x->right;
    }
    }
    
    for(j=0;j<m;j++)
    {
        if(level[j]%2==0)
        {
            stac[p++]=arr[j]; 
            u=1;
        }
        else
        {
            if(u==1)
            {
            for(r=p-1;r>=0;r--)
            {
                printf("%d ",stac[r]);
            }
            p=0;
            u=0;
            }
            printf("%d ",arr[j]);
        }
    }
    if(u==1)
    {
    for(r=p-1;r>=0;r--)
    {
        printf("%d ",stac[r]);
    }
    }
}

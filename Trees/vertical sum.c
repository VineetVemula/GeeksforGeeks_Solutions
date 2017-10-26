Given a Binary Tree, find vertical sum of the nodes that are in same vertical line. Print all sums through different vertical lines.

Input:
First line of every test case consists of T test case. First line of every test case consists of N, denoting number of nodes. Second line of every test case consists of 3*N elements denoting , 2 integers and 1 character ,i.e., parent node , child node and character denotes which child.

Output:
Single line output, print the vertical sum from left to right.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
3
5 2 L 5 3 R 2 1 L
5
5 3 R 5 2 L 2 1 L 2 7 R 3 6 L
Output:
1 2 5 3 
1 2 18 3 

--code--

void in(Node* x, int a[][2],int * m,int h)
{
    if(x!=NULL)
    {
        a[*m][0]=h;
        a[*m][1]=x->data;
        (*m)++;
        in(x->left,a,m,h-1);
        in(x->right,a,m,h+1);
    }
}
void printVertical(Node *root)
{
    int a[3000][2],i,j,temp,size=0,hi,sum=0;
    if(root==NULL)
    {
        printf("$");
        return;
    }
    in(root,a,&size,0);
    
    for(i=0;i<size-1;i++)
    {
        for(j=0;j<size-1;j++)
        {
            if(a[j][0]>a[j+1][0])
            {
                temp=a[j][0];
                a[j][0]=a[j+1][0];
                a[j+1][0]=temp;
                temp=a[j][1];
                a[j][1]=a[j+1][1];
                a[j+1][1]=temp;
            }
        }
    }
    hi=a[0][0];
    for(i=0;i<size;i++)
    {
        if(hi!=a[i][0])
        {
            printf("%d ",sum);
            hi=a[i][0];
            sum=0;
        }
        sum=sum+a[i][1];
    }
    printf("%d",sum);
}

Given a Binary Tree, Print the corner nodes at each level. The node at the leftmost and the node at the rightmost.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an intger n denoting the number of edges. The next line contains the edges of the binary tree.

Output:
Print the corner nodes ( nodes at the leftmost and nodes at the rightmost) at each level.

Constraints:
1<=T<=100
1<=data of each node<=100
1<=n<=100

Example:
Input:
2
6
15 10 L 10 8 L 10 12 R 15 20 R 20 16 L 20 25 R
2
1 2 R 2 3 R

Output:
15 10 20 8 25
1 2 3

--code--

int funct(Node *a[],int *i,int*s,int q[][100],int index[])
{
    Node *x,*p;
    int l=0;
    int level[1000],child[100];
    level[0]=0;
    while(*s!=*i)
    {
    x=a[(*s)++];
    if(l!=level[(*s)-1])
    {
        l++;
    }
    q[l][++index[l]]=x->key;
     if(x->left!=NULL)
    {
        level[*i]=l+1;
        a[(*i)++]=x->left;
    }
     if(x->right!=NULL)
    {
        level[*i]=l+1;
        a[(*i)++]=x->right;
    }
    
    }
    return l;
}
void printCorner(Node *root)
{
    int io=0,j,s=0,q[100][100],index[100],max,i;
    int *in=&io,*st=&s;
    Node * a[1000];
    a[io]=root;
    io++;
    for(i=0;i<100;i++)
    {
        index[i]=-1;
    }
    max=funct(a,in,st,q,index);
    printf("%d ",q[0][0]);
    for(i=1;i<=max;i++)
    {
        printf("%d ",q[i][0]);
        if(index[i]!=0)
            printf("%d ",q[i][index[i]]);
    }
}

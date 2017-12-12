Given a binary tree and two node values your task is to find the minimum distance between them.

Input:
The task is to complete the fuction findDist which takes 3 argument, the  root of the  Binary Tree and two node values a and b .
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should return min distance between two node values .

Constraints:
1 <=T<= 30
1 <=Number of nodes<= 100
1 <=Data of a node<= 1000

Example:
Input
1
2
1 2 L 1 3 R
2 3 

Output
2

--code--

Node* arr[100];
int o;
void in(Node * x,Node* a[],Node* b[],int na,int nb,int *n,int m,int* l1,int* l2)
{
    if(x!=NULL)
    {
        arr[m]=x;
        if(x->data==na)
        {
            for(o=0;o<=m;o++)
            {
                a[o]=arr[o];
            }
            *l1=m;
        }
        if(x->data==nb)
        {
            for(o=0;o<=m;o++)
            {
                b[o]=arr[o];
            }
            *l2=m;
        }
        in(x->left,a,b,na,nb,n,m+1,l1,l2);
        (*n)++;
        in(x->right,a,b,na,nb,n,m+1,l1,l2);
    }
}
int findDist(Node* root, int a, int b)
{
    Node *au[101],*bu[101];
    int n=0,i,l1,l2,n1;
    /*if(n1==1 && n2==1)
    {
        p->data=1;
        return p;
    }*/
    in(root,au,bu,a,b,&n,0,&l1,&l2);
    if(l1>l2)
        n1=l1;
    else n1=l2;
    for(i=0;i<=n1;i++)
    {
        if(au[i]!=bu[i])
            break;
    }
    /*for(i=0;i<=n;i++)
    {
        arr[i]=NULL; 
    }*/
    return(l1-i+1+l2-i+1);
}

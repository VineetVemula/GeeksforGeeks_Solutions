Given a Binary Tree and 2 nodes value n1 and n2  , your task is to find the lowest common ancestor of the two nodes . You are required to complete the function LCA . You should not read any input from stdin/console. There are multiple test cases. For each test case, this method will be called individually.

Input:
The task is to complete the method LCA which takes 3 arguments, root of the Tree and two nodes value  n1 and n2 . The struct node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should return the node which is the least common ancestor of the two nodes n1 and n2 .

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
1

--code--

Node* arr[100];
int o;
void in(Node * x,Node* a[],Node* b[],int na,int nb,int *n,int m,int * l1,int*l2)
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
Node * LCA(Node* root ,int n1 ,int n2)
{
    Node * a[101],*b[101],*p;
    int n=0,i,np,l1,l2;
    /*if(n1==1 && n2==1)
    {
        p->data=1;
        return p;
    }*/
    in(root,a,b,n1,n2,&n,0,&l1,&l2);
    if(l1>l2)
        np=l1;
    else np=l2;
    for(i=0;i<=np;i++)
    {
        if(a[i]!=b[i])
            break;
    }
    p=b[i-1];
    return p;
}

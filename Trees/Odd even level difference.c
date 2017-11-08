Given a a Binary Tree, your task is to complete the function getLevelDiff which  returns the difference between the sum of nodes at odd level and the sum of nodes at even level . The function getLevelDiff  takes only one argument  ie the root of the binary tree . 

       2
     /    \
    3     5
For the above tree the odd level sum is 2 and even level sum is 8 thus the difference is 2-8=-6

Input:
The task is to complete the method which takes one argument, root of Binary Tree. There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should return an integer denoting the difference between the sum of nodes at odd level and the sum of nodes at even level

Constraints:
1 <=T<= 30
1 <= Number of nodes<= 20

Example:
Input
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output
-4
60

--code--

void funct(Node *a[],int *i,int*s,int *odd,int* even)
{
    Node *x,*p;
    int l=0;
    int level[1000];
    level[0]=0;
    
    while(*s!=*i)
    {
    x=a[(*s)++];
    if(l!=level[(*s)-1])
    {
        l++;
        //printf("$ ");
    }
    //printf("%d ",x->data);
    if(l%2==0)
    {
        *odd = *odd + x->data;
    }
    else *even = *even + x->data;
    if(x->left!=NULL && x->right!=NULL)
    {
        level[*i]=l+1;
        a[(*i)++]=x->left;
        level[*i]=l+1;
        a[(*i)++]=x->right;
    }
     if(x->left!=NULL && x->right==NULL)
    {
        level[*i]=l+1;
        a[(*i)++]=x->left;
    }
     if(x->right!=NULL && x->left==NULL)
    {
        level[*i]=l+1;
        a[(*i)++]=x->right;
    }
    
    }
    
}
int getLevelDiff(Node *root)
{
    int io=0,j,s=0,odd=0,even=0;
    int *in=&io,*st=&s;
    Node * a[1000];
    a[io]=root;
    io++;
    funct(a,in,st,&odd,&even);
    return(odd-even);
}

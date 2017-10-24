Given  two  binary trees, your task is to find if both of them are identical or not .  

Input:
The task is to complete the method which takes 2 argument, the  roots r1 and r2  of the  Binary Trees. The struct Node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should return true if both trees are identical  else false.

Constraints:
1 <=T<= 30
1 <=Number of nodes<= 100
1 <=Data of a node<= 1000

Example:
Input
2
2
1 2 L 1 3 R
2
1 2 L 1 3 R
2
1 2 L 1 3 R
2
1 3 L 1 2 R

Output
1
0

--code--

void in(Node *x,Node * y,int * res)
{
    if(*res==1)
    {
        if((x==NULL && y!=NULL) || (x!=NULL && y==NULL))
        {
            *res=0;
            return;
        }
        if(x!=NULL && y!=NULL)
        {
            if(x->data!=y->data)
            {
                *res=0;
                return;
            }
            in(x->left,y->left,res);
            in(x->right,y->right,res);
        }
    }
}
bool isIdentical(Node *r1, Node *r2)
{
    int result=1;
    in(r1,r2,&result);
    if(result==1)
        return true;
    else return false;
}

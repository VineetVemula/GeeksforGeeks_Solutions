Given two binary trees, the task is to complete function isSubtree, which takes two argument. First argument to the function is root of binary tree T1 and Second argument is root of tree T2. Check if the  tree T2 is subtree of the  tree T1.
A subtree of a tree T1 is a tree T2 consisting of a node in T1 and all of its descendants in T1.

Example:

T2:          10
              /   \
            4     6
                 /
             30

T1:                  26
                      /   \
                    10   3
                   /   \     \

               4       6     3
                       /
                    30

In above example T2 is subtree of T1.

Input:

The task is to complete the method . There are multiple test cases. For each test case, this method will be called individually.

Output:

Return 1 if T2 is a subtree of T1, else 0.

Constraints:
1 <=T<= 30
1 <= Number of nodes <= 20

Example:
Input:
2
5
26 10 L 10 20 L 10 30 R 20 40 L 20 60 R
5
26 10 L 10 20 L 10 30 R 20 40 L 20 60 R

3
10 4 L 10 6 R 4 30 R
6
26 10 L 26 3 R 10 4 L 10 6 R 6 25 R 3 3 R

Output:
1
0

--code--

bool same (Node * x,Node * y)
{
    if(x!=NULL && y!=NULL)
    {
        if(x->key==y->key)
        {
            return(same(x->left,y->left) && same(x->right,y->right));
        }
        else return false;
    }
    else if(x==NULL && y==NULL)
        return true;
    else return false;
}
void find(Node * root,Node * v,Node ** x)
{
    if(*x == NULL && root!=NULL)
    {
        if(root->key==v->key)
        {
            *x=root;
        }
        find(root->left,v,x);
        find(root->right,v,x);
    }
}
bool isSubtree(Node*  T1 ,Node * T2)
{
    //Your code here 
    //return 1 if T2 is subtree of T1 else 0
    Node * p=NULL;
    find(T1,T2,&p);
    return(same(p,T2));
}

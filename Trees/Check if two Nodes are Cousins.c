Given the binary Tree and the two nodes say ‘a’ and ‘b’, determine whether the two nodes are cousins of each other or not.

Two nodes are cousins of each other if they are at same level and have different parents.

Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.

Input:
First line consists of T test cases. First line consists of a integer N denoting number of nodes. Second line consists of N triplets consisting of 2 integers and a character. Third line consists of 2 integers to check whether they are cousins or not.

Output:
Single line output, print "1" if they are cousins else "0". You don't have to print just return true or false.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
2
1 2 L 1 3 R
2 3
4
1 2 L 1 3 R 3 4 R 2 5 L
4 5
Output:
0
1

--code--

void in(Node* x,Node *a,Node *b,int l,int *level,int *res)
{
    if(x!=NULL && (x->left!=NULL || x->right!=NULL) && (*res)==-1)
    {
        if((x->left!=NULL && x->right!=NULL) && ((x->left->data==a->data && x->right->data==b->data) || (x->left->data==b->data && x->right->data==a->data)))
        {
            *res=0;
        }

        else if(x->left!=NULL && (x->left->data==a->data || x->left->data==b->data))
        {
            if((*level)==-1)
            {
                (*level)=l+1;
            }
            else if(l+1!=(*level))
            {
                (*res)=0;
            }
            else 
            {
                (*res)=1;
            }
        }
        else if(x->right!=NULL && (x->right->data==a->data || x->right->data==b->data))
        {
            if((*level)==-1)
            {
                (*level)=l+1;
            }
            else if(l+1!=(*level))
            {
                (*res)=0;
            }
            else 
            {
                (*res)=1;
            }
        }
        
        in(x->left,a,b,l+1,level,res);
        in(x->right,a,b,l+1,level,res);
    }
}
bool ifCousin(Node *root,Node *a,Node *b)
{
    int r=-1,lev=-1;
    if(root==a || root==b)
        return 0;
    if(a->data==b->data)
        return true;
    in(root,a,b,0,&lev,&r);
    if(r==1)
        return true;
    else return false;
}

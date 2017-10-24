Given a Binary Tree, find diameter of it.  The diameter of a tree is the number of nodes on the longest path between two leaves in the tree. The diagram below shows two trees each with diameter nine, the leaves that form the ends of a longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes).



Input:
The task is to complete the method which takes one argument, root of Binary Tree. The struct Node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should return diameter of binary tree.

Constraints:
1 <=T<= 30
1 <=Number of nodes<= 100
1 <=Data of a node<= 1000

Example:
Input:
2
2
1 2 L 1 3 R
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
3
4

--code--

int in(Node *x,int* max)
{
    if(x==NULL)
        return 0;
    if(x!=NULL)
    {
        int ls,rs;
        ls=in(x->left,max);
        rs=in(x->right,max);
        if(*max<ls+rs+1)
            *max=(ls+rs+1);
        if(ls>rs)
            return ls+1;
        else return rs+1;
    }
}

int diameter(Node* node)
{
    int max=0,rls,rrs;
    if(node==NULL)
        return -1;
    rls=in(node->left,&max);
    rrs=in(node->right,&max);
    
    if(max<(rls+rrs+1))
        max=(rls+rrs+1);
    return max;
}

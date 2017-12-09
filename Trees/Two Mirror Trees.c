Given a Two Binary Trees, write a function that returns true if one is mirror of other, else returns false.


MirrorTree1            

Input:
The task is to complete the method that takes two arguments, roots of two Binary Trees to be checked for mirror.

Output:
The function should return true if first tree is mirror of second.

Constraints:
1 <=T<= 30
1 <= Number of nodes<= 100
1 <= Data of a node<= 1000

Example:
Input:
2
2 2
1 2 R 1 3 L
1 3 R 1 2 L
4 4
10 20 L 10 30 R 20 40 L 20 60 R
10 20 L 10 30 R 20 40 L 20 60 R

Output:
1
0

--code--

int areMirror(Node* a, Node* b)
{
   int j=0,i=0;
   if(a!=NULL && b!=NULL)
   {
        if(a->left!=NULL && b->right!=NULL && a->right!=NULL && b->left!=NULL)
        {
            if(a->left->data==b->right->data && b->left->data==a->right->data)
            {
                j=areMirror(a->right,b->left);
                i=areMirror(a->left,b->right);
            }
        }
        else if(a->left!=NULL && b->right!=NULL && a->right==NULL && b->left==NULL)
        {
            if(a->left->data==b->right->data)
            {
                i=areMirror(a->left,b->right);
                j=1;
            }
        }
        
        else if(a->left==NULL && b->right==NULL && a->right!=NULL && b->left!=NULL)
        {
            if(b->left->data==a->right->data)
            {
                j=areMirror(a->right,b->left);
                i=1;
            }
        }
        else if(a->left==NULL && b->right==NULL && a->right==NULL && b->left==NULL)
        {
            i=1;
            j=1;
        }
        else return 0;
        
        return(i*j);
   }
   else if(a==NULL && b==NULL)
        return 1;
    else return 0;
}

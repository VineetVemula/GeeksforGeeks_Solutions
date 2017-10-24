Given a Binary Tree,  print the bottom view from left to right. A node x is there in output if x is the bottommost node at its horizontal distance from root. Horizontal distance of left child of a node x is equal to horizontal distance of x minus 1, and that of right child is horizontal distance of x plus 1.

Examples:

                      20
                    /    \
                  8       22
                /   \        \
              5      3       25
                    /   \      
                  10    14

For the above tree the output should be 5, 10, 3, 14, 25.

If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal. For example, in the below diagram, 3 and 4 are both the bottom-most nodes at horizontal distance 0, we need to print 4.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \      
                 10       14

For the above tree the output should be 5, 10, 4, 14, 25.

Input:
The task is to complete the method which takes one argument, root of Binary Tree. The struct Node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should print nodes in bottom view of Binary Tree.  Your code should not print a newline, it is added by the caller code that runs your function.

Constraints:
1 <=T<= 30
0 <= Number of nodes<= 100
0 <= Data of a node<= 1000

Example:
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
3 1 2
40 20 60 30

--code--

void in(Node* x, int a[][3],int l,int h)
{
    if(x!=NULL)
    {
        int i;
        for(i=0;i<150 && a[i][1]!=-1;i++)
        {
            if(a[i][0]==h)
                break;
        }
        if(a[i][1]==-1)
        {
            a[i][0]=h;
            a[i][1]=x->data;
            a[i][2]=l;
        }
        else
        {
            if(a[i][2]<=l)
            {
                a[i][1]=x->data;
                a[i][2]=l;
            }
        }
        in(x->left,a,l+1,h-1);
        in(x->right,a,l+1,h+1);
    }
}
void bottomView(Node *root)
{
    int a[150][3],i,j,temp,size;
    for(i=0;i<150;i++)
    {
        a[i][0]=999;
        a[i][1]=a[i][2]=-1;
    }
    in(root,a,0,0);
    for(i=0;i<150 && a[i][1]!=-1;i++)
    {
    }
    size=i;
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
                temp=a[j][2];
                a[j][2]=a[j+1][2];
                a[j+1][2]=temp;
            }
        }
    }
    for(i=0;i<size;i++)
    {
        printf("%d ",a[i][1]);
    }
    
}

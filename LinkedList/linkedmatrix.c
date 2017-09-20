Given a Matrix mat of N*N size, the task is to complete the function constructLinkedMatrix(), that constructs a 2D linked list representation of the given matrix.

Input : 2D matrix 
1 2 3
4 5 6
7 8 9

Output :
1 -> 2 -> 3 -> NULL
|    |    |
v    v    v
4 -> 5 -> 6 -> NULL
|    |    |
v    v    v
7 -> 8 -> 9 -> NULL
|    |    |
v    v    v
NULL NULL NULL
Input:
The fuction takes 2 argument as input, first the 2D matrix mat[][] and second an integer variable N, denoting the size of the matrix.
There will be T test cases and for each test case the function will be called separately.

Output:
The function must return the reference pointer to the head of the linked list.

Constraints:
1<=T<=100
1<=N<=150

Example:
Input:
2
3
1 2 3 4 5 6 7 8 9
2
1 2 3 4
Output:
1 2 3 4 5 6 7 8 9
1 2 3 4

--CODE--

Node* constructLinkedMatrix(int mat[MAX][MAX], int n)
{
    Node*p,*q,*r,*d;
    int i,j,k,l;
    r=(Node*)malloc(sizeof(Node));
    p=r;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            p=r;
            for(k=0;k<i;k++)
            {
                p=p->down;
            }
            for(l=0;l<j;l++)
            {
                p=p->right;
            }
            if(j!=n-1 && i!=n-1)
            {
                q=(Node*)malloc(sizeof(Node));
                d=(Node*)malloc(sizeof(Node));
                p->right=q;
                p->down=d;
                p->data=mat[i][j];
                q=NULL;
                d=NULL;
            }
            if(j==n-1 && i==n-1)
            {
                p->data=mat[i][j];
                p->right=NULL;
                p->down=NULL;
            }
            if(i==n-1)
            {
                q=(Node*)malloc(sizeof(Node));
                p->right=q;
                p->down=NULL;
                p->data=mat[i][j];
                q=NULL;
            }
            if(j==n-1)
            {
                d=(Node*)malloc(sizeof(Node));
                p->right=NULL;
                p->down=d;
                p->data=mat[i][j];
                d=NULL;
            }
        }
    }
    return r;
}

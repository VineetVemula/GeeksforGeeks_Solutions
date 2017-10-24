Given a binary tree, your task is to complete the function verticalOrder which takes one argument the root of the binary tree and prints the node of the binary tree in vertical order .

          1
       /     \
     2       3
   /        /
4       5

The nodes of the above tree printed in vertical order will be
4
2
1 5
3
Your output should be 4 $2 $1 5 $3 $

Note: Each vertical line will be separated by a "$" without quotes.

Input:

The task is to complete the method which takes one argument, root of Binary Tree. There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should print nodes in vertical order where  each vertical line is separated by a "$" without quotes.

Constraints:
1 <=T<= 30
1 <= Number of nodes<= 20
 

Example:
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
3 $1 $2 $
40 $20 $10 60 $30 $


--code--

void merge(int arr[][2], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1][2], R[n2][2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
    {
        L[i][0] = arr[l + i][0];
        L[i][1] = arr[l + i][1];
    }
    for (j = 0; j < n2; j++)
    {
        R[j][0] = arr[m + 1+ j][0];
        R[j][1] = arr[m + 1+ j][1];
    }
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i][0] <= R[j][0])
        {
            arr[k][0] = L[i][0];
            arr[k][1] = L[i][1];
            i++;
        }
        else
        {
            arr[k][0] = R[j][0];
            arr[k][1] = R[j][1];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k][0] = L[i][0];
        arr[k][1] = L[i][1];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k][0] = R[j][0];
        arr[k][1] = R[j][1];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[][2], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}

void in(Node* x, int a[][2],int * m,int h)
{
    if(x!=NULL)
    {
        a[*m][0]=h;
        a[*m][1]=x->data;
        (*m)++;
        in(x->left,a,m,h-1);
        in(x->right,a,m,h+1);
    }
}
void verticalOrder(Node *root)
{
    int a[3000][2],i,j,temp,size=0,hi;
    if(root==NULL)
    {
        printf("$");
        return;
    }
    in(root,a,&size,0);
    
    /*for(i=0;i<1000;i++)
    {
        for(j=0;j<1000;j++)
        {
            if(a[j][0]>a[j+1][0])
            {
                temp=a[j][0];
                a[j][0]=a[j+1][0];
                a[j+1][0]=temp;
                temp=a[j][1];
                a[j][1]=a[j+1][1];
                a[j+1][1]=temp;
            }
        }
    }*/
    mergeSort(a,0,size-1);
    hi=a[0][0];
    for(i=0;i<size;i++)
    {
        if(hi!=a[i][0])
        {
            printf("$");
            hi=a[i][0];
        }
        printf("%d ",a[i][1]);
    }
    printf("$");
}

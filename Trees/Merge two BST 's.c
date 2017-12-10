Given two BST, Your task is to complete the function merge which  prints the elements of both BSTs in sorted form.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains three lines. The first line of each test case contain's an integer N and M denoting the size of the two BST's. Then In the next two line are space separated values of the two BST's.

Output:
The function should print the elements of both BST's in sorted form.

Constraints:
1<=T<=100
1<=N,M<=100

Example(To be used only for expected output):
Input:
2
3 3
1 33 4 
6 7 1
2 2
1 6
9 2
Output:
1 1 4 6 7 33
1 2 6 9

--code--

void in(Node* x,int arr[],int* n)
{
    if(x!=NULL)
    {
        in(x->left,arr,n);
        arr[(*n)++]=x->data;
        in(x->right,arr,n);
    }
}
void merge(Node *root1, Node *root2)
{
    int a[150],b[150],i=0,j=0;
    int n1=0,n2=0;
    in(root1,a,&n1);
    in(root2,b,&n2);
    while(i<n1 && j<n2)
    {
        if(a[i]<b[j])
        {
            printf("%d ",a[i++]);
        }
        else printf("%d ",b[j++]);
    }
    while(i<n1)
    {
        printf("%d ",a[i++]);
    }
    while(j<n2)
    {
        printf("%d ",b[j++]);
    }
}

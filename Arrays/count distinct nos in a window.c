Given an array A[] of size n and an integer k, your task is to complete the function countDistinct which prints the count of distinct numbers in all windows of size k in the array A[].

Example

Input:  A[] = {1, 2, 1, 3, 4, 2, 3};
            k = 4
Output:
3 4 4 3
Explanation:
First window is {1, 2, 1, 3}, count of distinct numbers is 3
Second window is {2, 1, 3, 4} count of distinct numbers is 4
Third window is {1, 3, 4, 2} count of distinct numbers is 4
Fourth window is {3, 4, 2, 3} count of distinct numbers is 3


Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two integers n and k. Then in the next line are N space separated values of the array A[].

Output:
For each test case in a new line print the space separated values denoting counts of distinct numbers in all windows of size k in the array A[].

Constraints:
1<=T<=100
1<=n,k<=100
1<=A[]<=100

Example(To be used only for expected output):
Input:
2
7 4
1 2 1 3 4 2 3
3 2
4 1 1
Output:
3 4 4 3
2 1

--CODE--

void countDistinct(int A[], int k, int n)
{
    int i,j,c=0;
    int a[99999];
    for(j=0;j<99999;j++)
        a[j]=0;
    if(n==0)
        return;
    if(k>n)
        k=n;
    for(j=0;j<k;j++)
    {
        if(a[A[j]]==0)
        {
            c++;
        }
        (a[A[j]])++;
    }
    printf("%d",c);
    for(i=k;i<n;i++)
    {
        (a[A[i-k]])--;
        if(a[A[i-k]]==0)
            c--;
        if(a[A[i]]==0)
        {
            c++;
        }
        (a[A[i]])++;
        printf(" %d",c);
    }
}

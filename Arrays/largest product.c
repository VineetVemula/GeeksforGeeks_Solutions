Given an array consisting of N positive integers, and an integer k .You have to find the maximum product of k contiguous elements in the array. Your task is to complete the function which takes three arguments .The first argument  is the array A[ ] and second argument is an integer N denoting the size of the array A[ ] and the third argument  is an integer k.The function will return and value denoting the largest product of sub-array of size k.

Input:
The first line of input is an integer T denoting the no of test cases. Then T test cases follow . The first line of each test case are two integer N and K separated by space .The next line contains N space separated values of the array A[ ].

Output:
Output of each test case will be an integer denoting the largest product of subarray of size k.

Constraints:
1<=T<=100
1<=N<=10
1<=K<=N
1<=A[]<=10

Example:
Input
1
4 2
1 2 3 4
Output
12 

--code--

long int findMaxProduct(int A[], int n, int k)
{
    long int m=1,max;
    int i,j;
    for(i=0;i<k;i++)
    {
        m=m*A[i];
    }
    max=m;
    for(j=0,i=k;i<n;i++,j++)
    {
        m=m/A[j]*A[i];
        if(max<m)
            max=m;
    }
    return max;
}

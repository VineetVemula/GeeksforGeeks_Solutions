Equilibrium index of an array is an index such that the sum of elements at lower indexes is equal to the sum of elements at higher indexes . Now Given an array your task is to complete the function findEquilibrium which returns the index of the first Equilibrium point in the array. The function takes  two arguments. The first argument is the array A[ ] and the second argument is the size of the array A.

Input:
The first line of input takes an integer T denoting the no of test cases, then T test cases follow. The first line of each test case is an integer N denoting The size of the array . Then in the next line are N space separated values of the array. 

Output:
For each test case output will be the equilibrium index of the array .If no such index exist output will be -1.

Constraints:
1<=T<=100
1<=N<=100
-100<=A[]<=100

Example(To be used only for expected output):
Input
2
4
1 2 0 3
4
1 1 1 1

Output
2
-1

--code--

#include<stdlib.h>
int findEquilibrium(int A[], int n)
{
    int i=0,j,left=0,right=0,ans=-1;
    int a[n];
    j=n-1;
    if(n==1)
        return 0;
    if(n==2 && A[1]==0)
        return 0;
    if(n==2 && A[0]==0)
        return 1;
    for(i=0;i<n;i++)
    {
        left=left+A[i];
        a[i]=left;
    }
    for(j=n-1;j>=0;j--)
    {
        right=right+A[j];
        if(right==a[j-2])
            ans=j-1;
    }
    return ans;
}

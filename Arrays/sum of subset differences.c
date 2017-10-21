Given an array S consisting of n numbers, find the sum of difference between last and first element of each subset.
For example for set 5,8 there are 3 subsets possible
5    (difference is 5-5 = 0 as 5 is the only last and first element)
8    (difference is 8-8 = 0 as 8 is the only last and first element)
5 8 (difference is 8-5 = 3 as 8 is the last element  and 5 is the first element)
thus difference sum is 0+0+3 = 3
You are required to complete the function which returns an integer denoting the sum of difference between last and first element for each subset of array S.

Note: Elements in the subset should be in the same order as in the set S.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains 2 lines the first line of input contains an integer N denoting the size of the array A. In the next line are N space separated values of the array A.

Output:
For each test case in a new line output will be the sum of difference between last and first element of each subset of array S.

Constraints:
1<=T<=100
1<=N<=20
1<=A[]<=1000

Example(To be used only for expected output) :
Input:
2
4
5 2 9 6
3
1 2 3 
Output
21
6

--code--

#include<math.h>
int sumDiff(int S[], int n)
{
    int i,j,temp,sum=0;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            sum=sum+pow(2,(j-i-1))*(S[j]-S[i]);
        }
    }
    return sum;
}

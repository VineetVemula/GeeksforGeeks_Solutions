Given an array A[ ] your task is to complete the function max_val which finds the maximum value of abs(i – j) * min(arr[i], arr[j]) where i and j vary from 0 to n-1. 

Input:
The first line of input contains an integer T denoting the no of test cases then T test cases follow. Each test case contains 2 lines. The First line of each test case contains an integer N denoting the size of the array. In the next line are N space separated values of the array A[ ] .

Output:
For each test case in a new line output will be the max values obtained.

Constraints:
1<=T<=100
1<=N<=100
-100<=A[]<=1000

Example(To be used only for expected output):
Input
2
4
3 2 1 4
4
8 1 9 4
Output
9 
16

Explanation:
(i) For the first test case a[0] = 3 and a[3] = 4 and thus result is  abs(0-3)*min(3,4) = 9.
(ii) For the second test ase a[0]=8 and a[2]=9 thus result is abs(0-2)*min(8,9) = 16. 

--code--

#include<stdlib.h>
int max_val(int arr[], int n)
{
    int i,j,m=0,max=0;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            m=(j-i)*min(arr[i],arr[j]);
            if(m>max)
                max=m;
        }
    }
    return max;
}

Given two arrays, the task is to complete the function max_path_sum that takes 4 argument The first two arguments represent the 2 arrays A[], B[] and the last two arguments l1, l2 denote the size of array A and B respectively. The function returns the sum of the maximum sum path to reach from beginning of any array to end of any of the two arrays .

Note: You can switch from one array to another array only at common elements.

eg
A [ ] = {2,3,7,10,12}
B [ ] = {1 5 7 8}

Here We start from first element of B which is 1, then we move to 5, then 7. From 7, we switch to A (7 is common) and traverse 10 and 12.

Thus The result will be 1+5+7+10+12 =35

Input:
The first line of input contains an integer T denoting the no of test cases . Then T cases follow.
Each test case contains 3 lines. The first line contains two space separated integers l1 and l2 denoting the length of the two sorted array A and B. In the second line is the space separated values of array A and in the third line are space separated values of array B.

Output:
For each test case the output is the max sum obtained in such fashion .

Constraints:
1<=T<=100
1<=N,M<=100
1<=A[],B[]<=1000

Example:
2
5 4
2 3 7 10 12
1 5 7 8 
3 3
1 2 4
1 2 7

Output
35 
10

Explanation
1. For first test case the path will be 1+5+7+10+12 = 35 
2. For second test case the path will be 1+2 +7=10

--CODE--

 int max_path_sum(int A[], int B[], int l1, int l2)
{
    int i=0,j=0,m=0,n=0,max=0;
    while(i<l1 && j<l2)
    {
        if(A[i]<B[j])
        {
            m=m+A[i];
            i++;
            continue;
        }
        if(B[j]<A[i])
        {
            n=n+B[j];
            j++;
            continue;
        }
        if(A[i]==B[j])
        {
            m=m+A[i];
            i++;
            n=n+B[j];
            j++;
            if(m>n)
            {
                max=max+m;
            }
            else
            {
                max=max+n;
            }
            m=n=0;
        }
    }
    while(i<l1)
    {
        m=m+A[i];
        i++;
    }
    while(j<l2)
    {
        n=n+B[j];
        j++;
    }
    if(m>n)
        max=m+max;
    else max=n+max;
    return max;
}

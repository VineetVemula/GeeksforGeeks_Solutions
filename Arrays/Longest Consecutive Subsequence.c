Given an array of integers A[], the task is to complete the function which returns an integer denoting the length of the longest sub-sequence such that elements in the sub-sequence are consecutive integers, the consecutive numbers can be in any order. 

Examples

Input: A[] = {1, 9, 3, 10, 4, 20, 2};
Output: 4
The subsequence 1, 3, 4, 2 is the longest subsequence
of consecutive elements

Input: A[] = {36, 41, 56, 35, 44, 33, 34, 92, 43, 32, 42}
Output: 5
The subsequence 36, 35, 33, 34, 32 is the longest subsequence
of consecutive elements. 
Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer N. Then in the next line are N space separated values of the array A[].

Output:
For each test case in a new line output will be the length of the longest consecutive increasing sub-sequence present in the array A[ ] .

Constraints:
1<=T<=100
1<=N<=100

Example(To be used only for expected output):
Input:
2
7
1 9 3 10 4 20 2
11
36 41 56 35 44 33 34 92 43 32 42
Output:
4
5

--code--

int findLongestConseqSubseq(int arr[], int n)
{
    int i,j,temp,c=1,max=1;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(i=0;i<n-1;i++)
    {
        if(arr[i+1]==arr[i])
            continue;
        if((arr[i]+1)==arr[i+1])
        {
            c++;
            if(max<c)
                max=c;
        }
        else
        {
            c=1;
        }
    }
    return max;
}

Given an array of 0's and 1's your task is to complete the function maxLen which returns  size of  the  largest sub array with equal number of 0's and 1's .
The function maxLen takes 2 arguments .The first argument is the array A[] and second argument is the size 'N' of the array A[] .

Input:
The first line of the input is T denoting the number of test cases .
Then T test cases follow . Each test case contains two lines . 
The first line of each test case is a number N denoting the size of the array and in the next line are N space separated values of A [ ].

Output:
For each test case output in a new line the max length of the subarray .

Constraints:
1<=T<=100
1<=N<=100
0<=A[ ] <=1

Example:
Input (To be used only for expected output) :
2
4
0 1 0 1
5
0 0 1 0 0 

Output
4
2

--CODE--

int maxLen(int arr[], int n)
{
    int i,j,c=0,max=0,m;
    for(i=0;i<n;i++)
    {
        c=0;
        for(j=i;j<n;j++)
        {
            if(arr[j]==0)
                c++;
            else c--;
            if(c==0)
            {
                m=j-i+1;
                if(m>max)
                    max=m;
            }
        }
    }
    return max;
}

Given an array A[], of 'n' elements. Your task is to complete the function minDist which returns  an integer denoting the minimum distance between two integers x and y in the array. If no such distance is possible then return -1.
 

Input:
The first line of input contains an integer T, denoting the no of test cases. Then T test cases follow. Each test case consists of three lines. The first line of each test case contains an integer 'n' denoting size array. Then in the next line are 'n' space separated values of the array A[]. The last line of each test case contains two integers  x and y.

Output:
For each test case in a new line print the required answer .

Constraints:
1<=T<=100
1 <=n<= 100
1 <=A[], x, y<= 100

Example(To be used only for expected output):
Input:
2
2
1 2
1 2
7
86 39 90 67 84 66 62 
42 12
Output:
1
-1

--code--

int minDist(int arr[], int n, int x, int y)
{  
    int i,min=n,m,j;
    for(i=0;i<n-1;i++)
    {
        if(arr[i]==x)
        {
            for(j=i+1;j<n;j++)
            {
                if(arr[j]==y)
                {
                    m=j-i;
                    if(min>m)
                    {
                       min=m; 
                    }
                    break;
                }
            }
        }
        if(arr[i]==y)
        {
            for(j=i+1;j<n;j++)
            {
                if(arr[j]==x)
                {
                    m=j-i;
                    if(min>m)
                    {
                        min=m;
                    }
                    break;
                }
            }
        }
    }
    if(min==n)
        return -1;
    return min;
}

Given a Integer array A[] of n elements. Your task is to complete the function PalinArray. Which will return 1 if all the elements of the Array are palindrome otherwise it will return 0.

Input:
The first line of input contains an integer denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line of input contains an integer n denoting the size of the arrays. In the second line are N space separated values of the array A[].

Output:
For each test case in a new line print the required result.

Constraints:
1<=T<=50
1<=n<=20
1<=A[]<=10000

Example:
Input:
2
5
111 222 333 444 555
3
121 131 20

Output:
1
0

--code--

int PalinArray(int a[], int n)
{  
    int i,d,m;
    for(i=0;i<n;i++)
    {
        m=a[i];
        d=0;
        while(m>0)
        {
            d=d*10+m%10;
            m=m/10;
        }
        if(d!=a[i])
            return 0;
    }
    return 1;
}

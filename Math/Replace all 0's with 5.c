Given a number your task is to complete the function convertFive which takes an integer n as argument and replaces all zeros in the number n with 5 .Your function should return the converted number .

Input:
The first line of input contains an integer T denoting the number of test cases . Then T test cases follow . Each test case contains a single integer n denoting the number.

Output:
The output of the function will be an integer where all zero's are converted to 5 .

Constraints:
1<=T<100
1<=n<=10000

Example:
Input
2
1004
121

Ouput
1554
121

--CODE--

int convertFive(int n)
{
    int e=n,d=0,t,c=0,i=0;
    while(e!=0)
    {
        t=e%10;
        if(t==0)
        {
            d=d+5*(pow(10,i));
        }
        i++;
        e=e/10;
    }
    return(n+d);
}

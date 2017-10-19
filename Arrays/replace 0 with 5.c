Given a number your task is to complete the function convertFive which replace all zeros in the number with 5 and returns the number.

Input:
The first line of input contains an integer T denoting the number of test cases . Then T test cases follow . Each test case contains a single integer N denoting the number.

Output:
The output of the function will be an integer where all zero's are converted to 5 .

Constraints:
1<=T<100
1<=N<=10000

Example:
Input
2
1004
121

Ouput
1554
121

--code--

#include<math.h>
int convertFive(int n)
{
    int d,k,i=0;
    while(n>0)
    {
        d=n%10;
        n=n/10;
        if(d==0)
        {
            k=5*pow(10,i)+k;
        }
        else k=d*pow(10,i)+k;
        i++;
    }
}

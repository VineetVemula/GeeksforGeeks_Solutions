Given an array A[] of n numbers and another number x, determine whether or not there exist two elements in A whose sum is exactly x.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N and X,N is the size of array.
The second line of each test case contains N integers representing array elements C[i].

Output:

Print "Yes" if there exist two elements in A whose sum is exactly x, else "No" without quotes.

Constraints:

1 ≤ T ≤ 200
1 ≤ N ≤ 200
1 ≤ C[i] ≤ 1000

Example:

Input:
2
6 16
1 4 45 6 10 8
5 10
1 2 4 3 6

Output:
Yes
Yes

--CODE--

#include <stdio.h>

int main() 
{
	int c[200],n,t,s,i,j;
	scanf("%d",&t);
	while(t--)
	{
	 scanf("%d %d",&n,&s);
	 for(j=0;j<n;j++)
	     {
	         scanf("%d",&c[j]);
	     }
	 for(i=0;i<n-1;i++)
	 {
	     for(j=i+1;j<n;j++)
	     {
	         if((c[i]+c[j])==s)
	         {
	            printf("Yes\n");
	            goto a;
	         }
	     }
	 }
	 printf("No\n");
	 a:;
	}
	
	return 0;
}

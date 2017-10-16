You are given an Array. Your task is to complete the function getSum to return the sum of the given range a and b.

Input:
First line consists of T test cases. First line of every test case consists of 3 integers n,a and b ,denoting number of elements, lower range and higher range respectively. Second line consists of elements of array.

Output:
Return the sum value .

Constraints:
1<=T<=100
1<=N<=100
0<=a,b

Example:
Input:
1
6 1 3
1 3 5 7 9 11
Output:
15

--CODE--

int getSum(int arr[],int n,int a,int b)
{
 int sum=0,i;
 for(i=a;i<=b;i++)
 {
    sum=sum+arr[i]; 
 }
 return sum;
}

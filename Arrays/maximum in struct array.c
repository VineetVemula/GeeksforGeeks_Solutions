Given a struct array of type Height, having two elements feet and inches, your task is to complete the function findMax(), that must return the maximum height from the array in terms of inches.

Input:
The function takes two argument as input, the array of structure and an integer variable denoting the size of the array.
There will be T, test cases and for each test case the function will be called separately.

Output:
The function should return the maximum height from the array.

Constraints:
1<=T<=100
1<=N<=105
0<=Feet, Inches<=105

Example:
Input:
2
2
1 2 2 1
4
3 5 7 9 5 6 5 5
Output:
25
93

--CODE--

int findMax(Height arr[], int n)
{
    int i,res=0,cal;
    for(i=0;i<n;i++)
    {
        cal=arr[i].feet*12 +arr[i].inches;
        if(cal>res)
            res=cal;
    }
    return res;
}

Given K sorted arrays arranged in a form of a matrix, your task is to merge them. You need to complete mergeKArrays function which takes 2 arguments, an arr[k][k] 2D Matrix containing k sorted arrays and an integer k denoting the no. of sorted arrays. The function should return a pointer to the merged sorted arrays. There are multiple test cases. For each test case, this method will be called individually. 

Input:
The first line of input will denote the no of Test cases then T test cases will follow . Each test cases will contain an integer N denoting the no of sorted arrays. Then in the next line contains all the elements of the array separated by space.

Output:
The output will be the sorted merged array.

Constraints
1<=T<=50
1<=N<=10

Example:

Input
1
3

1 2 3 4 5 6 7 8 9 

Output:
1 2 3 4 5 6 7 8 9

Explanation 
above test case has 3 sorted arrays of size 3, 3, 3
arr[][] = [[1, 2, 3],

             [4, 5, 6],

             [7, 8, 9]]
The merged list will be [1, 2, 3, 4, 5, 6, 7, 8, 9]

--CODE--

int res[99999];
int *mergeKArrays(int arr[][N], int k)
{
    int i,j,min,no,a[k],p=0;
    int m=k*k;
    for(i=0;i<k;i++)
    {
       a[i]=0; 
    }
    for(i=0;i<m;i++)
    {
        min=9999;
        no=0;
        for(j=0;j<k;j++)
        {
           if(min>arr[j][a[j]] && a[j]!=k)
           {
               min=arr[j][a[j]];
               no=j;
           }
        }
        
        a[no]=a[no]+1;
        res[p++]=min;
    }
    return res;
    
}

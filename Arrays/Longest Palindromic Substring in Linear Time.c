Given a string, find the longest substring which is palindrome in Linear time O(N).
Input:

The first line of input contains an integer T denoting the no of test cases . Then T test cases follow. The only line of each test case contains a string.
Output:

For each test case print the Longest Palindromic Substring.

Constraints:
1<=T<=100
1<=N<=50
Example:

Input:

2
babcbabcbaccba
forgeeksskeegfor

Output:
abcbabcba
geeksskeeg

--code--

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


// your task is to complete this function
#include<stdlib.h>
#include<string.h>
void findLongestPalindromicString(char text[])
{
    int size,n,i,j,l,r,c=0,max=0,max1=0,pos1=99999,pos2=9999,p1,p2,ans=-1,k,h,pos1i=-1,pos2i=-1;
    size=strlen(text);
    n=size;

    char inverse[size];
    for(i=size-1,j=0;i>=0;i--,j++)
    {
        inverse[i]=text[j];
    }
    r=size-1;
    p1=0;
    while(r>=0)
    {
    p1=0;
    for(i=0,j=size-1-r;i<=r,j<size;j++,i++)
    {
        if(text[i]==inverse[j])
        {
            c++;
            p2=i;
            continue;
        }
        if(max<=c)
        {
            if(max==c)
            {
                if(pos1<p1)
                {
                    goto uuu;
                }
            }
            for(k=p1,h=size-1-p2;k<=p2;k++,h++)
            {
                if(text[k]!=inverse[h])
                    goto uuu;
            }
            max=c;
            pos1=p1;
            pos2=p2;
            ans=1;
        }
        uuu:;
        p1=i+1;
        c=0;
    }
    if(max<=c)
    {
        if(max==c)
        {
            if(pos1<p1)
            {
                goto b;
            }
        }
        for(k=p1,h=size-1-p2;k<=p2;k++,h++)
        {
            if(text[k]!=inverse[h])
                goto b;
        }
        max=c;
        pos1=p1;
        pos2=p2;
        ans=1;
    }
    b:;
    c=0;
    r--;
    }
    
    p1=0;
    r=size-1;
    c=0;
    max1=max;
    while(r>=0)
    {
    p1=0;
    for(i=0,j=size-1-r;i<=r,j<size;j++,i++)
    {
        if(inverse[i]==text[j])
        {
            c++;
            p2=i;
            continue;
        }
        if(max<=c && c>max1)
        {
            if(max==c)
            {
                if(pos1i>p1)
                {
                    goto a;
                }
            }
            for(k=p1,h=size-1-p2;k<=p2;k++,h++)
            {
                if(inverse[k]!=text[h])
                    goto a;
            }
            max=c;
            pos1i=p1;
            pos2i=p2;
            ans=0;
        }
        a:;
        p1=i+1;
        c=0;
    }
    if(max<=c && c>max1)
    {
        if(max==c)
        {
            if(pos1i>p1)
            {
                goto d;
            }
        }
        for(k=p1,h=size-1-p2;k<=p2;k++,h++)
        {
            if(inverse[k]!=text[h])
                goto d;
        }
        max=c;
        pos1i=p1;
        pos2i=p2;
        ans=0;
    }
    d:;
    c=0;
    r--;
    }

    if(max==1)
    {
        printf("%c",text[1]);
        printf("\n");
        return;
    }
    if(ans==1)
    {
        for(i=pos1;i<=pos2;i++)
        {
            printf("%c",text[i]);
        }
        printf("\n");
    }
    else if(ans==0)
    {
        for(i=pos1i;i<=pos2i;i++)
        {
            printf("%c",inverse[i]);
        }
        printf("\n");
    }
}

ALTERNATE SIMPLE SOLUTION

void findLongestPalindromicString(char text[])
{
    // code here
    int len = strlen(text);
    int max = 1;
    int left = 1, right = 1;
    for (int i = 0; i < len; i++)
    {
        int l = i, r = i;
        while (l >= 0 && r < len)
        {
            if (text[l] != text[r])
            {
                break;
            }
            else
            {
                int curLength = r - l + 1;
                if (curLength > max)
                {
                    max = curLength;
                    right = r;
                    left = l;
                }
            }
            
            l--;
            r++;
        }
        
        l = i;
        r = i + 1;
        while (l >= 0 && r < len)
        {
            if (text[l] != text[r])
            {
                break;
            }
            else
            {
                int curLength = r - l + 1;
                if (curLength > max)
                {
                    max = curLength;
                    right = r;
                    left = l;
                }
            }
            
            l--;
            r++;
        }
        
        
    }
    
    for (int i = left; i <= right; i++)
    {
        cout << text[i];
    }
    
    cout << endl;
}

Given a singly linked list of integers, Your task is to complete the function isPalindrome that returns true if the given list is palindrome, else returns false.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T testcases follow. Each test case contains 2 line the first line of each test case contains an integer N denoting the size of the linked list. The next line contains N space separated integers denoting the values of the nodes of the linked list.

Output:
For each test case output will be 1 if the linked list is a palindrome else 0.

Constraints:
1<=T<=1000
1<=N<=50

Example(To be used only for expected output):
Input
2
3
1 2 1
4
1 2 3 4

Output:
1
0

--CODE--

bool isPalindrome(Node *head)
{
    struct Node* f,*last;
    int data,i=0,c=0,m,j;
    last=head;
    f=head;
    if(head==NULL)
        return 0;
    while(last!=NULL)
    {
        last=last->next;
        c++;   
    }
    last=head;
    do
    {
        m=c-i;
        last=head;
        for(j=1;j<m;j++)
        {
            last=last->next;
        }
        if(f->data!=last->data)
            return 0;
        f=f->next;
        i++;
    }while(last->next!=f && f!=last);
    return 1;
}

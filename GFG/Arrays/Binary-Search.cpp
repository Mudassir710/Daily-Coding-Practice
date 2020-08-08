/*
Mohammed Mudassir Mohiuddin
Binary Search 
Given a sorted array of integers and a key to be searched in the array. Print the position of the key in the array, if present. If it's not present in the array, report it. 

Input:
The first line contains an integer 'T' denoting the number of test cases. Then 'T' test cases follow. Each test case consists of 3 lines. First line of each test case contains an integer N denoting the size of the array. Second line of each test case consists of 'N' space separated integers denoting the elements of the array A[]. The third line contains a key 'k' .

Output:
Prints the position of the key if its present in the array else print -1 if the key is not present in the array.

User Task:
You don't need to read input or print anything. Your task is to complete the function bin_search() which takes the array A[], key k and the leftmost and the rightmost index in the array (left and right respectively) and returns the position where the key k occurs in the array. If it's not present, return -1.

Expected Time Complexity: O(LogN)
Expected Auxiliary Space: O(LogN) if solving recursively and O(1) otherwise.

Constraints:
1 <= T <= 100
1 <= N <= 104
1 <= arr[i] <= 104
*/


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int bin_search(int A[],int left,int right,int k);

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int N;
        cin>>N;
        int a[N];
        for(int i=0;i<N;i++)
            cin>>a[i];
        int key;
        cin>>key;
        int found = bin_search(a,0,N-1,key);
        cout<<found<<endl;
    }
}
// } Driver Code Ends


/*You need to complete this function */
int bin_search(int A[], int left, int right, int k)
{
    if(right >= left)
    {
        int mid = left + (right - left)/2;
        if(A[mid] == k) return mid;
        else if(A[mid] < k) return bin_search(A,mid + 1,right,k);
        else return bin_search(A,left,mid - 1,k);
    }
    return -1;
}
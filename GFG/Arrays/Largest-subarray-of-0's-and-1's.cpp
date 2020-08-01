/*
Mohammed Mudassir Mohiuddin
Given an array of 0s and 1s. Find the length of the largest subarray with equal number of 0s and 1s.
*/


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int maxLen(int arr[], int n);

int main()
{
    // your code goes here
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << maxLen(a, n) << endl;
    }
    return 0;
}// } Driver Code Ends


/*You are required to complete this method*/

// arr[] : the input array containing 0s and 1s
// N : size of the input array

// return the maximum length of the subarray
// with equal 0s and 1s
int max(int a, int b) { return a > b ? a : b; }
int maxLen(int arr[], int N)
{
    int sum =0;
    int max_len = 0;
    unordered_map<int,int> map;
    //map[0] = -1;
    for(int i=0; i<N; ++i)
    {
        sum += (arr[i] == 0) ? -1 : 1;
        //cout<<"sum "<<sum<<"\n";
        if(map.find(sum) != map.end())
        {
            max_len = max(max_len, i - map[sum]);
        }
        else
        {
            map[sum] = i;
        }
    }
    return max_len;
}

//-001 0
//0 1


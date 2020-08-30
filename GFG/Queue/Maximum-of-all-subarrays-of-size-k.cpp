/*Mohammed Mudassir Mohiuddin*/ 
/*
Given an array A and an integer K. Find the maximum for each and every contiguous subarray of size K.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case contains a single integer N denoting the size of array and the size of subarray K. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print the maximum for every subarray of size k.

Constraints:
1 ≤ T ≤ 200
1 ≤ N ≤ 107
1 ≤ K ≤ N
0 ≤ A[i] <= 107

Example:
Input:
2
9 3
1 2 3 1 4 5 2 3 6
10 4
8 5 10 7 9 4 15 12 90 13

Output:
3 3 4 5 5 5 6
10 10 10 15 15 90 90

Explanation:
Testcase 1: Starting from first subarray of size k = 3, we have 3 as maximum. Moving the window forward, maximum element are as 3, 4, 5, 5, 5 and 6.
*/ 


#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int inpSize,WindowSize;
	cin>>inpSize>>WindowSize;
	int arr[inpSize];
	for(int i=0;i<inpSize;i++)
	  cin>>arr[i];
	priority_queue <int> pq; 
	unordered_map<int, int> map;
	for(int i=0;i<WindowSize;i++)
	{
	    pq.push(arr[i]);
	    if(map.find(arr[i]) == map.end())
	        map[arr[i]] = 1;
	    else map[arr[i]]++;
	}
	int start =  0;
	for(int i=WindowSize;i<inpSize;i++)
	{
	    if(!pq.empty()) cout<<pq.top()<<" ";
	    map[arr[start++]]--;
	    if(map.find(arr[i]) == map.end())
	        map[arr[i]] = 1;
	    else map[arr[i]]++;
	    pq.push(arr[i]);
	    while(!pq.empty() && !map[pq.top()])
	        pq.pop();
	}
	cout<<pq.top();
}
int main()
 {
	int tests;
	cin>>tests;
	while(tests--)
	{
	    solve();
	    cout<<"\n";
	}
	return 0;
}
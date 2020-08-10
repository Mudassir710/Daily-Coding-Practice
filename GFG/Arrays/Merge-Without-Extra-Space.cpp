/*
Mohammed Mudassir Mohiuddin 
Given two sorted arrays arr1[] and arr2[] in non-decreasing order with size n and m. The task is to merge the two sorted arrays into one sorted array (in non-decreasing order).

Note: Expected time complexity is O((n+m) log(n+m)). DO NOT use extra space.  We need to modify existing arrays as following.

Input: arr1[] = {10};
       arr2[] = {2, 3};
Output: arr1[] = {2}
        arr2[] = {3, 10}  

Input: arr1[] = {1, 5, 9, 10, 15, 20};
       arr2[] = {2, 3, 8, 13};
Output: arr1[] = {1, 2, 3, 5, 8, 9}
        arr2[] = {10, 13, 15, 20} 
Input:
First line contains an integer T, denoting the number of test cases. First line of each test case contains two space separated integers X and Y, denoting the size of the two sorted arrays. Second line of each test case contains X space separated integers, denoting the first sorted array P. Third line of each test case contains Y space separated integers, denoting the second array Q.

Output:
For each test case, print (X + Y) space separated integer representing the merged array.

Constraints:
1 <= T <= 100
1 <= X, Y <= 5*104
0 <= arr1i, arr2i <= 109
*/


#include<bits/stdc++.h>
using namespace std;
void solve()
{   
    int n,m;
	cin>>n>>m;
	int arrn[n], arrm[m];
	for(int i=0;i<n;i++)
	  cin>>arrn[i];
	for(int i=0;i<m;i++)
	  cin>>arrm[i];
	int i=0,j=0;  
	while(i<n && j<m)
	    (arrn[i] > arrm[j])? (cout<<arrm[j++]<<" ") : (cout<<arrn[i++]<<" ");
	//cout<<"\n"<<i<<" "<<j<<"\n";
	while(i < n)
	    cout<<arrn[i++]<<" ";
	while(j < m)
	    cout<<arrm[j++]<<" ";    
    cout<<"\n";
}
int main()
 {
	int tests;
	cin>>tests;
	while(tests--)
	{
	    solve();
	}
	return 0;
}
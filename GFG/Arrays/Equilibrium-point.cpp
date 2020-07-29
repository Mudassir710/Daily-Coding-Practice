/*
Mohammed Mudassir Mohiuddin
Given an array A of N positive numbers. The task is to find the position where equilibrium first occurs in the array. Equilibrium position in an array is a position such that the sum of elements before it is equal to the sum of elements after it.

Input:
The first line of input contains an integer T, denoting the number of test cases. Then T test cases follow. First line of each test case contains an integer N denoting the size of the array. Then in the next line are N space separated values of the array A.

Output:
For each test case in a new  line print the position at which the elements are at equilibrium if no equilibrium point exists print -1.

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= Ai <= 108

Example:
Input:
2
1
1
5
1 3 5 2 2

Output:
1
3
*/

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int tests;
	
	cin>>tests;
	while(tests--)
	{
	    long num,sum=0;
	    cin>>num;
	    long arr[num];
	    for(int i=0;i<num;i++)
	    {
	        cin>>arr[i];
	        sum+=arr[i];
	    }
	    long leftarr[num] = {0};
	    for(int i=1; i<num; ++i)
	    {
	        leftarr[i] = arr[i-1] + leftarr[i-1];
	    }
	    bool flag = 1;
	    for(int i=0; i<num; ++i)
	    {
	        if(leftarr[i] == sum-arr[i]-leftarr[i])
	        {
	            flag = 0;
	            cout<<i+1<<"\n";
	            break;
	        }
	    }
	    if(flag) cout<<"-1\n";
	}
	return 0;
}
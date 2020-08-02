/*
Mohammed Mudassir Mohiuddin
Given an array arr of N integers. Find the contiguous sub-array with maximum sum.
*/
#include<bits/stdc++.h>
using namespace std;
long long max(long long a, long long b){ return (a>b)? a : b;}
int main()
 {
	int tests;
	cin>>tests;
	while(tests--)
	{
	    int num;
	    cin>>num;
	    int arr[num];
	    for(int i=0;i<num;i++)
	        cin>>arr[i];
	    long long current_sum = 0, best_sum = INT_MIN;
	    for(int i=0; i<num; ++i)
	    {
	         current_sum = max(arr[i], current_sum + arr[i]);
             best_sum    = max(current_sum, best_sum);
             //cout<<current_sum<<" "<<best_sum<<"\n";
	    }     
	    cout<<best_sum<<"\n";
	}
	return 0;
}

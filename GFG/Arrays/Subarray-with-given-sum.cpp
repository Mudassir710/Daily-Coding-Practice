/*
Mohammed Mudassir Mohiuddin
Given an unsorted array A of size N of non-negative integers, find a continuous sub-array which adds to a given number S.
*/

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int tests;
	cin>>tests;
	while(tests--)
	{
	    int num,i;
	    long long curr_sum=0, tar_sum;
	    cin>>num>>tar_sum;
	    int arr[num];
	    for(i=0;i<num;i++)
	        cin>>arr[i];
	    int start =0;
	    bool flag = 1;
	    curr_sum = arr[0];
	    for(int i=1; i<=num; ++i)
	    {
	        //cout<<curr_sum <<" " << i;
	        while(curr_sum > tar_sum && start < num) 
	            curr_sum -= arr[start++];
	        if(curr_sum == tar_sum)
	        {
	            flag =0;
	            cout<<start+1<<" "<<i<<"\n";
	            break;
	        }
	        if(i < num) curr_sum+=arr[i];
	    }
	    if(flag) cout<<"-1\n";
	}
	return 0;
}